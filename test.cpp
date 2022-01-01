#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a = "movies";
    string b = "movi";

    if (a.substr(0, b.length()) == b)
        cout << "matched" << endl;

    return 0;
}