#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int func(int curr, int &n, int &p, int nad, int fed ){
	if(curr>=n)return 1;
	int l=0;
	if(nad>=(p*(fed +1))){l+=func(curr+1,n,p,nad,fed+1);};
	l+=func(curr+1,n,p,nad+1,fed);
	return l;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int mat,p; cin>>mat>>p;
	 	cout<<func(0,mat,p,0,0);
	}
return 0;
}
