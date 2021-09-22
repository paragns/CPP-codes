#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){ 	
	 	int n; cin>>n;
	 	int t=1;
	 	vector<int>pref(n+1);
	 	pref[0]=0;
	 	for(int i=1;i<=n;i++){
		 	string A;
		 	cin>>A;
		 	if(A[A.size()-1]=='a' or A[A.size()-1]=='e' or A[A.size()-1]=='i' or A[A.size()-1]=='o' or A[A.size()-1]=='u' ){
			 	if(A[0]=='a' or A[0]=='e' or A[0]=='i' or A[0]=='o' or A[0]=='u' ){
				  pref[i]=1;
				 }
			 }
		 }
		 ll int sum=0;
		 for(int i=1;i<=n;i++){
		 	sum+=pref[i];
		 	pref[i]=sum;
		 }
		// for(int i:pref)cout<<i<<" ";
		int q; cin>>q;
		for(int i=0;i<q;i++){
			string A;
			cin>>A;
			int a=0,b=0;
			int j=0;
			while(A[j]!='-'){
				a=a*10+(A[j]-'0');
				j++;
			}
			j++;
			while(j!=A.size()){
				b=b*10+(A[j]-'0');
				j++;
			}
			//cout<<a<<" "<<b;
			cout<<pref[b]-pref[a-1]<<'\n';
		}
	}
return 0;
}
