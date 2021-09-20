
#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	int n; cin>>n;
	 	vector<vector<ll int>> A(n,vector<ll int>(2));
	 	for(int i=0;i<n;i++){
			cin>>A[i][0]; 
		}
	 	cin>>n;
	 	for(int i=0;i<n;i++){
			cin>>A[i][1]; 
		}
	 	ll int time=0;
	 	queue<ll int>exit, enter;
	 	int i=0,prev=-1;
		vector<ll int>ans(n,-1);
	 	while(1){
	 		if(i>=n and exit.empty() and enter.empty())break;
			while(i<n and A[i][0]==time ){
				if(A[i][1]==1)exit.push(i);
				else if(A[i][1]==0)enter.push(i);
				i++;
			}
			    if(exit.empty() and !enter.empty()){ans[enter.front()]=time; enter.pop(); prev=0;}
				else if(!exit.empty() and enter.empty()){ans[exit.front()]=time; exit.pop(); prev=1;}
				else if(exit.empty() and enter.empty()){time=A[i][0];prev=-1;continue;}
				else if(prev==-1 or prev==1){
					ans[exit.front()]=time; exit.pop(); prev=1;	
				}
				else if(prev==0){ans[enter.front()]=time; enter.pop(); prev=0;}
				
				time++;
				
		}
		for(auto i:ans)cout<<i<<'\n';
	 }
return 0;
}
