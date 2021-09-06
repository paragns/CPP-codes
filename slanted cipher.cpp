#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int m=s.size()/n;
vector<vector<char>> v(n,vector<char>(m));
	int ind=0;//strring traversal
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[ind]=='_')s[ind]=' ';
			v[i][j]=s[ind];
			ind++;
		}
	}
	string ans="";
	int i=0,j=0, nexti=0,nextj=1;
	while(i<n and j<m){
		ans+=v[i][j];
		i++;j++;
		if(i>=n or j>=m)i=nexti, j=nextj, nextj++;
	} 
	 cout<<ans;
	//00 11 22 01 12 23 02 13 24 03 14 25
}
// 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	solve();
	}
	
	
return 0;
}
