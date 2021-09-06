#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
unordered_map<string, int>mp;
void func(int n, string &A, string &mask,string &temp){
	cout<<A<<endl;
	mp[A]++;
	for(int i=n-1;i>=0;i--){
		if(mask[i]=='0'){
			A[i]^=1;
			//cout<<A[i]<<" ";
			if(mp.find(A)==mp.end()){
				
				mask=temp;
				mask[i]='1';
				func(n,A,mask,temp);
				break;
			}
			else {
				A[i]^=1;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	 while(t--){
	 	int n;cin>>n;
	 	string A="";
	 	for(int i=0;i<n;i++)A+='0';
	 	string mask=A,temp=A;;
	 	func(n, A, mask,temp);
	 	
	 }
	
	
return 0;
}
