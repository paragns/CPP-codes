#include <bits/stdc++.h>
using namespace std;
 
// Driver code
int main()
{
	int n,m;
	cin >>n>>m;
	vector<int>A(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
map<int,int>mp;
vector<long long int>indx(n,0);
	for(int i=0;i<m;i++){
		int l,m;
		cin>>l>>m;
		
		l--;m--;
		indx[l]++;
		if(m+1<n)indx[m+1]--;
	}
	int su=0;
	for(int i=0;i<n;i++){
		su+=indx[i];
		indx[i]=su;
	}
	sort(indx.begin(),indx.end(),greater<int>());
	sort(A.begin(),A.end(),greater<int>());
	
	long long int sum=0;
	for(int i=0;i<n;i++){
	sum+=A[i]*indx[i];	
	}
	cout<<sum;
	
return 0;
}
