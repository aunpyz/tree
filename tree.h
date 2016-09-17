#include <queue>
#include <stack>
#include <iomanip>
#include <vector>

using namespace std;

#ifndef Binary_Search_Tree
#define Binary_Search_Tree

template<class T> class Tree;

template<class T>
class Node
{
    public:
        Node() { left=right=NULL; }
        Node(const T& el, int ln=0, Node *l=0, Node *r=0)
        {
            key=el; left=l; right=r;
            line = ln;
        }
        T key;
        Node *left, *right;
        int line;
};

template<class T>
class Tree
{
    public:
        Tree() { root = 0; }
        ~Tree() { clear(); }
        void clear() { clear(root); root = 0; }
        bool isEmpty() { return root == 0; }
        void inorder() { inorder(root); }
        void insert(const T& el, int ln);
        void addLine(const T& ln);
        void deleteNode(Node<T> *& node);
        //print all nodes in a specific line
        T lineNode(int ln);
    protected:
        Node<T> *root;
        vector<T> lineList;
        void clear(Node<T> *p);
        void inorder(Node<T> *p);
};

template<class T>
void Tree<T>::clear(Node<T> *p)
{
	if (p != 0)
    {
	     clear(p->left);
	     clear(p->right);
	     delete p;
	}
}

template<class T>
void Tree<T>::inorder(Node<T> *p)
{
	//TO DO! This is for an inorder tree traversal!
    if(p != NULL)
    {
        inorder(p->left);
        //cout << p->key << endl;
        cout<<setw(15)<<p->key <<setw(10)<< p->line<<endl;
        inorder(p->right);
    }
}

template<class T>
// int ln refers to line number(s)
void Tree<T>::insert(const T &el, int ln)
{
	Node<T> *p = root, *prev = 0;
	while(p != 0)
    {
		prev = p;
		if(p->key < el) p=p->right;
		else p=p->left;
	}
	if(root == 0) root = new Node<T>(el,ln);
	else if(prev->key<el) prev->right = new Node<T>(el, ln);
	else
		prev->left = new Node<T>(el, ln);
}

template<class T>
void Tree<T>::deleteNode(Node<T> *&node)
{
	Node<T> *prev, *tmp=node;
	if(node->right == 0) node = node->left;
	else if(node->left == 0) node = node->right;
	else
    {
		tmp = node->left;
		prev = node;
		while(tmp->right != 0)
		{
			prev = tmp;
			tmp=tmp->right;
		}
		node->key = tmp->key;
		if(prev == node) prev->left = tmp->left;
		else prev->right = tmp->left;
	}
	delete tmp;
}

//breadth first search **stack **queue
template<class T>
void Tree<T>::addLine(const T& ln)
{
    lineList.push_back(ln);
}

template<class T>
T Tree<T>::lineNode(int ln)
{
    return lineList.at(ln);
}

#endif // Binary_Search_Tree
