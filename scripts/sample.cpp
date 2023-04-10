#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
  int n = stoi(argv[2]); // triangulation number
  int s = stoi(argv[4]); // sample number

  string mesh = "Freefem++ -nw ./utils/mesh.edp -n " + to_string(n); // init mesh command
  string eig = "Freefem++ -nw ./utils/eig.edp"; // init eig command
  string randmesh = "Freefem++ -nw ./utils/randmesh.edp -h 0 -s " + to_string(s); // init randmesh command
  string solve = "FreeFem++ ./utils/solver.edp -r 1 -p 1 -s " + to_string(s); // init solve command

  system(mesh.c_str()); // creating new mesh
  system(eig.c_str()); // calculating eigenvalues of map
  system(randmesh.c_str()); // mesh mapping
  system(solve.c_str()); // solve problem

  return 0;
}
