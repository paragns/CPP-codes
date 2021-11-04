#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
bool safe(int x,int y ,int n, int m){
	if(x>=0 and y>=0 and x<n and y<m)return 1;
	else return 0;
}
bool same(vector<int>A, int x, int y){
	if(A[0]==x and A[1]==y )return 1;
	else return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	 while(t--){
		int n,m;
		cin>>n>>m;
		vector<vector<int>>A(n,vector<int>(m,0));	
	 	for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)cin>>A[i][j]; 
		}
	 	int q; cin>>q;
	 	map<vector<int>, vector<vector<int>>>mp;
	 	for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int ele=A[i][j];
				for(int k=0;k<n;k++){
					for(int l=0;l<m;l++){
						if(k==i and l==j)continue;
						if(ele%A[k][l]==0)mp[{i,j}].push_back({k,l});
					}
				}
			} 
		}
	 	for(int i=0;i<q;i++){
			int x,y,x2,y2;
			cin>>x>>y>>x2>>y2;
			x--,y--;x2--,y2--;
			 queue<vector<int>>q;
			 q.push({x,y});
			 int cnt=4;
			 while(cnt--){
			 	int sz=q.size();
				 while(sz--){
				 	auto top=q.front();
				 	int x1=top[0],y1=top[1];
				 	q.pop();
				 	if(safe(x1+1,y1,n,m)){q.push({x1+1,y1});if(same({x1+1,y1},x2,y2))cout<<"YES"<<"\n";break;}
				 	if(safe(x1,y1+1,n,m)){q.push({x1,y1+1});if(same({x1,y1+1},x2,y2))cout<<"YES"<<"\n";break;}
				 	if(safe(x1-1,y1,n,m)){q.push({x1-1,y1});if(same({x1-1,y1},x2,y2))cout<<"YES"<<"\n";break;}
				 	if(safe(x1,y1-1,n,m)){q.push({x1,y1-1});if(same({x1,y1-1},x2,y2))cout<<"YES"<<"\n";break;}
				 	for(auto j:mp[{x1,y1}]){
						if(same(j,x2,y2)){cout<<"YES"<<"\n";break;}
						q.push(j); 
					}
				}
			 }
			 if(!q.size())cout<<"NO"<<"\n";
		}
	 }
return 0;
}
