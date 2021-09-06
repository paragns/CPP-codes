#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
	cin >>n;
	int extend[n];
	
	memset(extend,-1,sizeof(extend));
	
	for(int i=0;i<n;i++){
		int l;
		cin>>l;
		int left=max(i-l,0);
		int right=min(i+l+1,n);
		extend[left]=max(extend[left],right);
	}
	int ans=1;
	int right=extend[0];
	int next=0;
	 for(int i=0;i<n;i++){
        next = max(next,extend[i]);
    
        if (i == right){
            ans++;
            right = next;
        }
    }
	cout<<ans;
return 0;
}

