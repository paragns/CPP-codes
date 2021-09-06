#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX	
#define minf INT_MIN
int w,h,n,ans;
vector<vector<int>>office;
void func(int x, int y, auto &A, int n){
	if(n==0){
		int temp=-1;
		for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			int p=inf;
			for(auto v:office){
				p=min(p,abs(i-v[0])+abs(j-v[1]));
			}
			temp=max(temp,p);			
		}
		}
		ans=min(ans,temp);
		return;
	}
	if(y==w){
		x++;
		y=0;
	}
	
	if(x==h)return;
	A[x][y]=0; office.push_back({x,y});
	func(x,y+1,A,n-1);
	A[x][y]=-1; office.pop_back();
	func(x,y+1,A,n);
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	while(T--){
		cin>>w>>h>>n;
		ans=inf;
		vector<vector<int>>A(h,vector<int>(w,-1));
		func(0,0,A,n);
		cout<<ans;	
	}
return 0;
}
