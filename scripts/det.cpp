#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
  int n = stoi(argv[2]); // triangulation number

  string mesh = "Freefem++ ./utils/mesh.edp -n " + to_string(n); // init mesh command
  string solve = "FreeFem++ ./utils/solver.edp"; // solve problem command
  
  system(mesh.c_str()); // creating new mesh
  system(solve.c_str()); // solve problem

  return 0;
}
