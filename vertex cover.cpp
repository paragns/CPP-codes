#include<bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(int i, vector<int> &state, vector<bool> &visited, map<int , vector<int>> &city){
	bool hosp_req=false;
	visited[i]=true;
	if(city[i].size()==1 && i!=1) return;
	
	for(auto edge:city[i]){
		if(visited[edge]) continue;
		dfs(edge, state, visited, city);
		
		if(state[edge]==0){
			 state[i]=2;
		}
		else if(state[edge]==2 and state[i]!=2 ){
			state[i]=1;
		}
	}
	if(i==1 && state[1]==0){
		state[i]=2;
	}
	
	return ;
}
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int i, n, e;
    cin>>n>>e;
    map<int , vector<int>> city;
 	for(i=0;i<e;i++){
 		int temp1, temp2;
		cin>>temp1>>temp2;
		city[temp1].push_back(temp2);
		city[temp2].push_back(temp1);	
	}
	vector<int> state(n+1,0);
	vector<bool> visited(n+1, false);
	
	dfs(1, state, visited, city);
	int ans=0;
	for(i=1;i<=n;i++){
		if(state[i]==2) ans++;
	}
	cout<<ans;
	return 0;
}
