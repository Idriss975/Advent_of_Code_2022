#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include <array>
#include <vector>
using namespace std;

class Packet_Marker
{
public:
    unsigned long Count = 4;
    deque<char> BUFFER;
public:
    
    
    Packet_Marker(const string s) // Horrible Code
    {
        for (unsigned char i = 0; i < s.length(); i++)
            BUFFER.push_back(s.at(i));
    }

    char Extract_duplicate() // Could be optimized
    {
        for (unsigned char i = 0; i < 4; i++)
            for (unsigned char j = i+1; j < 4; j++)
                if (BUFFER.at(i) == BUFFER.at(j))
                    return i;
        return -1;
    }

    void insert_chars(vector<char> c)
    {
        for (auto &i : c)
        {
            BUFFER.pop_front();
            BUFFER.push_back(i);
            Count++;
        }
    }
};

int main()
{
    ifstream INP("input.txt");
    Packet_Marker PM(string() + char(INP.get()) ); // Horrible code (turns out i was doing undefined behaviour)
    PM.BUFFER.push_back(char(INP.get()));
    PM.BUFFER.push_back(char(INP.get()));
    PM.BUFFER.push_back(char(INP.get()));
    while (PM.Extract_duplicate() != -1 && !INP.eof())
    {
        for (unsigned char i = 0; i < PM.Extract_duplicate()+1; i++)
            PM.insert_chars({ char(INP.get()) });
    }
    
    cout << "first marker after character : " << PM.Count << endl;
    INP.close();

    return 0;
}