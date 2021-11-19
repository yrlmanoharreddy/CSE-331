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
void printGivenLevel(NODE* root,
                     int level, int ltr);
int height(NODE* node);
struct node* newNode(int data);
void printSpiral(NODE* root)
{
    int h = height(root);
    int i;
    bool ltr = false;
    for(i = 1; i <= h; i++)
    {
        printGivenLevel(root, i, ltr);
        ltr = !ltr;
    }
}
void printGivenLevel(NODE* root,
                     int level, int ltr)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
         
    else if (level > 1)
    {
        if (ltr)
        {
            printGivenLevel(root->left,
                            level - 1, ltr);
            printGivenLevel(root->right,
                            level - 1, ltr);
        }
        else
        {
            printGivenLevel(root->right,
                            level - 1, ltr);
            printGivenLevel(root->left,
                            level - 1, ltr);
        }
    }
}
int height(NODE* node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
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
	 printSpiral(root);
	return 0;
}
