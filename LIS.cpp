#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	vector<int>A(n);
	for(int i=0;i<n;i++)
		cin>>A[i];
	
	set<int>s;
	for(int i=0;i<n;i++){
		if(s.find(A[i])!=s.end()){//  if number ARE NOT DISTICT
			continue;
		} 
		s.insert(A[i]);
		auto x=s.upper_bound(A[i]);
		if(x!=s.end())s.erase(x);
		//cout<<s.size()<<" ";
	}
	cout<<s.size();
	  
return 0;
}
// 10 9 2 5 3 7 101 18
// 2 4 5  


// 2 5 4 6 3 4 5 6 7
// 2 3 4 5 6 7
// 1 2 2 3 3 3 4 5 6
// 
/*
 Find the Longest increasing subsequence at Each Position
 
   vector<int> dp(n+1,INT_MAX);    
    vector<int> ans;
    dp[0] = -1;
        for(int i=0;i<n;i++){
            int ind = upper_bound(dp.begin(),dp.end(),A[i])-dp.begin();
            ans.push_back(ind);
            dp[ind]= A[i];
        }
    return ans;
 */
