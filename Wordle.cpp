#include "Wordle.h"

#include <iostream>
#include <fstream>

using std::ifstream;
using namespace std;

vector<string> Wordle::validWords;
// Opens txt file and puts words into vector
void Wordle::loadWords(string filename)
{
    ifstream file;
    file.open(filename);
    string word;

    while(getline(file, word))
    {
        validWords.push_back(word);
    }
}

//Picks a random word from vector and is the solution
string Wordle::pickRandom()
{
    srand(time(NULL));
    string randomWord;
    int random = rand() % validWords.size();
    randomWord = validWords[random];

    return randomWord;
}

//Compares guess and solution and will provide feedback
string Wordle::compareWords(string guess, string solution)
{
    int position = 0;
    string a = guess;
    string b = solution;
    string clue = ""; // NULL FOR NOW

    for(int i = 0; i < 5; i++)
    {
        if(a[i] == b[position])
        {
            clue += " G ";
            position++;
        }
        else if( (a[i] == b[0]) ||(a[i] == b[1]) ||(a[i] == b[2]) ||(a[i] == b[3]) ||(a[i] == b[4]))
        {
            clue += " Y ";
            position++;
        }
        else
        {
            clue += " - ";
            position++;
        }
    }
    cout << clue << endl;
    return clue; //= "G G G G G";
}

bool Wordle::ifGuessed(string output){
    string a = output;
    if(a == "G G G G G")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Wordle::winWordle()
{
    string output;
    string input;
    int count = 0;
    string solution = pickRandom();

    for(int i = 0; i < 5; i++)
    {
        cout << "Input a 5-letter word: " << endl;
        cin >> input;
        if(input.length() != 5)
        {
           cout << "Invalid Word!" << endl;
        }
        else
        {
            output = compareWords(input, solution);
            if(ifGuessed(output) == false){
            count++;
            }
            else
            {
                cout << "You Won!" << endl;
                return true;
            }
        }

    }
}









