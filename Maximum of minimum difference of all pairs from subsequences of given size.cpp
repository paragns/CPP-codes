#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int check(int mid, vector<int>&A, int k){
	int last=0,cnt=0,s;
	for(int i=0;i<A.size();i++){
		s=A[i]-A[last];
		if(s>=mid){cnt++; last=i;}
	}
	if(cnt+1>=k)return 1;// cnt +1 since no of elements will be cnt+1;
	else return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	int n; cin>>n;
	 	vector<int>A(n);
	 	int mine=inf, maxe=minf;
	 	for(int i=0;i<n;i++){cin>>A[i];mine=min(mine,A[i]); maxe=max(maxe,A[i]);}
	 	
	 	int k; cin>>k;
	 	int low=0, high=maxe;
	 	while(low<high){
	 	//	cout<<low<<" "<<high;
		 	int mid=high-(high-low)/2;
		 	if(check(mid,A,k))low=mid;
		 	else high=mid-1;
		 }
		 cout<<low;
	 }
	
	
return 0;
}
