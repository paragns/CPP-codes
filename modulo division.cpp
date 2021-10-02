#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int power(int a, int b,int m){
	if(b==1)return a;
	int st=power(a,b/2,m)%m;
	if(b%2==1)return (a%m*(st*st)%m)%m;
	else return (st*st)%m;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	cin>>T;
	 while(T--){
	 	//(a/b)mod m
	 	int a,b,m;
	 	cin>>a>>b>>m;
	 	if(__gcd(b,m)!=1)cout<<"not defined"<<'\n';
	 	else {
		 		int b_inv=power(b,m-2,m);
		 		cout<<((a%m) *(b_inv%m))%m<<'\n';
		 }
	 }
return 0;
}
