#include <stdio.h>
#include "HuffmanTree.h"
#include <iostream>
#include <algorithm>
using namespace std;
HuffmanTree::HuffmanTree(const string &m)
{
	int i,cnt,j,uni,min,secmin,pmin,psmin;
	struct keycount abc[m.size()];
	for(i=0,uni=1;i<m.size();i++)
	{
		for(j=0;j<uni;j++)
		{
			if(m[i]==abc[j].key)
			{
				abc[j].count++;
				break;
			}
			if(j+1 == uni)
			{
				uni++;
				abc[j].key=m[i];
				abc[j].count = 1;
				break;
			}
		}
	}
	Node *ptr[2*uni-1-2];
	cout << uni << endl;
	for(i=0;i<uni-1;i++)
	{
		ptr[i] = new TerminalNode(abc[i].key,abc[i].count);
		cout << ptr[i]->getFreq() << endl;
	}
	for(j=0,cnt=0;j<uni-2;j++)
	{
		for(i=0,min=999999,secmin=999999,pmin=0,psmin=0;i<uni-1+cnt;i++)
		{
			if(ptr[i]->parent==0)
			{
				if(ptr[i]->getFreq()<min){
					min = ptr[i] ->getFreq();
					pmin = i;
				}
				if(ptr[i]->getFreq()>=min && ptr[i]->getFreq()<secmin&&i!=pmin){
					secmin = ptr[i]->getFreq();
                    psmin = i;
                    if(secmin==min){
                        int tmp;
                       tmp = pmin;
                       pmin = psmin;
                       psmin = tmp;
                    }
				}
			}

		}
        ptr[uni-1+cnt] = new InternalNode(ptr[pmin],ptr[psmin]);
		ptr[pmin]->parent = 1;
		ptr[psmin]->parent = 1;
		printf("min: %d  secmin: %d\n",min,secmin);
		cnt++;
	}
	root = ptr[uni-1+cnt-1];
}
char TerminalNode::getValue()
{
	return value;
}
InternalNode::InternalNode(Node *L, Node *R)
{
	parent = 0;
	nodeType = 1;
	this->freq = L->getFreq()+R->getFreq();
	this->lChild = L;
	this->rChild = R;
}

TerminalNode::TerminalNode(char key,int count)
{
	value = key;
	freq = count;
	nodeType=0;
	parent = 0; //no parent;
}
int Node::getFreq(){
	return freq;
}
Node* HuffmanTree::getRoot()
{
	return root;
}
Node* InternalNode::getLChild()
{
    this->lChild->code = this->code + "0";
    return this->lChild;
}
Node* InternalNode::getRChild()
{
    this->rChild->code = this->code + "1";
    return this->rChild;
}
void HuffmanTree::treeprint(Node *p)
{
    if(p->nodeType!=0)
    {
        treeprint(p->getLChild());
        treeprint(p->getRChild());
    }
    else if(p->nodeType==0)
    {
        cout <<p->getValue() << "code = " << p->code << endl;
    }
}
