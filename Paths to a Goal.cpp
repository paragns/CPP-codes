#include <bits/stdc++.h>
using namespace std;

int mod=1000000007, target, lim;
string s;
vector<vector<vector<int>>> dp;
int recurse(int pos, int curr, int state){
	int n=s.size();
	if(curr<0 || curr>lim)return 0;
	if(pos==n && curr==target)return 1;
	if(pos==n)return 0;
	if(dp[pos][curr][state]!=-1) return dp[pos][curr][state];
	if(state==0){
		//state 0: 'l' ignored
		if(s[pos]=='r'){
			dp[pos][curr][state]=(recurse(pos+1, curr+1, 3)%mod+recurse(pos+1, curr, 2)%mod)%mod;
		}
		else{
			dp[pos][curr][state]=recurse(pos+1, curr, 0)%mod;
		}
	}
	else if(state==1){
		//state 1: 'r' ignored
		if(s[pos]=='r'){
			dp[pos][curr][state]=recurse(pos+1, curr, 1)%mod;
		}
		else{
			dp[pos][curr][state]=(recurse(pos+1, curr-1, 3)%mod+recurse(pos+1, curr,2 )%mod)%mod;
		}
	}
	else if(state==2){
		//state 2: both 'l' and 'r' ignored
			dp[pos][curr][state]=recurse(pos+1, curr, 2)%mod;
	}
	else if(state==3){
		//state 3: none ignored
		if(s[pos]=='r'){
			dp[pos][curr][state]=(recurse(pos+1, curr+1, 3)%mod+recurse(pos+1, curr, 1)%mod)%mod;
		}
		else{
			dp[pos][curr][state]=(recurse(pos+1, curr-1, 3)%mod+recurse(pos+1, curr, 0)%mod)%mod;
		}
	}
	return dp[pos][curr][state];
}

int main(){
	cin>>s;
	int n=s.size();
	int start;
	cin>>lim;
	cin>>start>>target;
	dp.resize(n+1, vector<vector<int>>(lim+1, vector<int>(4, -1)));
	cout<<recurse(0,start,3)<<endl;
	return 0;
}

