#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

template<class T>
T max(vector<T> &V)
{
    T temp = V.at(0);
    for(T& v : V)
        if (v > temp)
            temp = v;
    return temp;
}

int main()
{
    ifstream Myfile("input.txt");
    string myText;
    vector<unsigned long> Elfes = {0};

    while (getline(Myfile, myText)) {
        if (myText.empty())
            Elfes.push_back(0ul);
        else
            Elfes.back() += stoul(myText);
    }
    Myfile.close();

    cout << "Max Value = " << max(Elfes) << endl;
    
    
    return 0;
}