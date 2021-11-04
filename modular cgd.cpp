#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll int power(ll int a,ll int b,ll int d){
	if(b==1)return a;
	ll int st=power(a,b/2,d)%d;
	if(b%2){
		return ((((st%d)*(st%d))%d)*a)%d;
	}
	return ((st%d)*(st%d))%d;
}
ll int gcd(ll int a, ll int b, ll int c, ll int n){
	if (c == 0)return (power(a,n,mod)+power(b,n,mod))%mod;
	ll int ans=1;
	for(ll int i=1;i<1000001;i++){
		if(c%i==0){
			//cout<<i<<endl;
			if((power(a,n,i)+power(b,n,i))%i==0)ans=max(i,ans);
			ll int num=c/i;
			if((power(a,n,num)+power(b,n,num))%num ==0)ans=max(ans,num);
		}
	}	
	return ans;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		ll int a,b,n;
		cin>>a>>b>>n;
		ll int C=abs(a-b);
		//cout<<A<<" "<<B<<" "<<C<<endl;
		cout<< gcd(a,b,C,n)<<'\n';
	}
	return 0;
}
