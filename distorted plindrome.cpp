#include <bits/stdc++.h>
using namespace std;

  
// Driver code
void swaps(string &A,int i,int j, int &ans){
	int k=j;
	while(A[k]!=A[i]){
		k--;
	}
	if(k<=i)ans=-1;
	else {
		while(k!=j){
			swap(A[k],A[k+1]);
			ans++;
			k++;
		}
	}
	return;
}
int no_swaps(string &A){
	
	int i=0,j=A.size()-1,ans=0;
	while(i<j){
		swaps(A,i,j,ans);
			if(ans==-1)break;
			i++;j--;
		
	}
	return ans;
}
int main()
{
	
	int ans=0;
	while(1){
		string p;
		getline(cin,p);
		if(p=="0")break;
		cout<< no_swaps(p)<<endl;
	}
	
	
return 0;
}
