#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int check(int mid,vector<int> &B,vector<int>&T){
	int j=0;
	for(int i=0;i<T.size();i++){
		int sum=0,time=0;
		while(j<B.size() and time<mid){
			if(B[j]>T[i])break;
			time+=2;
			j++;
		
		}
	}
	if(j==B.size())return 1;
	else return 0;
}
//7 6 5 4 3
//10 3
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 int n,m; cin>>n>>m;
	 vector<int>truck(m);
	 vector<int> box(n);
	 for(int i=0;i<n;i++)cin>>box[i];	
	 for(int i=0;i<m;i++)cin>>truck[i];
	 sort(box.begin(),box.end());
	 	sort(truck.begin(),truck.end()); 
	 	int low=0,high=2*n;
	 	while(low<high){
		 	int mid=low+(high-low)/2;
		 	//cout<<high<<
			 if(check(mid,box,truck))high=mid;
		 	else low=mid+1;
		 }
		 cout<< high;
	 }
	
	
return 0;
}
