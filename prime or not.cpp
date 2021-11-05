#include<bits/stdc++.h>
#define int long long
using namespace std;
int multi(int a , int b, int c){
	int x=0,y=a%c;
	while(b>0){
		if(b%2){
			x=(x+y)%c;
		}
		int t=2;
		y=(t*y)%c;
		b/=2;
	}
	return x%c;
}
int power(int a, int b, int mod){
	if(b==1)return a%mod;
	int st=power(a,b/2,mod)%mod;
	int d=(multi(st,st,mod))%mod;
	if(b%2==0){
		return d;
	}
	else return (multi(a,d,mod))%mod;
}
signed main(){
	int T;
	cin>>T;
	while(T--){
		int p; cin>>p;
		if(p<=4){
			 if(p==2 or p==3)cout<<"YES\n";
			 else cout<<"NO\n";
			 continue;
		}
		bool flag=0;
		for(int i=0;i<10;i++){
			int a=2+rand()%(p-2);
			if(power(a,p-1,p)!=1){
				cout<<"NO"<<"\n";
				flag=1;
				break;
			}
		}
		if(!flag)cout<<"YES"<<'\n';
	}
	return 0;
}
