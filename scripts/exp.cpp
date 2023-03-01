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

    if(rank==0){
        string mesh = "Freefem++ -nw ./utils/mesh.edp -n " + to_string(n); // init mesh command
        system(mesh.c_str()); // creating new mesh

        done = 1; // initialization done
    }

    /*
    MPI_Bcast(&done, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if(done==1){
        string randmesh = "Freefem++ -nw ./utils/randmesh.edp -s "; // init mesh command
        string solve = "FreeFem++ -nw ./utils/solver.edp -r 1 -p 0 -s "; // solve problem command

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
            string exp = "FreeFem++ -nw ./utils/exp.edp -m " + to_string(m); // init mesh command
            system(exp.c_str()); // calculate expectation 
        }
    }
    */

    MPI_Finalize();
}
