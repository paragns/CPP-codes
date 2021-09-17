#include <bits/stdc++.h>
using namespace std;
#define ll long long
  bool comp(string a,string b){
  	string ab=a+b;
  	string ba=b+a;
  	if(ab>ba)return 1;
  	else return 0;
  }
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string>p(n);
    for(int i=0;i<n;i++){
    	ll int k;
    	cin>>k;
    		p[i]=to_string(k);
	}
	sort(p.begin(),p.end(),comp);
	
	for(int i=0;i<p.size();i++)
	for(int j=0;j<p[i].size();j++){
		cout<<p[i][j]-'0';
	}
return 0;
}
