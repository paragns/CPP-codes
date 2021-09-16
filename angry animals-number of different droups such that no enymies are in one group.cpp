#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n;
	cin>>n;
	long long int i, m;
	cin>>m;
	vector<long long int> a(m);
	for(i=0;i<m;i++){
		cin>>a[i];
	}
	cin>>m;
	vector<long long int> b(m);
	for(i=0;i<m;i++){
		cin>>b[i];
	}
	vector<long long int> conflict(n+1, n+1);
	for(i=0;i<m;i++){
		if(a[i]<b[i]){
			 conflict[a[i]]=min(conflict[a[i]], b[i]);
		}
		else{
			 conflict[b[i]]=min(conflict[b[i]], a[i]);
		}
	}
	vector<long long int> safe(n+1, n+1);
	for(i=n-1;i>0;i--){
		safe[i]=min(safe[i+1], conflict[i]);
	}
	
	//for(int i=0;i<conflict.size();i++)cout<<i<<"->"<<conflict[i]<<" ";
	//cout<<endl;
	//for(int i=0;i<safe.size();i++)cout<<i<<"->"<<safe[i]<<" ";
	
	long long int ans=0;
	for(i=1;i<=n;i++){
		ans+=safe[i]-i;
	}
	cout<<ans;
	return 0;
}
