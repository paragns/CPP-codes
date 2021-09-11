#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
 while(T--){
 	int n; cin>>n;
    vector<string> A(n);
    for (int i = 0; i < n; i++) {
        cin>>A[i];
    }
	unordered_map<string, int>mp,mp1; //mp1 stores prefixes;
	for(int i=0;i<n;i++){
	    string t="";
	    if(mp1[A[i]]){
	        cout<<"BAD SET"<<"\n"; 
	            for(int k=0;k<A[i].size();k++) cout<<A[i][k];
	            cout<<endl;
	            return 0;
	    }
	    for(int j=0;j<A[i].size();j++){
	        t.push_back(A[i][j]);
	        if(mp[t]){
	            cout<<"BAD SET"<<"\n"; 
	            for(int k=0;k<A[i].size();k++) cout<<A[i][k];
	            cout<<endl;
	            //for(int k=0;k<t.size();k++) cout<<t[k];
	            return 0;}
	        mp1[t]++;    
	    }
	    
	    mp[A[i]]++;
	}
cout<<"GOOD SET";
return 0;
}
return 0;
}
