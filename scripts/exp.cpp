#include <iostream>
#include <cstring>
#include <fstream>
#include <mpi.h>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank;
    int size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int n = stoi(argv[2]);
    int t = stoi(argv[4]);
    int l = stoi(argv[6]);

    string file;
    if(t==2) file = "./utils/points/SG-GL_weights_l";
    else file = "./utils/points/uniform_weights_l";
    file = file + to_string(l) + ".txt"; 

    int m = 0;
    ifstream in(file);
    string unused;
    while (getline(in, unused)) m++;

    int done = 0;

    if(rank==0){
        string mesh = "FreeFem++ -nw -ne ./utils/mesh.edp -n " + to_string(n); // init mesh command
        string eig = "FreeFem++ -nw -ne ./utils/eig.edp"; // init eig command

       // system(mesh.c_str()); // creating new mesh
       // system(eig.c_str()); // calculating eigenvalues of map

        done = 1;
    }

    MPI_Bcast(&done, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if(done){
        string randmesh = "FreeFem++ -nw -ne ./utils/randmesh.edp";
        randmesh = randmesh + " -t " + to_string(t);
        randmesh = randmesh + " -l " + to_string(l); 
        randmesh = randmesh + " -m " + to_string(m); 
        randmesh = randmesh + " -s ";

        string solve = "FreeFem++ -nw -ne ./utils/solver.edp -r 1 -p 0 -s "; // solve problem command

        string samplemesh;
        string samplesolve;

        int upplim = m*rank/size+1;
        int lowlim = m*(rank+1)/size+1;

        for(int i=upplim;i<lowlim;i++){
            samplemesh = randmesh + to_string(i);
            samplesolve = solve + to_string(i);

            system(samplemesh.c_str()); // mesh mapping for sample
            system(samplesolve.c_str()); // solve problem for sample 
        }

        MPI_Barrier(MPI_COMM_WORLD);

        if(rank==0){
            string exp = "FreeFem++ -nw -ne ./utils/exp.edp";
            exp = exp + " -t " + to_string(t);
            exp = exp + " -l " + to_string(l);
            exp = exp + " -m " + to_string(m);

            system(exp.c_str()); 
        }
    }

    MPI_Finalize();
}
