
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
int main(){
	
	vector<ll>a={3,1,2,3,2,3,4};
	int n= a.size();
    	
	vector<ll> right(n);
	stack<ll> st;

	for(ll i=n-1;i>=0;i--){
		while(!st.empty() and a[st.top()]<=a[i]){
			st.pop();
		}
		if(!st.empty()){
			right[i]=st.top()-i;
		}
		else{
			right[i]=n-i;
		}
		st.push(i);
	}
	vector<ll> left(n);
    stack<ll> pt;
    st=pt;
	for(ll i=0;i<n;i++){
			while(!st.empty() and a[st.top()]<a[i]){
			st.pop();
		}
		if(!st.empty()){
			left[i]=-st.top()+i;
		}
		else{
			left[i]=i+1;
		}
		st.push(i);
	}
        for(int i=0;i<left.size();i++){
        	cout<<left[i]<<" ";
		}
		cout<<endl;
		for(int i=0;i<left.size();i++){
        	cout<<right[i]<<" ";
		}
		cout<<endl;
			int freq[n];
			for(int i=0;i<n;i++){
				freq[i]=left[i]*right[i];
				cout<<freq[i]<<" ";
				
			}
return 0;
}
/*



*/
