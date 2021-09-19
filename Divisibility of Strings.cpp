#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007

vector<int> LPS(string &pat){
	int n=pat.size();
	vector<int>lps(n,0);
	for(int i=1;i<n;i++){
		int j=lps[i-1];
		while(j>0 and pat[j]!=pat[i]){
			j=lps[j-1];
		}
		
		if(pat[j]==pat[i])j++;
		lps[i]=j;
	}
	return lps;
	
}
  
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	 while(t--){
	 	string A,B;
	 	cin>>A>>B;
	 	int i=0,j=0,flag=0;
	 	int m=B.size();
	 	
	 	while(i<A.size()){
			 if(A[i]!=B[j%m]){flag=1; break;}
			 i++;
			 j++;
		 }
	
	 	if(flag or j%m!=0 )cout<<-1;
	 else{
	 	vector<int>lps=LPS(B);
		 A=B;
		 B=B.substr(0,m-lps[m-1]);
		 int i=0,j=0,flag=0;
	 	 int x=B.size();
	 	while(i<A.size()){
			 if(A[i]!=B[j%x]){flag=1; break;}
			 i++;
			 j++;
		 }
	 	if(flag or j%x!=0 )cout<<A.size();
	 else cout<<m-lps[m-1];
	 }
	 }
return 0;
}
/*
aaaa
0123

bcdbcd
000123

abcda
00001

ababab
001234

*/
