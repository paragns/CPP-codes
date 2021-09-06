#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN

string make(string A){
	multiset<string, greater<string>> s;
	int level=0;
	int j=0;
	for(int i=0;i<A.size();i++){
		if(A[i]=='1')level++;
		else level--;
	if(level==0){s.insert('1'+make(A.substr(j+1,i-j-1))+'0');j=i+1;}
	}
	string ans="";
	for(auto i:s)ans+=i;
	return ans;	
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	 while(t--){
	 	string A;
	 	cin>>A;
	 	cout<<make(A);
	 	
	 	
	 }
	
	
return 0;
}
