#include <iostream>
#include <string>
#include <fstream>
#include <array>
using namespace std;


uint8_t Misplacement(string& A, string& B, string& C)
{
    for (char &i : A)
        if (B.find(i) != string::npos)    
            if (C.find(i) != string::npos)
                return isupper(i) ?  i - 38 : i - 96;
    return 0U;
}

int main()
{
    ifstream Myfile("input.txt");
    string myText;
    unsigned long Score = 0;
    array<string,3> SplitText;

    unsigned char ind = 0;
    while (getline(Myfile, myText)) 
    {
        SplitText.at(ind) = myText;
        if(ind == 2U)
            Score += Misplacement(SplitText.at(0), SplitText.at(1), SplitText.at(2));
        ind = (ind+1U) % 3U;
    }    
    
    Myfile.close();
    
    cout << "Total is " << Score << endl;

    return 0;
}