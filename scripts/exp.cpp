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

    FILE *fp;
    char c;

    int m = 0;

    int n = stoi(argv[2]);
    string points = argv[4];
    string weights = argv[6];

    points = "./utils/points/" + points;
    weights = "./utils/points/" + weights;

    if(rank==0){
        fp = fopen(points.c_str(), "r");
        for (c = getc(fp); c != EOF; c = getc(fp)) if (c == '\n') m+=1;

        string mesh = "FreeFem++ -nw -ne ./utils/mesh.edp -n " + to_string(n); // init mesh command
        system(mesh.c_str()); // creating new mesh

        string eig = "FreeFem++ -nw -ne ./utils/eig.edp"; // init eig command
        system(eig.c_str()); // calculating eigenvalues of map
    }

    MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if(m){
        string randmesh = "FreeFem++ -nw -ne ./utils/randmesh.edp";
        randmesh = randmesh + " -np " + to_string(m);
        randmesh = randmesh + " -p " + points; 
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
            string exp = "FreeFem++ -nw -ne ./utils/exp.edp -m " + to_string(m);
            exp = exp + " -w " + weights;
            system(exp.c_str()); 
        }
    }

    MPI_Finalize();
}
