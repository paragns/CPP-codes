#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int n,m;
bool safe(int x, int y){
	 if(x>=0 and x<n and y>=0 and y<m)return 1;
	 else return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	cin>>n>>m;
	 	vector<vector<int>>A(n,vector<int>(m,0));
	 	auto temp=A;
	 	int sum=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>A[i][j];
				sum+=A[i][j];
			} 
		}
		int ans=sum;
		vector<vector<int>>dir{{-1,0},{0,1},{1,0},{0,-1}};
		int dist=0;
		queue<vector<int>>q,q1;
		auto viz=temp;
		q.push({0,0});
		while(!q.empty()){
			int flag=0;
			int sz=q.size();
			if(sum==0)break;
			while(sz--){
				auto v=q.front();
				q.pop();
				int x=v[0], y=v[1];
				if(A[x][y]!=0){
					flag=1;
					sum-=A[x][y];
					A[x][y]=0;
					viz=temp;
					q=q1;
					q.push({x,y});
					viz[x][y]=1;
					break;
				}
				for(int i=0;i<4;i++){
					int cx=dir[i][0]+x;
					int cy=dir[i][1]+y;
					if(safe(cx,cy)){
						if(!viz[cx][cy]){
							q.push({cx,cy});
							viz[cx][cy]=1;
						}
					}
				}
			}
			if(!flag)dist++;
		}
		ans+=(2*dist);
		cout<<ans;
	}
	
return 0;
}
