#include<bits/stdc++.h>
using namespace std;
#define N 1000001
#define int long long
#define ld long double

bool check2(double mid , int u, vector<int>&A, int n){
	long double lim=u+1,sum=0;
	for(int i=0;i<A.size();i++){
		sum+=(A[i]+mid)*(A[i]+mid)*(A[i]+mid);
		if(sum>lim)return 0;
	}
	return 1;
bool check(int mid, int u, vector<int>&A, int n){
	int sum=0;
	for(int i=0;i<A.size();i++){
		sum+=(A[i]+mid)*(A[i]+mid)*(A[i]+mid);
		if(sum>u)return 0;
	}
	return 1;
}
}
ld func(int n, int u, vector<int>&A){
	int low=0, high=1e5,mid;
	while(low<high){
			int mid=high-(high-low)/2;
			if(check(mid,u,A,n))low=mid;
			else high=mid-1;
		}
		int sum=0,cnt=0;
		for(int i=0;i<n;i++)sum+=(A[i]+low)*(A[i]+low)*(A[i]+low);
		if(sum==u)return low;
		ld l=low,h=low+1,m;
		while(l<h and cnt<100){
			m=(h+l)/2;
			cnt++;
			if(check2(m,u,A,n))l=m;
			else h=m-0.001;
		}
		return m;
}
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	//cout<<fixed;
	//cout<<setprecision(2);
	int T;
	cin>>T;
	while(T--){
		int n,u;
		cin>>n>>u;
		//int sum=0;
		vector<int>A(n);
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		cout<<func(n,u,A);
		cout<<"\n";
	
	}
	return 0;
}
