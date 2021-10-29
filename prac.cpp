#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN


unordered_map<int, vector<vector<int>>>A,B;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
		 int n;
	 	 cin>>n;
	 	 unordered_map<string , int>city;
	 	vector<string>que;
	 	for(int i=0;i<n;i++){
		 	string t;
			 cin>>t;
			 city[t]=i;
		 }
	 	
	 	cin>>n;
	 	vector<int>X(n),Y(n);
	 	for(int i=0;i<n;i++){
			cin>>X[i]; 	
		}
	 	cin>>n;
	 	for(int i=0;i<n;i++)cin>>Y[i];
	 	
		for(int i=0;i<n;i++){
			A[X[i]].push_back({Y[i],i});
			A[Y[i]].push_back({X[i],i});
		}
	 	for(int i:A){
			sort(A[i.first].begin(),A[i.first].end());
			if(A[i.first].size()==1)continue;
			for(int j=0;j<A[i.first].size();j++){
				if(j==0)A[i.first][j].push_back(A[i.first][j+1][1]);
				else if(j==A[i.first].size()-1)A[i.first][j].push_back(A[i.first][j-1][1]);
				else{
					if(A[i.first][j]-A[i.first][j-1]<= A[i.first][j+1]-A[i.first][j])A[i.first][j].push_back(A[i.first][j-1][0])
				}
			} 
		}
		for(int i:B){
			sort(B[i.first].begin(),B[i.first].end()); 
			if(B[i.first].size()==1)continue;
			for(int j=0;j<B[i.first].size();j++){
				if(j==0)B[i.first][j].push_back(B[i.first][j+1][1]);
				else if(j==B[i.first].size()-1)B[i.first][j].push_back(B[i.first][j+1][1]);
			} 
		}
		cin>>n;
	 	for(int i=0;i<n;i++){
		 	cin>>que[i];
			int x=X[city[que[i]]];
			int y=Y[city[que[i]]];
			A[x]
		}
	 	
	 	
	}
return 0;
}
