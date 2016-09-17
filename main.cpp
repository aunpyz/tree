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
    try
    {
        cout<<"Enter the line number: ";
        cin>>ln;
        if(ln >= 1 && ln <= mytree.getListSize() )
            //find nodes in a list (based on line input)
            cout<<mytree.lineNode(ln-1);
        else if(ln == -1)
            return 0;
        else
            throw invalid_argument("");
    }
    catch(const invalid_argument& e)
    {
        cout<<"Invalid input"<<endl;
    }
	//
	return 0;
}
