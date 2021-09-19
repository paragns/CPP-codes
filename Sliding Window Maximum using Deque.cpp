#include <bits/stdc++.h>
using namespace std;
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	
	deque<int>q;
	q.push_back(0);
	
	for(int i=1;i<k;i++){
		while(!q.empty() and a[q.back()]<a[i] )	q.pop_back();
			q.push_back(i); 
			   
	}
	cout<<a[q.front()]<<" ";
	
	for(int i=k;i<n;i++){
		if(i-k==q.front())q.pop_front();
		
		while(!q.empty() and a[q.back()]<a[i] )	q.pop_back();
		
		q.push_back(i);
		cout<<a[q.front()]<<" ";
	}
	
	
	
return 0;
}
