#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN

int func(string &A, int x, int y,int inter){
	int n=A.size();
	if(x>=inter and y>=n)return 0;
	if(x>=inter)return (n-y);
	if(y>=n)return (inter-x);
	//if(x==y)return 1;
	if(A[x]==A[y])return func(A,x+1,y+1,inter);
	int p=1+func(A,x+1,y+1,inter);
	int q=min(1+func(A,x+1,y,inter),1+func(A,x,y+1,inter));
	return min(p,q);
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	
		 string A;
	 	cin>>A;
	 	int n=A.size();
	 	int ans=inf;
	 	for(int i=n/2-1;i<=n/2+1;i++){
			ans=min(ans,func(A,0,i,i));
		}
		cout<<ans;
	}
return 0;
}
//xeeyxy


