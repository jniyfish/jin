#ifndef HuffmanTree_H
#define HuffmanTree_H
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

class Node
{
	friend class HuffmanTree;
	protected:
	int freq;
	int parent;
	int nodeType;

    public:
    string code;
	int getFreq();
    virtual int getNodeType(){}
	virtual char getValue()	{
		cout <<"this Node doesn't have value"<<endl;
		return 0;
	}
    virtual Node* getLChild(){
        cout <<"this Node doesn't have Left child"<<endl;
        return NULL;
    }
    virtual Node* getRChild(){
        cout <<"this Node doesn't have Right child"<<endl;
          return NULL;
    }
};


class InternalNode : public Node
{
	private:
		Node*lChild;
		Node*rChild;
	public:
        int getNodeType(){return 1;};
        char getValue(){
            cout << "InternalNode doesn't have value" << endl;
            return 0;
        };
		InternalNode(Node *L,Node*R);
		Node* getLChild();
		Node* getRChild();

};
class TerminalNode : public Node
{
	private:
		char value;
	public:
		char getValue();
        Node* getLChild(){
            cout <<"this Node doesn't have Left child"<<endl;
              return NULL;
        }
        Node* getRChild(){
            cout <<"this Node doesn't have Right child"<<endl;
              return NULL;
        }

		TerminalNode(char key,int count);
};
struct keycount{
	char key;
	int count;
};
class HuffmanTree
{
	private:
		Node *root;
	public:
		Node *getRoot();
		void treeprint(Node *);
		HuffmanTree(const string &);

};
#endif
