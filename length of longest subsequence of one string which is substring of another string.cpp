#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int n, m;
int func(string &A, string &B, int x, int y ){
	if(x>=n or y>=m)return 0;
	if(A[x]==B[y]){
		return 1+func(A,B,x+1, y+1);
	}
	 else   return func(A,B,x+1,y);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	string A,B; cin>>A>>B;
		cin>>n>>m;
		int ans=0;
		for(int i=0;i<m;i++){
		ans=max(ans,func(A,B,0,i));
		}
		cout<<ans;	 		
	 }
return 0;
}
