#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
vector<int>LPS(string &A){
	int n=A.size();
	vector<int>lps(n,0);
	for(int i=1;i<n;i++){
		int j=lps[i-1];
		while(j>0 and A[j]!=A[i])j=lps[j-1];
			if(A[j]==A[i])j++;
			lps[i]=j;
	}
	return lps;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	string A,B;
	 	cin>>A>>B;
	 	B=B+B;
		int n=A.size();
//		cout<<"*";
		vector<int >lps=LPS(A);
		string txt=B, pat=A;
		int j=0,i=0;
		int maxmat=0,minrot=inf;
		int cnt=0;
		while(i<txt.size()){
			while(i<txt.size() and j<pat.size() and txt[i]==pat[j]){
				j++;
				cnt++;
				i++;
			}
			if(cnt>=maxmat){
				if(cnt>maxmat){
					minrot=min(j-maxmat,n-j+maxmat);
				}
				if(cnt==maxmat){
					int t=min(j-maxmat,n-j+maxmat);
					minrot=min(minrot,t);
				}
			}
			if(j!=0)j=lps[j-1];
			else i++;
			cnt=j;
		}
		cout<<minrot;
	}
	
return 0;
}
