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

    int done = 0;

    int n = stoi(argv[2]);
    int m = stoi(argv[4]);
    int h = stoi(argv[6]);

    if(rank==0){
        string mesh = "FreeFem++ -nw -ne ./utils/mesh.edp -n " + to_string(n); // init mesh command
        system(mesh.c_str()); // creating new mesh

        string eig = "FreeFem++ -nw -ne ./utils/eig.edp"; // init eig command
        system(eig.c_str()); // calculating eigenvalues of map

        done = 1; // initialization done
    }

    MPI_Bcast(&done, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if(done==1){
        string randmesh = "FreeFem++ -nw -ne ./utils/randmesh.edp -h "; // init mesh command
        randmesh = randmesh + to_string(h);
        randmesh = randmesh + " -s ";
        string solve = "FreeFem++ -nw -ne ./utils/solver.edp -r 1 -p 0 -s "; // solve problem command

        string samplemesh;
        string samplesolve;

        int upplim = m*rank/size+1;
        int lowlim = m*(rank+1)/size+1;

        for(int i=upplim;i<lowlim;i++){
            samplemesh = randmesh + to_string(i);
            samplesolve = solve + to_string(i);

            cout << samplemesh << endl;

            system(samplemesh.c_str()); // mesh mapping for sample
            system(samplesolve.c_str()); // solve problem for sample 
        }
    }

    MPI_Finalize();
}
