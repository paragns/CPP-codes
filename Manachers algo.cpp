#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
// https://cp-algorithms.com/string/manacher.html
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	string A;
	 	cin>>A;
	 	int n=A.size();
	 	vector<int>odd(n);
	 	// for odd length palindrome
		 int l=0,r=-1;
	 	for(int i=0;i<n;i++){
			 int k= (i>r)? 1:min(odd[l+r-i],r-i+1);
			 while(i-k>=0 and i+k<n and A[i-k]==A[i+k]){
			 	k++;
			 }
			 odd[i]=2*k-1;
			 k--;
			 if(i+k>r){
			 	l=i-k; 
			 	r=i+k;
			 }
		}
		cout<<"odd length pali: ";
		for(int i:odd)cout<<i<<" ";
		cout<<endl;
		//for even length palindrome
		l=0,r=-1;
		vector<int>even(n);
	 	for(int i=0;i<n;i++){
			 int k= (i>r)? 0:min(even[l+r-i+1],r-i+1);
			 while(i-k-1>=0 and i+k<n and A[i-k-1]==A[i+k]){
			 	k++;
			 }
			 
			 even[i]=2*k;
			 k--;
			 if(i+k>r){
			 	l=i-k-1; 
			 	r=i+k;
			 }
			 
		}
		cout<<"even length pali: ";
		for(int i:even)cout<<i<<" ";
	}
return 0;
}
