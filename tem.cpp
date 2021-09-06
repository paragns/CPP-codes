#include <bits/stdc++.h>
using namespace std;
unordered_set<string>s;
	int n;
int dp[1001][1001][4];	
void func(string &A,int pos, int y,int curr,t){
		if(curr==y);
		if(pos==A.size() or curr>n or curr<0)return;
	int k;
	A[pos]=='r'? k=1:k=-1;
	func(A,pos+1,y,curr+k,t);
	func(A,pos+1,y,curr,t);
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string A;
	cin>>A;
    
	cin>>n;
	int x,y;
	cin>>x>>y;
	
	for(int len=1;len<A.size();len++){
	   		int k=0;
	   		string t="";
	   		
	   		for(int i=0;i<len;i++){t+=A[i]; A[i]=='r' k++:}
		   func(A,i+1,y,x+k,t);	
	}
	int t;
	x==y?t=1:t=0;
//	for(auto i:s)cout<<i<<endl;
	cout<<s.size()+t;
return 0;
}
