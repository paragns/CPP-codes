#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<vector<int>>lcp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)cin>>A[i][j];
	}
	char curr='a';
	string ans="";
	for(int i=0;i<n;i++)ans+='@';
	for(int j=1;j<n;j++){
		for(int i=0;i<n;i++){
				int k=i+j;
				int x=lcp[i][k];
				if(x){
					char c=curr;
					if(ans[i]!='@')c=ans[i];
					while(x--){
						ans+=c;
						c= c+1;
					}
				}
		}
	}

}
