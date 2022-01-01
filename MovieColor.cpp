#include <string>
using namespace std;

enum MovieColor{
    Color,
    Black, 
    Unspecified
};

MovieColor convertColor(string s){
    if (s.compare("Color")) return Color;
    else if (s.compare("Black and White")) return Black;
    else if (s.compare("")) return Unspecified;
}