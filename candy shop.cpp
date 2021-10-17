#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
const int N=100001;
vector<ll int>fenwick;
void update(ll int x,ll int val){     
	for(x; x < N; x += x&-x){
		fenwick[x] += val;
	}
}
ll int query( ll int x){
	ll int sum = 0;
	for(x; x > 0; x -= x&-x)
	sum += fenwick[x];
	return sum;
}  
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fenwick.resize(N,0);
    vector<ll int>temp=fenwick;
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	ll int n,q;
	 	cin>>n>>q;
	 	vector< int>A(n),B(n);
	 	for(int i=0;i<n;i++)cin>>A[i];
	 	for(int i=0;i<n;i++)cin>>B[i];
	 	vector<vector< int>>que(q),s,e;
	 	for(int i=0;i<q;i++){
			int t; cin>>t;
			if(t==1){
				int l,r,k;
				cin>>l>>r>>k;
				l--;r--;
				que[i]={t,l,r,k};
				s.push_back({l,i,k});
				e.push_back({r,i,k});
			}
			else{
				int in,u;
				cin>>in>>u;
				in--;
				que[i]={t,in,u};
			} 
		}
		sort(s.begin(),s.end());
	 	sort(e.begin(),e.end());
	 	vector<int>ans(q);
	 	int j=0;
	 	for(int i=0;i<n;i++){
			while(j<s.size() and s[j][0]==i){
//			 cout<<"*";
			 ans[s[j][1]]-=query(s[j][2]);
//			 cout<<ans[s[j][1]]<<" ";
			 j++;
			}
			update(A[i],B[i]);
		}
		fenwick=temp;
		j=0;
		for(int i=0;i<n;i++){
			update(A[i],B[i]);
			while(j<e.size() and e[j][0]==i){
			 ans[e[j][1]]+=query(e[j][2]);
//			  cout<<ans[e[j][1]]<<" ";
			 j++;
			}
		}
		map<int, int>mp;
		for(int i=0;i<q;i++){
			if(que[i].size()==3){
				if(que[i][2]==0){
					mp[que[i][1]]=1;
				}
				else mp.erase(que[i][1]);
			}
			else{
				int l=que[i][1],r=que[i][2],k=que[i][3];
				auto it1=mp.lower_bound(l);
				auto it2=mp.upper_bound(r);
				while(it1!=it2){
					//cout<<it1->first<<" ";
					if(A[it1->first]<=k)ans[i]-=B[it1->first];
					it1++;
				}
				cout<<ans[i]<<endl;
			}
		}
	}
return 0;
}
