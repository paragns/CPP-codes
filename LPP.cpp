#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007

vector<int> LPS(string &pat){
	int n=pat.size();
	vector<int>lps(n,0);
	for(int i=1;i<n;i++){
		int j=lps[i-1];
		while(j>0 and pat[i]!=pat[j]){
			j=lps[j-1];
		}
		if(pat[i]==pat[j])j++;
		
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
	 	
	 	string A;
	 	cin>>A;
	 	string t= A;
	 	reverse(t.begin(),t.end());
	 	t=A+t;
		vector<int>lps=LPS(t);
		//for(int i:lps)cout<<i<<" ";
	 	int x=lps[lps.size()-1];
		if(x>=A.size())cout<<A;
		else {
			t=A.substr(x);
			reverse(t.begin(),t.end());
			cout<<t+A;
	 	}
	}
return 0;
}
// abbbba 

