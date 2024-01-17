#include <iostream>
#include<stdlib.h>
#include <queue>
using namespace std;
queue<string> Q2;
template<class S, class T>// Template for string ang integer
class Player                       // PLayer Class Stores the information of Player
{
    S Name;
    T score;
public:
    Player()                        // Default Constructor
    {
        Name = "";
        score = 0;
    }
    Player(S Name, T score)         // OverLoaded Constructor
    {
        this->Name = Name;
        this->score = score;
    }
    friend class Game;
};

queue<Player<string, int>> Q;   // STL Queue
class Game                  // Class to play the Game
{
private:
    int dice;
public:
    Game()
    {
        dice = 0;
    }
    int Roll_dice()             // Function to get a random dice face
    {
        dice=rand()%6+1;
        return dice;
    }
    void play()                // Function tp play snake and ladders with conditions
    {
        Player<string,int> temporary;
        int Dice, i = 1;

        while(!Q.empty())      // Loop until the Queue gets empty
        {
            cout << "\nIts " << Q.front().Name << " turn.Please enter any key to continue ";
            cin.ignore();       // Entering any random key
            cin.get();
            if(Q.front().score != 100)            // Condition until the player reached the 100 score
            {
                Dice = Roll_dice();
                cout << Q.front().Name << " got " << Dice << ".";
                Q.front().score = Q.front().score + Dice;          // Adding updated and previous score
                if(Q.front().score > 100)
                {
                    cout << " TRY AGAIN :(" << endl;
                    Q.front().score = Q.front().score - Dice;
                }
                else  if(Q.front().score == 20)                      //ladder at 20/
                {
                    cout << "###### LADDER FOUND.The Total score is now 40 " << endl ;
                    Q.front().score = Q.front().score + 20; // Reached to the score 40
                }
                else if(Q.front().score == 60)                       //ladder at 60
                {
                    cout << "###### LADDER FOUND.The Total score is now 75 " << Q.front().Name<< endl ;
                    Q.front().score = Q.front().score + 15; // Reached to the score 75
                }
                else if(Q.front().score == 50)                         //Snake at 50
                {
                    cout << "  (-,-)OOOOOOOOOOO SNAKE BITES.The Total score is now 40  " << endl ;
                    Q.front().score = Q.front().score - 10; // Reached to the score 40
                }
                else if(Q.front().score == 90)                         //Snake at 90
                {
                    cout << "  (-,-)OOOOOOOOOOO SNAKE BITES..The Total score is now 79 "<< endl;
                    Q.front().score = Q.front().score - 11; // Reached to the score 79
                }
                else
                {
                    cout << " The Total score of "<< Q.front().Name << " is now " << Q.front().score;
                }
                temporary = Q.front();       // Saving in the temporary to again push in the Queue untill it wants
                Q.pop();
                Q.push(temporary);
            }
            else if(Q.front().score == 100)
            {
                cout << Q.front().Name <<" got " << i << " position  :) "<< endl;
                Q2.push(Q.front().Name);
                i++;
                Q.pop();
            }

        }
    }
    void Display_Positions()     // Function to Display the positions
    {
        int x = 1;
        while (!Q2.empty())
        {
            cout <<"********* PLAYER "<<Q2.front()<< " GOT " << x <<" POSITION ********** " << endl;
            x++;
            Q2.pop();
        }
        cout << '\n';
    }

};

int main()
{
    Game G;
    int No_Players, i =0;
    string Player_Name;
    cout << "\nPlease enter the numbers of players : ";
    cin >> No_Players;
    if(No_Players == 1)
    {
        cout << "SORRY 1 PLAYER CAN'T PLAY THIS GAME " << endl;
    }
    if(No_Players != 1) {
        while (i < No_Players) {
            cout << "Please enter the Name of Player " << i + 1 << " : ";
            cin >> Player_Name;
            Player <string, int> P1(Player_Name, 0);    // Sending score 0 as Initial Key
            Q.push(P1);
            i++;
        }
    }
    G.play();
    cout << endl;
    G.Display_Positions();

    return 0;
}