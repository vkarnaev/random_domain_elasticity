#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
  int n;
  int s;

  try {
    n = stoi(argv[2]);
    s = stoi(argv[4]);
  }
  catch(...) {
    n = 8;
    s = 1;
  }

  string mesh = "Freefem++ -ne -nw ./utils/mesh.edp -n " + to_string(n); // init mesh command
  string eig = "Freefem++ -ne -nw ./utils/eig.edp"; // init eig command
  string randmesh = "Freefem++ -ne ./utils/randmesh.edp -t 0 -l 1 -s " + to_string(s); // init randmesh command
  string solve = "FreeFem++ -ne ./utils/solver.edp -r 1 -p 1 -s " + to_string(s); // init solve command

  system(mesh.c_str()); // creating mesh
  system(eig.c_str()); // calculating eigenvalues of map
  system(randmesh.c_str()); // mesh mapping
  system(solve.c_str()); // solve problem

  return 0;
}
