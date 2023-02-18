#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define WIN 6
#define LOSE 0
#define DRAW 3
enum RPS
{
    Rock=1,
    Paper,
    Scissors
};
class RockPaperScissors
{
    public:
        RPS me; 
        RPS opponent; 
        RockPaperScissors() {}
        RockPaperScissors(string v) 
        {
            //me
            me = v[2] == 'X' ? RPS::Rock : (v[2] == 'Y' ? RPS::Paper : RPS::Scissors);
            //other
            opponent = v[0] == 'A' ? RPS::Rock : (v[0] == 'B' ? RPS::Paper : RPS::Scissors);
        }
        unsigned char Win()
        {
            int Score = me - opponent; 
            return Score == 1 || Score == -2 ? WIN : ( Score == 0 ? DRAW : LOSE);
        }

        unsigned char RoundScore()
        {
            return me + Win(); 
        }
    
};



int main()
{
    ifstream Myfile("input.txt");
    string myText;
    RockPaperScissors RRR;
    unsigned long points = 0ul;

    while (getline(Myfile, myText)) 
    {
        if (!myText.empty())
        {
            RRR = RockPaperScissors(myText);
            points += RRR.RoundScore();
        }
    }
    Myfile.close();

    cout << "Total score is " << points << endl;
    return 0;
}