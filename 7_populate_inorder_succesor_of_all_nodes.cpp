#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
		int data;
		node *left,*right,*next;
};
node *cbt(int key)
{
	node *newnode=new node;
	newnode->data=key;
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->next=NULL;
	return newnode;
}
node *btc(node *root,int key)
{
	if(root==NULL)
	{
		return cbt(key);
	}
	queue<node *> q;
	q.push(root);
	while(!q.empty())
	{
		node *temp=q.front();
		q.pop();
		if(temp->left!=NULL)
		{
			q.push(temp->left);
		}
		else
		{
			temp->left=cbt(key);
			return root;
		}
		if(temp->right!=NULL)
		{
			q.push(temp->right);
		}
		else
		{
			temp->right=cbt(key);
			return root;
		}
	}
}
void populateNext(node* p)
{
    static node *next = NULL;
 
    if (p)
    {
        populateNext(p->right);
        next = p;
        populateNext(p->left);
    }
}
int main()
{
	int n,k;
	string str;
	getline(cin,str);
	n=str.length();
node *root=NULL;
	for(int i=0;i<n;i++)
	{
		if(str[i]!=' ')
		root=btc(root,str[i]-48);
		
	}
    populateNext(root);
    node *ptr = root->left->left;
    while(ptr)
    {
        cout << "Next of " << ptr->data << " is "
             << (ptr->next? ptr->next->data: -1)
             << endl;
        ptr = ptr->next;
    }
	return 0;
}
