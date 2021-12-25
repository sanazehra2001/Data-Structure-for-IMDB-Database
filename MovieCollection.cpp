#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Movie.cpp"

using namespace std;

//This file will work as our parser

class MovieCollection{
    
    
    //methods:
    //  a)  read csv file
    //  b)  create an object of MovieNode class
    //  c)  Automatically inserts all the entries of that line in various fields of the 
    //      data part in the MovieNode object. Note that the data field is of type Movie
    //  d)  Finally, insert the newly created MovieNode object in your list


    //After parsing, implement functionalities of table-1

};

int main(){
    
    string line;
    string word;
    string colmVals[28];
    int index;
    ifstream file ("IMDB_Top5000-SEECS.csv");

    if (file.is_open()){
        getline(file, line);        // gets the row of column headings

        //while(getline(file, line)){     // reads an entire row and stores it in line
            index = 0;
            getline(file, line);
            stringstream s (line);      // breaks the line into words
            
            while(getline(s, word, ',')){      // for every colm of a row, stores data in word
                colmVals[index++] = word;
            }

            //cout << line << "\n";
        //}
        file.close();
    }
    else{
        cout << "Unable to open file";
    }


    return 0;
}