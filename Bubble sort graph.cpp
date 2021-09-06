#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	vector<int>A(n);
	for(int i=0;i<n;i++)
		cin>>A[i];
	
	set<int>s;
	for(int i=0;i<n;i++){
		s.insert(A[i]);
		auto x=s.upper_bound(A[i]);
		if(x!=s.end())s.erase(x);
	}
	cout<<s.size();
return 0;
}
