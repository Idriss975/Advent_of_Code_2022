#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>
using namespace std;

template<typename T>
T maxsum3(vector<T> V)
{
    T temp;
    for (unsigned int i = 1; i < 4; i++)
        for(typename vector<T>::iterator j = V.begin(); j < V.end()-i; j++)
        {
            if (*j > j[1])
            {
                temp = *j;
                *j = j[1];
                j[1] = temp;
            }
        }
    
    return V.end()[-1] + V.end()[-2] + V.end()[-3];
}

int main()
{
    ifstream Myfile("input.txt");
    string myText;
    vector<unsigned long> Elfes = {0};

    while (getline(Myfile, myText)) {
        if (myText.size() == 0u)
            Elfes.push_back(0ul);
        else
            Elfes.back() += stoul(myText);
    }
    Myfile.close();

    cout << "Max Value = " << maxsum3(Elfes) << endl;
    
    
    return 0;
}