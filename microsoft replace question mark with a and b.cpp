#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int func(string &A,int pos,char pprev, char prev ){
	if(pos>=A.size())return 1;
	if(A[pos]==prev and A[pos]==pprev)return 0;
	if(A[pos]!='?'){
		if(A[pos]==prev and A[pos]==pprev)return 0;
		return func(A,pos+1,prev,A[pos]);
	}
	
	int l=0,r=0;
	if(A[pos]=='?' and (pprev!='a' or prev!='a')) l=func(A,pos+1,prev,'a');
	if(A[pos]=='?' and (pprev!='b' or prev!='b')) r=func(A,pos+1,prev,'b');
	return l+r; 
	
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	string A;
	 	cin>>A;
	 	cout<<func(A,0,'-1','-1');
	}
return 0;
}
