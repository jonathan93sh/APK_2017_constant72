#include <iostream>
#include "myarray.h"

using namespace std;
void intArrayTest();

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;

    intArrayTest();




    return 0;
}


void intArrayTest()
{
    MyArray<int> intArray;

    for(auto i = 0; i < 100; i++)
    {
        if(intArray.size() != i)
        {
            cout << "Fejl returner forkert size! forventet: " << i << ". men returneret: " << intArray.size() << endl;
        }
        intArray.fill(i);
    }

    if(*intArray.begin() != 0 || *intArray.end() != 100-1 )
        cout << "begin() og end() virker ikke korrekt" << "begin: " << *intArray.begin() << " og end: " << *intArray.end() << endl;

    for(auto i = 0; i < 100; i++)
    {
        if(intArray[i] != i)
            cout << "forkert retur værdi: " << intArray[i] << ". forventet: " << i << endl;

        cout << " " << intArray[i] << endl;
    }

    try
    {
        intArray[50] = 1000;
    }
    catch(std::out_of_range ex)
    {
        cout << ex.what() << endl;
    }

    cout << intArray[50] << " = 1000 ok" << endl;

    try
    {
        intArray[1000] = 1000;
    }
    catch(std::out_of_range ex)
    {
        cout << ex.what() << " Array er overflow beskyttet " << endl;

    }

    const auto& cref = intArray;

    for(auto i = 0; i < cref.size(); i++)
    {
        cout << intArray[i] << endl;
    }
    //cref.fill(123); -fpermissive
    //cref[4] = 10; assignment of read-only


}
