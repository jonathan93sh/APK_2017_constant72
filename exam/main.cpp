#include <iostream>
#include <typeinfo>
#include "destTemplate.hpp"
#define W_DIM 5
using namespace std;

int main(int argc, char *argv[])
{
    char a[W_DIM] = {1,1,1,1,1};
    char b[W_DIM] = {3,3,3,3,3};

    //string a = "test";
    //string b = "HHHH";
    //bool aa = false;
    //bool bb = true;

    //bool *a = &aa;
    //bool *b = &bb;

    //int a = 1;
    //int b = 2;

    cout << "Hello World!" << endl;
    auto dist = distance<W_DIM>(a,b);
    cout << "Distance: " << dist << " dist type: " << typeid(dist).name() << endl;
    return 0;
}
