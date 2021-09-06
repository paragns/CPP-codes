#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int k;
	cin>>k;
	int n;
	cin>>n;
	vector<vector<int>>pat(n);
	vector<int>p(n);
	for(int i=0;i<n;i++){
		int x;cin>>x;
		p[i]=x;
		pat[i]={x,i+1};
	}
	
	sort(p.begin(),p.end());
	sort(pat.begin(),pat.end(), greater<vector<int>>());
	
	set<int>s;
	vector<int>A(100001,0);
	for(int i=0;i<pat.size();i++){
		s.insert(pat[i][1]);
		if(s.size()>k)s.erase(--s.end());
		if(s.size()==k)A[pat[i][0]]=*(s.rbegin());
		//cout<<pat[i][0]<<"->";
		//for(auto ele:s)cout<<ele<<" ";
		//cout<<endl;
	}		
	int q;cin>>q;
	vector<int>arr(q);
	for(int i=0;i<q;i++){
		int x;cin>>x;
		x=*(lower_bound(p.begin(),p.end(),x));
		//if(A[x]==0)cout<<0<<'\n';
		 cout<<A[x]<<'\n';
	}

return 0;
}
