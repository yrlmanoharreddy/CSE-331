#include<bits/stdc++.h>
#define cap 10000
using namespace std;
class heap
{
	public:
		int capacity;
		int size;
		int *arr;
		heap(int c)
		{
			size=0;
			capacity=c;
			arr=new int[c];
		}
		int left(int i)
		{
			return (2*i+1);
		}
		int right(int i)
		{
			return (2*i+2);
		}
		int parent(int i)
		{
			return ((i-1)/2);
		}
		void insert(int k)
		{
			if(size==capacity)
			{
				return;
			}
			size++;
			arr[size-1]=k;
			for(int i=size-1;i!=0 && arr[i]>arr[parent(i)];)
			{
				swap(arr[i],arr[parent(i)]);
				i=parent(i);
			}
		}
		void print(int n)
		{
			for(int i=0;i<n;i++)
			{
				cout<<arr[i]<<" ";
			}
		}
};
int main()
{
	heap obj(cap);
	int n,k;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		obj.insert(k);
	}
	obj.print(n);
	return 0;
}
