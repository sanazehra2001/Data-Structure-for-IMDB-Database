#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include "Movie.cpp"
#include "DirectorNode.cpp"
//#include "ActorNode.cpp"

using namespace std;
class MovieCollection
{
};

int main()
{
    int index;
    string line;
    string word;
    float val;
    short int year;
    string colmVals[28];
    ifstream file("IMDB_Top5000-SEECS.csv");

    if (file.is_open())
    {
        getline(file, line); // gets the row of column headings

        while (getline(file, line)) // reads an entire row and stores it in line
        {
            index = 0;
            stringstream s(line); // breaks the line into words

            Movie m; // create a new Movie node for each row

            while (getline(s, word, ',')) // the comma separated values are stored at consecutive array index
            {
                colmVals[index++] = word;
            }

            // setting attributes of each Movie
            m.setTitle(colmVals[0]);

            while (getline(stringstream(colmVals[1]), word, '|')) // add genres to the list
            {
                m.setGenre(word);
            }

            m.setTitleYear(stoi(colmVals[2]));
            m.setImdbScore(stof(colmVals[3]));

            DirectorNode d(colmVals[4], stoi(colmVals[5]));
            if (DirectorNode::searchDir(d.getName()) == NULL)   // if the dir is not in the dir map
            { 
                DirectorNode::allDirectors.insert({colmVals[4].at(0), &d});
            }
            m.setDirectorNode(&d);

            m.setNumOfCriticReviews(stoi(colmVals[6]));
            m.setDuration(stoi(colmVals[7]));

            for (int i = 8; i < 14; i + 2) // add actors to the array
            {
                ActorNode a(colmVals[i], stoi(colmVals[i + 1]));

                if (ActorNode::searchActor(a.getName()) == NULL)    // if the actor is not in the actor map
                { 
                    ActorNode::allActors.insert({colmVals[i].at(0), &a});
                }

                m.setActor(&a);
            }

            m.setGross(stoi(colmVals[14]));
            m.setNumOfVotes(stoi(colmVals[15]));
            m.setFbLikesForCast(stoi(colmVals[16]));
            m.setFaceNumInPoster(stoi(colmVals[17]));

            while (getline(stringstream(colmVals[18]), word, '|'))  // | separated keywords are added to the list
            { 
                m.setPlotKeywords(word);
            }

            m.setImdbLink(colmVals[19]);
            m.setNumOfReviews(stoi(colmVals[20]));
            m.setLanguage(colmVals[21]);
            m.setCountry(colmVals[22]);
            m.setContentRating(colmVals[23]);
            m.setBudget(stoi(colmVals[24]));
            m.setAspectRatio(stof(colmVals[25]));
            m.setFbLikesForMovie(stoi(colmVals[26]));
            m.setColor(colmVals[27]);
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }

    return 0;
}