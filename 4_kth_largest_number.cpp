#include<bits/stdc++.h>
using namespace std;
void heapify(int k,int heap[],int n)
{
	int parent=k;
	int left=2*k+1;
	int right=2*k+2;
	if(right<n && heap[right]>heap[parent])
	{
		parent=right;
	}
	if(left<n && heap[left]>heap[parent])
	{
		parent=left;
	}
	if(parent!=k)
	{
		swap(heap[k],heap[parent]);
	    heapify(parent,heap,n);
    }
}
void buildbinaryheap(int heap[],int n)
{
	int l_n_l_i=(n-2)/2;
	for(int i=l_n_l_i;i>=0;i--)
	{
		heapify(i,heap,n);
	}
}
int extractmin(int arr[],int size)
		{
			if(size==0)
			{
				return INT_MAX;
			}
			if(size==1)
			{
				size--;
				return arr[0];
			}
			swap(arr[0],arr[size-1]);
			size--;
			heapify(0,arr,size);
			return arr[size];
		}
int main()
{
	int n;
	cin>>n;
	int arr[n+100];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	buildbinaryheap(arr,n); 
	int k,x;
	cin>>k;
	int y=n;
	for(int i=0;i<k;i++)
	{
		x=extractmin(arr,y);
		y--;
	}
	cout<<x;
	return 0;
}
