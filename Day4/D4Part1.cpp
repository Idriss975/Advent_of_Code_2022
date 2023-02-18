#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;


class Pair
{
    
public:
    unsigned char Left;
    unsigned char Right;
    Pair() 
    {
        Left = 0;
        Right = 0;
    }

    Pair(const string &Pair)
    {
        for(unsigned char i = 1; i < Pair.size(); i++)
            if(Pair.at(i) == '-')
            {
                Left = stoi(Pair.substr(0,i));
                Right = stoi(Pair.substr(i+1));
                break;
            }
    }

    bool encapsulates(const Pair &Line) const
    {
        return (Left <= Line.Left && Right >= Line.Right) || (Left >= Line.Left && Right <= Line.Right);
    }
};

array<Pair,2> SplitPairs(const string &Line)
{
    array<Pair,2> OUTP;
    for (unsigned char i = 2; i < Line.size(); i++)
        if(Line.at(i) == ',')
        {
            OUTP.at(0) = Pair(Line.substr(0, i));
            OUTP.at(1) = Pair(Line.substr(i+1));
            break;
        }
    return OUTP;
}




int main()
{
    ifstream Myfile("input.txt");
    string MyText;
    unsigned int Score = 0;
    array<Pair,2> P;

    while (getline(Myfile, MyText))
    {
        P = SplitPairs(MyText);
        if (P.at(0).encapsulates(P.at(1)))
            Score++;
    }
    
    cout << "Total score is " << Score << endl;


    return 0;
}