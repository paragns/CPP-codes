#include <bits/stdc++.h>
using namespace std;


int main()
{
		ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;

	vector<int> a(n);
	for(int i=0;i<n;i++)
	cin>> a[i];
		
int s=-1,e=-1;
vector<int>A=a;
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();i++){
		if(A[i]!=a[i] and s==-1)s=i;
		if(A[i]!=a[i] and s!=-1)e=i;
	}
	if(s==-1)cout<<0;
	else cout<<e-s+1;
	return 0;
}
