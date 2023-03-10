#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
  int n = stoi(argv[2]); // triangulation number

  string mesh = "Freefem++ ./utils/mesh.edp -n " + to_string(n); // init mesh command
  string randmesh = "Freefem++ ./utils/randmesh.edp -s 1"; // init mesh command
  string solve = "FreeFem++ ./utils/solver.edp -r 1 -p 1 -s 1"; // solve problem command

  system(mesh.c_str()); // creating new mesh
  system(randmesh.c_str()); // mesh mapping
  system(solve.c_str()); // solve problem

  return 0;
}
