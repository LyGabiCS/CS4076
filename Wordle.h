#ifndef WORDLE_H
#define WORDLE_H

#include <iostream>
#include <vector>

using std::string;
using std::vector;

//Make this class abstract! will use it for the 3 types of wordle puzzles??
class Wordle {

public:
    static void loadWords(string);
    static string pickRandom();
    static string compareWords(string, string);
    static bool ifGuessed(string);
    static bool winWordle();



private:
    static vector<string> validWords; // stores all available words
    static int guessCount; // Limit of 5
    static string solution; // stores the word that is to be guessed



};
#endif // WORDLE_H
