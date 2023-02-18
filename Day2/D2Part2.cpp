#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define WIN 6U
#define LOSE 0U
#define DRAW 3U

#define ROCK 1U
#define PAPER 2U
#define SCISSORS 3U

unsigned long RockPaperScissors(char Op, char W)
{
    if (W == 'X') //Lose
        return (Op == 'A' ? SCISSORS : (Op == 'B' ? ROCK : PAPER)) + LOSE;
    
    else if (W == 'Y') //Draw
        return (Op == 'A' ? ROCK : (Op == 'B' ? PAPER : SCISSORS)) + DRAW;
    
    else // Win
        return (Op == 'A' ? PAPER : (Op == 'B' ? SCISSORS : ROCK)) + WIN;
}

int main()
{
    ifstream Myfile("input.txt");
    string myText;
    unsigned long points = 0U;

    while (getline(Myfile, myText)) 
        if (!myText.empty())
            points += RockPaperScissors(myText[0], myText[2]);
    
    Myfile.close();

    cout << "Total score is " << points << endl;
    return 0;
}