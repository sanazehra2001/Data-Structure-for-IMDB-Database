#include <string>
using namespace std;

enum MovieColor{
    Color,
    Black
};

MovieColor convert(string s){
    if (s == "Color") return Color;
    else if (s == "Black and White") return Black;
}