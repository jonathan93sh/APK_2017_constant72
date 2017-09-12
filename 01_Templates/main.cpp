#include <iostream>
#include "myarray.h"
#include "sharedptr.h"

using namespace std;

void intArrayTest();
void myFindTest();
void stringTest();
void sharedptrTest();

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;

    intArrayTest();

    myFindTest();
    sharedptrTest();

    stringTest();
    string * test = new std::string("test");

    string * t2 = new std::string(*test);
    cout << *t2 << endl;
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

void myFindTest()
{
    {
        MyArray<int> my;

        for(auto i = 0; i < 10; i++)
            my.fill(i);

        cout << "Looking for '9'? " << (myfind(my.begin(), my.end(), 9) != nullptr? " Found " : " nothing") << " rvalue: " << *myfind(my.begin(), my.end(), 9) << endl;
    }

    /*{
        MyArray<double> my;

        for(auto i = 0; i < 10; i++)
            my.fill(i);

        cout << "Looking for '9'? " << (myfind(my.begin(), my.end(), 9) != nullptr? " Found " : " nothing") << " rvalue: " << *myfind(my.begin(), my.end(), 9) << endl;
        // no matching function for call to myfind(const double *, const double *, int)
    }*/

    MyArray<double> myD; // ex 1.3 - grunden til at koden for myArray<int> ikke vil virke for myArray<double> er fordi templates funktioner kun har explisit cast, så kompileren finder ikke automatisk ud af at den skal caste den integer værdi om til en double, og derfor ikke kan finde myfind der passer til parameter typerne.

    for(auto i = 0; i < 10; i++)
        myD.fill(i);

    cout << "Looking for '9'? " << (myfind(myD.begin(), myD.end(), (double)9) != nullptr? " Found " : " nothing") << " rvalue: " << *myfind(myD.begin(), myD.end(),(double) 9) << endl;


    {
        MyArray<double> my;

        for(auto i = 0; i < 10; i++)
            my.fill(i);

        cout << "Looking for '9'? " << (myfind(my.begin(), my.end(), 9) != nullptr? " Found " : " nothing") << " rvalue: " << *myfind(my.begin(), my.end(), 9) << endl;
        // efter at have tilføjet en ekstra template parameter behøver vi ikke at caste 9 om til en double.
    }

    MyArray<int> my;
    for(auto i = 20; i > 0; i--)
        my.fill(i);

    myD = my;

    for(auto i = 0; i < my.size(); i++)
    {
        if((int)myD[i] != my[i])
            cout << "myD har ikke den samme værdi som my" << myD[i] << "!=" << my[i] << endl;
        cout << myD[i] << " == " << my[i] << endl;
    }

}

void stringTest()
{
    MyArray<string *> myStr;

    myStr.fill(new string("Hallo"));
    myStr.fill(new string("Det"));
    myStr.fill(new string("Vrker"));
    myStr.fill(new string("sku'"));

    for(auto i = 0; i < myStr.size(); i++)
    {
        cout << *myStr[i] << endl;
    }

    myStr[2] = new std::string("Virker");

    for(auto i = 0; i < myStr.size(); i++)
    {
        cout << *myStr[i] << endl;
    }

    cout << ***myStr.begin() << endl;
cout << ***myStr.end() << endl;

    myfind(myStr.begin(), myStr.end(), std::string("test"));

    cout << "Looking for 'Virker'? " << (myfind(myStr.begin(), myStr.end(), std::string("Virker")) != nullptr? " Found " : " nothing") << " rvalue: " << ***myfind(myStr.begin(), myStr.end(), std::string("Virker")) << endl;
}

void sharedptrTest()
{
    SharedPtr<std::string> stest(new std::string("Hej med dig"));

    {
        cout << *stest << " count: " << stest.count() << endl;
        SharedPtr<std::string>  hej(new std::string("endnu en test"));
        stest = hej;
        cout << *hej << " == " << *stest << " count: " << hej.count() << " == " << stest.count() <<  endl;
    }

    cout << *stest << " count: " << stest.count() << endl;




}
