#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007
# define ll long long
int k;
int func( int tot, int r, int b,int lr, int lb ){
	if(r+b==0)return 1;
	int x=0;
	if(r>0 and lr>0)x=func(tot-1,r-1,b,lr-1,k);
	int y=0;
	if(b>0 and lb>0)y=func(tot-1,r,b-1,k,lb-1);
	return (x+y)%mod;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	
	int a,b;
	cin>>a>>b>>k;
	cout<<func(a+b,a,b,k,k);
	cout<<endl;
	//cout<<ans[a+b];
	}
return 0;
}
