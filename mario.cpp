#include <bits/stdc++.h>
using namespace std;
#define N 100000
int r1,r2,n;
int rec(int index,vector<int>&right, vector<int>& pre, string & A){
 	
    if(index == n) return 0;

    if(right[index] != -1) return right[index];

    int mine = 1e9;

    if(index + 1 <= n && A[index + 1] != '*') mine = min(mine , 1 + rec(index + 1,right, pre,A));
    if(index + 2 <= n && A[index + 2] != '*') mine = min(mine , 1 + rec(index + 2,right, pre,A));
    if(pre[index] * r2 >= index  * r1 && (index + pre[index] <= n) && ( A[index + pre[index]] != '*') )
        mine = min(mine, 1 + rec(index + pre[index],right, pre,A));

    return right[index] = mine;

}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>sieve(N+1,0);
	sieve[0]=sieve[1]=1;
	for(int i=2;i*i<N;i++){
		if(sieve[i])continue;
		int t=i*i;
		for(int j=t;j<N;j+=i)
			sieve[j]=1;
			
	}
	vector<int>pre(N,0);
	for(int i=1;i<N;i++){
		pre[i]=pre[i-1]+(sieve[i]==0);
		
	}
	
	
	int t;
	cin>>t;
			
	while(t--){
		
		cin>>r1>>r2>>n;
		string A;
		cin>>A;
		A = "0" + A;
	vector<int>right(n+1,-1);
        if(A[n] == '*' || A[1] == '*'){
            cout<<"No way!\n";
            continue;
        }

	int ans=rec(1,right,pre,A);
	if(ans==1e9)cout<<"no way!\n";
	else cout<< ans<<"\n";
	
	}
return 0;
}
