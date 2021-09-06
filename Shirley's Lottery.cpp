#include <bits/stdc++.h>
using namespace std;

  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int n;
cin>>n;
vector<int>f(n),s(n);
for(int i=0;i<n;i++){
	cin>>f[i];
}	
cin>>n;
for(int i=0;i<n;i++){

cin>>s[i];
if(f[i]>s[i])swap(f[i],s[i]);
}

sort(f.begin(),f.end());
sort(s.begin(),s.end(),greater<int>());
int ans=0;
int sol=0;
for(int i=0;i<n;i++){
	while(s[s.size()-1]<f[i]){
		ans--;
		s.pop_back();
	}
	ans++;
	sol=max(ans,sol);
}
cout<<sol;
return 0;
}
