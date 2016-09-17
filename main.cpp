#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <stdexcept>
#include "tree.h"
using namespace std;

//void main()
int main()
{
	Tree<string> mytree;
	int lnCount = 1;
	string line;
	int ln; // line for user to see
	ifstream file("ninelie.txt");
	//ifstream file("story.txt");
	if(!file.eof())
	{
	    while(getline(file, line))
	    {
	        mytree.addLine(line);
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
	cout<<setw(20)<<"Index"<<endl;
    mytree.inorder();
    cout<<"Which line you wanna see?: ";
    try
    {
        cin>>ln;
        if(typeid(ln) != typeid(int))
            throw invalid_argument("");
        if(ln < 1)
            throw invalid_argument("");
        //find nodes in a list (based on line input)
        cout<<mytree.lineNode(ln-1);
    }
    catch(const invalid_argument& e)
    {
        cout<<"Invalid input"<<endl;
    }
	//
	return 0;
}
