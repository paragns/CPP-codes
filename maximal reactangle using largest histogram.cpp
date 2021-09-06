#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll int maxrect(vector<ll int>A){
	ll int ans=0;
		stack<ll int>s;
		for(int i=0;i<A.size();i++){
			while(!s.empty() and A[i]<A[s.top()]){
				int ind=s.top();
				s.pop();
				if(s.empty())ans=max(ans,A[ind]*(i));
				else{
					ans=max(ans,A[ind]*(i-s.top()-1));
				}
			}
			s.push(i);
		}
		return ans;	 
}
  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	ll int r,c, ans=0;
    vector<vector<ll int>>A;
	cin>>r>>c;

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin>>A[i][j];	

	for(int i=0;i<r;i++){
		vector<ll int>p=A[i];
		p.push_back(0);
		ans=max(ans,maxrect(p));
		for(int j=i+1;j<r;j++){
			for(int k=0;k<c;k++){
				p[k]+=A[j][k]; 
				if(A[j][k]==0)p[k]=0;
			}
			ans=max(ans,maxrect(p));
		}	
	}	
	cout<<ans;
			
	return 0;

}
