#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

array<unsigned char, 3> SplitInstruction(const string &Raw)
{
    array<unsigned char, 3> OUTP;
    OUTP.at(0) = stoi(Raw.substr(5, Raw.find('f')-1U)) - 1U;
    OUTP.at(1) = stoi(Raw.substr(Raw.find('f')+5U, Raw.find('t')-1U)) - 1U;
    OUTP.at(2) = stoi(Raw.substr(Raw.find('t')+3U)) - 1U;

    return OUTP;
}

void TopofEachcreate(const array<vector<unsigned char>, 9> &ST)
{
    cout << "Top of each Table = ";
    for (auto &i : ST)
        cout << i.back();
    cout << endl;
    
}

int main()
{
    array<vector<unsigned char>, 9> ST;
    array<unsigned char, 3> Insts;
    ifstream File("input.txt");
    string Text;

    for(unsigned char i = 0; i < 8; i++)
    {
        getline(File, Text);
        for(unsigned char j = 1; j < 36 ; j+=4)
            if (Text.at(j) != ' ')
                ST.at((j-1)/4).push_back(Text.at(j));
    }
    for(vector<unsigned char>& i : ST)
        reverse(i.begin(), i.end());
    for (size_t i = 0; i < 2; i++) //Skip 2 lines
        getline(File, Text);
    
    /*
    [N]         [C]     [Z]            
    [Q] [G]     [V]     [S]         [V]
    [L] [C]     [M]     [T]     [W] [L]
    [S] [H]     [L]     [C] [D] [H] [S]
    [C] [V] [F] [D]     [D] [B] [Q] [F]
    [Z] [T] [Z] [T] [C] [J] [G] [S] [Q]
    [P] [P] [C] [W] [W] [F] [W] [J] [C]
    [T] [L] [D] [G] [P] [P] [V] [N] [R]
     1   2   3   4   5   6   7   8   9 

    move 6 from 2 to 1
    */
    while (getline(File, Text))
    {
        Insts = SplitInstruction(Text);
        for (unsigned char i = 0; i < Insts.at(0)+1; i++)
        {
            //ST.at(Insts.at(2)).push_back(ST.at(Insts.at(1)).back());
            //ST.at(Insts.at(1)).pop_back();
            ST.at(Insts.at(2)).push_back(ST.at(Insts.at(1)).end()[-Insts.at(0)-1+i]);
            ST.at(Insts.at(1)).erase(ST.at(Insts.at(1)).end()-Insts.at(0)-1+i);
        }
    }
    
    TopofEachcreate(ST);
    
    return 0;
}