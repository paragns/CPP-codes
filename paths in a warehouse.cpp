#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int r,c;
bool safe(int x, int y, auto &A){
	if(x>=0 and x<r and y>=0 and y<c and A[x][y]!=0)return 1;
	else return 0;
}
ll int func(int x, int y, auto &A, auto &ans){
	if(x==r-1 and y==c-1 ){
		if(A[x][y]!=0)return ans[x][y]=1;
		else return -1;
	}
	if(!safe(x,y,A))return -1;
	if(ans[x][y]!=0)return ans[x][y]%mod;
	ll int l=func(x+1,y,A,ans);
	ll int r=func(x,y+1,A,ans);
	if(l==-1 and r==-1)return ans[x][y]=-1;
	else if(l==-1)return ans[x][y]=r%mod;
	else if(r==-1)return ans[x][y]=l%mod;
	else return ans[x][y]=(l+r)%mod;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){ 	
	 	cin>>r>>c;
	 	vector<vector<int>>A(r,vector<int>(c,0));
	 	
	 	for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)cin>>A[i][j];
		}
		if(A[0][0]==0){cout<<0;return 0;}
		vector<vector<ll int>>ans(r,vector<ll int>(c,0));
		cout<<max((ll int)0,func(0,0,A,ans));
		
	}
	
	
return 0;
}
