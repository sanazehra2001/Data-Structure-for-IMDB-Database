#include <string>
using namespace std;

enum MovieColor
{
    Color,
    Black,
    Unspecified
};

MovieColor convertColor(string s)
{
    if (s == ("Color"))
        return Color;
    else if (s == "Black and White")
        return Black;
    else if (s == "")
        return Unspecified;
}

string toStringForColor(MovieColor c)
{
    switch (c)
    {
    case Color:
        return "Color";
    case Black:
        return "Black and White";
    case Unspecified:
        return "Unspecified";
    }
}