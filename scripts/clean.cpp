#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
    string clean; 

    clean = "rm -r  ./storage/solutions/rand";
    system(clean.c_str());

    clean = "rm -r  ./storage/solutions/det";
    system(clean.c_str());

    clean = "rm -r  ./storage/meshes/rand";
    system(clean.c_str());

    clean = "zip -r storage.zip storage/";
    system(clean.c_str());

    return 0;
}