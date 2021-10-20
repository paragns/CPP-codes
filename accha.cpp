#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
vector<int>LPS(string &A){
	int n=A.size();
	vector<int>lps(n,0);
	for(int i=1;i<n;i++){
		int j=lps[i-1];
		while(j>0 and A[j]!=A[i])j=lps[j-1];
			if(A[j]==A[i])j++;
			lps[i]=j;
	}
	return lps;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	cin>>T;
	 while(T--){
	 	string A,B;
	 	cin>>A;
		int n=A.size();
//		cout<<"*";
		vector<int >lps=LPS(A);
		int ans=n;
		for(int i=n-1;i>=0;i--){
				ans+=lps[i];
				if(lps[i]!=0)i-=lps[i]-1;	
		}
		cout<<ans;
	}
	
return 0;
}
