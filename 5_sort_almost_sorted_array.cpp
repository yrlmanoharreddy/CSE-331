#include <bits/stdc++.h> 
using namespace std; 

int sortK(int arr[], int n, int k) 
{ 
	priority_queue<int, vector<int>, greater<int> > pq; 
    
    for(int i=0;i<=k;i++)
        pq.push(arr[i]);
        
	int index = 0; 
	for (int i = k + 1; i < n; i++) { 
		arr[index++] = pq.top(); 
		pq.pop(); 
		pq.push(arr[i]); 
	} 

	while (pq.empty() == false) { 
		arr[index++] = pq.top(); 
		pq.pop(); 
	} 
} 

void printArray(int arr[], int size) 
{ 
	for (int i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 
 
int main() 
{ 
	int n,k;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>k;
	sortK(arr, n, k); 
	printArray(arr, n); 
	return 0; 
} 

