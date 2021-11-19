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
void heapSort(int arr[], int n) 
{  
	buildbinaryheap(arr,n); 

	for (int i=n-1; i>0; i--) 
	{ 
		swap(arr[0], arr[i]);
		heapify(0,arr, i); 
	} 
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
	heapSort(arr,n);
	for(int i=0;i<n-1;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
