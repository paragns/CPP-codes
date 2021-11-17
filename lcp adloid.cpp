#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<vector<int>>lcp(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>lcp[i][j];
			if(i+lcp[i][j]>n or j+lcp[i][j]<n){
				cout<<"Impossible";
				return 0;	
			}
		}
		
	}
	string ans="";
	for(int i=0;i<n;i++)ans+='@';
	ans[0]='a';
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
				int x=lcp[i][j];
				if(ans[i]=='@')ans[i]=(char)(ans[i-1]+1);
				if(ans[i]>'z')ans="Impossible";
				while(x--){
					ans[j]=ans[i];
				}
		}
		if(ans=="Impossible")break;
	}
	cout<< ans;
}
