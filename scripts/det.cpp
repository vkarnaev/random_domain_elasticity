#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
  int n;

  try {
    n = stoi(argv[2]);
  }
  catch(...) {
    n = 8;
  }

  string mesh = "Freefem++ -ne ./utils/mesh.edp -n " + to_string(n); // init mesh command
  string solve = "FreeFem++ -ne ./utils/solver.edp"; // solve problem command
  
  system(mesh.c_str()); // creating new mesh
  system(solve.c_str()); // solve problem

  return 0;
}
