#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN

int func(string &A, int x, int y){
	if(x>y)return 0;
	if(x==y)return 1;
	if(A[x]==A[y])return func(A,x+1,y-1);
	int p=1+func(A,x+1,y-1);
	int q=min(1+func(A,x+1,y),1+func(A,x,y-1));
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
	 	cout<<func(A,0,n-1);
	}
return 0;
}
//xxyy


