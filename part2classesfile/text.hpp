#include <fstream>
#include <string>
#include <iostream>
using namespace std;
class Text
{
    string text;
public:
    Text(){};
    Text(const string& name)
    {
        ifstream infile;
        infile.open(name);
        if(!infile.good())
        {
            std::cout << "File is not open";
        }
        else
        {
            string line;
            while(getline(infile,line))
                text = text + line + '\n';
        }
    };
    string contetns()
    {
        return text;
    };
};
