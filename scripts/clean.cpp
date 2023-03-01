#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
    string del;

    // deleting meshes
    del = "rm ./storage/meshes/det/*";
    system(del.c_str());

    del = "rm ./storage/meshes/rand/mesh/*";
    system(del.c_str());

    del = "rm ./storage/meshes/rand/mesh0/*";
    system(del.c_str());

    del = "rm ./storage/meshes/rand/mesh1/*";
    system(del.c_str());

    // deleting solutions
    del = "rm ./storage/solutions/det/*";
    system(del.c_str());

    del = "rm ./storage/solutions/rand/sig/*";
    system(del.c_str());

    del = "rm ./storage/solutions/rand/u/*";
    system(del.c_str());

    del = "rm ./storage/solutions/rand/v/*";
    system(del.c_str());

  return 0;
}