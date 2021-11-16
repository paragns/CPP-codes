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
	cin>>T;
	 while(T--){
	 	int k,b;
	 	cin>>k>>b;
	 	int n;
	 	cin>>n;
	 	vector<int>W(n);
	 	for(int i=0;i<n;i++){
			 cin>>W[i];
		}
		int m; cin>>m;
		vector<int>S(m);
		for(int i=0;i<m;i++){
			cin>>S[i];
		}
		sort(W.begin(), W.end());
		sort(S.begin(), S.end());
		int j=0,cnt=0;
		for(int i=0;i<n;i++){
			if(S[j]<=W[i]){
				S[j]=-1;
				W[i]=-1;
				cnt++;
				j++;
			}
		}
		vector<int>w,s;
		for(int i=0;i<n;i++){
			if(W[i]!=-1)w.push_back(W[i]);
		}
		for(int i=0;i<m;i++){
			if(S[i]!=-1)s.push_back(S[i]);
		}
		multiset<vector<int>>st;
		for(int i=0;i<w.size();i++){
			int ind=lower_bound(s.begin(),s.end(),w[i])-s.begin();
			if(ind!=w.size())st.insert({s[ind]-w[i], ind});
			if(ind!=0)st.insert({s[ind-1]-w[i],ind-1});
		}
		//for(auto i:st)cout<<i[0]<<" "<<i[1]<<endl;
		//cout<<cnt<<"*"<<endl;
		while(k and s.size()){
			auto v=*(st.begin());
			st.erase(st.begin());
			int l=v[0], ind=v[1];
			if(l%b==0)k-=(l/b);
			else k-=((l/b)-1);
			if(k<0)break;
			cnt++;
		}
		cout<<cnt<<'\n';
	}
return 0;
}
