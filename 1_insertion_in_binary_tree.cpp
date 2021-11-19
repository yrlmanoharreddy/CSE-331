#include<bits/stdc++.h>
using namespace std;
class NODE
{
	public:
		int data;
		NODE *left;
		NODE *right;
};
NODE* CreateNode(int dat)
{
    NODE* newNode = new NODE();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = dat;
    newNode->left = newNode->right = NULL;
    return newNode;
}
NODE *insertbt(NODE *root,int ele)
{
	if (root==NULL) 
	{
        root = CreateNode(ele);
        return root;
    }
    queue<NODE*> q;
    q.push(root);
    while (!q.empty()) 
	{
        NODE* temp = q.front();
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
        else
	    {
            temp->left = CreateNode(ele);
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else 
		{
            temp->right = CreateNode(ele);
            return root;
        }
    }
}
void inorder(NODE* temp)
{
    if (temp == NULL)
        return;
 
    inorder(temp->left);
    cout << temp->data <<" ";
    inorder(temp->right);
}
int main()
{
	int n,k;
	string str;
	getline(cin,str);
	n=str.length();
	NODE *root=NULL;
	for(int i=0;i<n;i++)
	{
		if(str[i]!=' ')
		root=insertbt(root,str[i]-48);
		
	}
	inorder(root);
	return 0;
}
