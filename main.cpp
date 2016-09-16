#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "tree.h"
using namespace std;

//void main()
int main()
{
	Tree<string> mytree;
	int lnCount = 1;
	string line;
	ifstream file("ninelie.txt");
	if(!file.eof())
	{
	    while(getline(file, line))
	    {
	        istringstream iss(line);
	        while(iss)
            {
                string word;
                iss >> word;
                if(word == "")
                    lnCount++;
                else
                {
                    mytree.insert(word, lnCount);
                }
            }
	    }
	}
	file.close();
	mytree.inorder();
	//
	return 0;
}
