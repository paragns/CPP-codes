#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
bool check(string &A, string &B){
	int i=0;
	while(i<A.size() and B.size()){
		if(B[0]==A[i])B=B.substr(1);
		i++;
	}
//	cout<<B.size();
	if(B.size())return 0;
	else return 1;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	 while(t--){
	 	string S,t;
	 	cin>>S>>t;
	 	int n;
	 	cin>>n;
	 	vector<int>A(n);
	 	for(int i=0;i<n;i++)cin>>A[i];
	 	
	 	int high=n,low=-1;
	 	while(low<high){
		 	int mid=high-(high-low)/2;
		 	string p=S,q=t;
		 	for(int i=0;i<=mid;i++){
			 	p[A[i]-1]='*';
			 }
			 if(check(p,q))low=mid;
			 else high=mid-1;
			 //cout<<p<<" "<<q<<" "<<" "<<mid<<" "<<high<<" "<<low<< endl;
			 
		 }
		 
	 	cout<<low+1;
	 	
	 }
return 0;
}
