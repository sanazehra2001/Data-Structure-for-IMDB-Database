#include <iostream>
#include <fstream>

#include <sstream>
#include "Movie.cpp"
#include "Director.cpp"
#include "Actor.cpp"
<<<<<<< Updated upstream
<<<<<<< Updated upstream


using namespace std;

=======
=======
>>>>>>> Stashed changes
#include "AVL.cpp"

#include "Movie.h"
#include "Director.h"
#include "Actor.h"
#include "AVL.h"

using namespace std;

void addDirector(string name, int likes, Movie* m)
{
    string key = name.substr(0, 2);

    if (Director::allDirectors.find(key) == Director::allDirectors.end())
    {
        //key is not present, create key-avl pair
        Director dir(name, likes);      //create a new director
        DirectorAVL avl;                //create an AVL for that key
        avl.insert(&dir);               //add the director to the AVL

        Director::allDirectors.insert({key, avl});  //finally add this newly created AVL to the map
    }
    else
    {   // the key already exists

        Director* d = Director::searchDir(name);    // pointer to the found dir or NULL otherwise  
       
        if (d)  
        {   // if director is found
            d->addMovie(m);
        }
        else
        {   //if no director with the provided name is found
            Director dir(name, likes);
            Director::allDirectors.at(key).insert(&dir);
            d->addMovie(m);
        }
        
    }
}

void addActor(string name, int likes, Movie* m)
{
    string key = name.substr(0, 2);

    if (Actor::allActors.find(key) == Actor::allActors.end())
    {
        //key is not present, create key-avl pair
        Actor actor(name, likes);       //create a new actor
        ActorAVL avl;                   //create an AVL for that key
        avl.insert(&actor);             //add the actor to the AVL

        Actor::allActors.insert({key, avl});  //finally add this newly created AVL to the map
    }
    else
    {   // the key already exists

        Director* d = Director::searchDir(name);    // pointer to the found dir or NULL otherwise  
       
        if (d)  
        {   // if director is found
            d->addMovie(m);
        }
        else
        {   //if no director with the provided name is found
            Director dir(name, likes);
            Director::allDirectors.at(key).insert(&dir);
            d->addMovie(m);
        }
        
    }
}
//
//         file.close();

//         cout << "The file has been closed. The doc has been parsed.";
//     }
//     else
//     {
//         cout << "Unable to open file";
//     }

//     return 0;
// }

// int main()
// {
//     cout << "Im inside";
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

>>>>>>> Stashed changes
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
                // cout << word<<endl;
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

<<<<<<< Updated upstream
<<<<<<< Updated upstream
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
=======
=======
>>>>>>> Stashed changes
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

        stringstream genres(colmVals[1]);
        while (getline(genres, word, '|')) // add genres to the list
        {
            m.setGenre(word);
        }

        m.setTitleYear(stoi(colmVals[2]));
        m.setImdbScore(stof(colmVals[3]));

        // Director d(colmVals[4], stoi(colmVals[5]));
        // if (Director::searchDir(d.getName()) == NULL) // if the dir is not in the dir map
        // {
        //     Director::allDirectors.insert({colmVals[4].at(0), &d});
        // }
        // m.setDirector(&d);

        m.setNumOfCriticReviews(stoi(colmVals[6]));
        m.setDuration(stoi(colmVals[7]));

        // Actor *actors[3];
        // for (int i = 8; i < 14; i + 2) // add actors to the array
        // {
        //     int actorIndex = 0;
        //     Actor a(colmVals[i], stoi(colmVals[i + 1]));

        //     if (Actor::searchActor(a.getName(), false) == NULL) // if the actor is not in the actor map
        //     {
        //         //Actor::allActors.insert({colmVals[i].at(0), &a});
        //     }
        //     actors[actorIndex] = &a;
        // }
        // m.setActor(actors);

        m.setGross(stoi(colmVals[14]));
        m.setNumOfVotes(stoi(colmVals[15]));
        m.setFbLikesForCast(stoi(colmVals[16]));
        m.setFaceNumInPoster(stoi(colmVals[17]));

        stringstream keywords(colmVals[18]);
        while (getline(keywords, word, '|')) // | separated keywords are added to the list
        {
            m.setPlotKeywords(word);
            cout << word << endl;
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
    return 0;
}
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
