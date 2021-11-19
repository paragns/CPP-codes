#include<bits/stdc++.h>
using namespace std;
#define N 1000001
#define int long long

vector<int>primes,spf(N,0);
void sieve(){
	for(int i=2;i<N;i++){
		if(spf[i]==0){
			primes.push_back(i);
			spf[i]=i;
		}
		for(int j=0;j<primes.size() and i*primes[j]<N; j++){
			spf[i*primes[j]]=primes[j];
		}
	}
}
int bin(int b, int e, int mod){
	int res=1;
	b%=mod;
	while(e){
		if(e&1){
			res=(res*b)%mod;
		}
		b=(b*b)%mod;
		e>>=1;
	}
	return res;
	
}
bool check(int n, int a, int d, int s){
	int x=bin(a,d,n);
	if(x==1 or x==n-1)return 0;
	for(int r=1;r<s;r++){
		x=(x*x)%n;
		if(x==n-1)return 0;
	}
	return 1;
}
bool func(int n){
	if(n<2)return 0;
	int r=0;
	int d=n-1;
	while((d&1)==1){
		d>>=1;
		r++;
	}
	for(int a:{2,3,5,7,11,13,17,19,23,29,31,37}){
		if(n==a)return 1;
		if(check(n,a,d,r))return 0;
	}
	return 1;
}
int give(int n,string &A){
	int i=A.size()-1;
	string p="";
	while(n){
		if(1&n)p+=A[i];
		i--;
		n=(n>>1);
	}
	reverse(p.begin(),p.end());
	int k=stoi(p);
	return k;
}
signed main(){
	sieve();
	string s;
	cin>>s;
	int n=s.size(),ans=0;
	for(int i=1;i<pow(2,n);i++){
		int l=give(i,s);
		//cout<<l<<endl;
		if(l<N ){
			if(spf[l]==l)ans++;
		}
		else if(func(l))ans++;
		
	}
	cout<<ans;
	return 0;
}
