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
    map["1"] = m;
    map["a1"] = m;
    map["Ac"] = m;
    map["Ab"] = m;
    map["c"] = m;
    map["ae"] = m;
    map["az"] = m;
    map["b"] = m;
    map["b1"] = m;
    map["B"] = m;
    map["d"] = m;
    map["B"] = m;

    // for (auto it = map.lower_bound("a"); it != map.upper_bound("az"); it++)
    // {
    //     cout << it->first << endl;
    // }
    for (auto it = map.lower_bound("A"); it != map.upper_bound("Az"); it++)
    {
        cout << it->first << endl;
    }
    // for (auto it = map.begin(); it != map.end(); it++)
    // {
    //     cout << it->first << endl;
    // }
    // if (map["c"].name == "")
    //     cout
    //         << map["a"].name;

    return 0;
}