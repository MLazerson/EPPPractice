#include <fstream>
#include <string>
#include <iostream>
#include "text.hpp"
using namespace std;
int main()
{
    Text o1;
    Text o2("apex.txt");
    cout << "content: " << o1.contetns() << endl;
    cout << "content: " << o2.contetns() << endl;
    system("pause");
}
