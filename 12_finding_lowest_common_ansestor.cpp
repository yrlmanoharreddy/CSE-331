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
        else {
            temp->right = CreateNode(ele);
            return root;
        }
    }
}
bool findPath(NODE *root, vector<NODE *> &p, int n){
    if(root==NULL)return false;
    p.push_back(root);
    if(root->data==n)return true;
    
    if(findPath(root->left,p,n)||findPath(root->right,p,n))return true;
    
    p.pop_back();
    return false;
}

NODE *lca(NODE *root, int n1, int n2){
    vector <NODE *> path1, path2;
    if(findPath(root,path1,n1)==false||findPath(root,path2,n2)==false)
        return NULL;
    for(int i=0;i<path1.size()-1 && i<path2.size()-1;i++)
        if(path1[i+1]!=path2[i+1])
            return path1[i];
    return NULL;
}
int main()
{
	int n;
	string str;
	getline(cin,str);
	n=str.length();
	NODE *root=NULL;
	for(int i=0;i<n;i++)
	{
		if(str[i]!=' ')
		root=insertbt(root,str[i]-48);
		
	}
	int n1,n2;
	cin>>n1>>n2;
	NODE *x=lca(root,n1,n2);
	cout<<x->data;
	return 0;
}
