#include <iostream>
#include <string>
#include <fstream>
#include <array>
using namespace std;

int main()
{
    ifstream Myfile("input.txt");
    string myText;
    unsigned long Score = 0;
    array<string,2> SplitText;


    while (getline(Myfile, myText)) 
        if (!myText.empty())
        {
            SplitText.at(0) = myText.substr(0 ,myText.size() / 2);
            SplitText.at(1) = myText.substr((myText.size() / 2));
            for (char& c : SplitText.at(0))
                if (SplitText.at(1).find(c) != string::npos)
                {
                    Score += isupper(c) ? c - 38 : c - 96;
                    break;
                }
        }
    Myfile.close();
    
    cout << "Total is " << Score << endl;

    return 0;
}