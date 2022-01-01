#include <iostream>
#include <fstream>

#include <sstream>
#include "Movie.cpp"
#include "Director.cpp"
#include "Actor.cpp"

using namespace std;

int main()
{
    int index;
    string line;
    string word;
    float val;
    short int year;
    string colmVals[28];
    ifstream file("IMDB_Top5000-SEECS.csv");

    cout << "File started";

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
                cout << word<<endl;
            }

            m.setTitleYear(stoi(colmVals[2]));
            m.setImdbScore(stof(colmVals[3]));

            Director d(colmVals[4], stoi(colmVals[5]));
            if (Director::searchDir(d.getName()) == NULL)   // if the dir is not in the dir map
            {
                //Director::allDirectors.insert({colmVals[4].at(0), &d});
            }
            m.setDirector(&d);

            m.setNumOfCriticReviews(stoi(colmVals[6]));
            m.setDuration(stoi(colmVals[7]));

            Actor* actors[3];
            for (int i = 8; i < 14; i + 2) // add actors to the array
            {
                int actorIndex = 0;
                Actor a(colmVals[i], stoi(colmVals[i + 1]));

                if (Actor::searchActor(a.getName(), false) == NULL)    // if the actor is not in the actor map
                {
                    //Actor::allActors.insert({colmVals[i].at(0), &a});
                }
                actors[actorIndex] = &a;
            }
            m.setActor(actors);

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
            //m.setColor(colmVals[27]);
        }
        file.close();

        cout << "The file has been closed. The doc has been parsed.";
    }
    else
    {
        cout << "Unable to open file";
    }

    return 0;
}

// int main()
// {
//     Actor a("Actor1");
//     Director d;
//     d.setName("Director");
//     Movie m;
//     m.setTitle("Movie1");

//     cout<<m.getTitle();
//     cout<<d.getName();
//     cout<<a.getName();

//     return 0;
// }