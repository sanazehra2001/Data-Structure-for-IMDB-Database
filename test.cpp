#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

class Movie
{
public:
    string name;
    Movie()
    {
    }
    Movie(string n)
    {
        name = n;
    }
};

int main()
{
    Movie m("movie1");

    map<string, Movie> map;
    map["a1"] = m;
    map["Ac"] = m;
    map["ae"] = m;
    map["b1"] = m;

    for (auto it = map.lower_bound("A"); it != map.upper_bound("b"); it++)
    {
        cout << it->first << endl;
    }
    if (map["c"].name == "")
        cout
            << map["a"].name;

    return 0;
}