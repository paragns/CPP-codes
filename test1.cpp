  #include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	cin>>t;
	 while(t--){
	 	int A=11;
        vector<int>B={6, 8, 5, 4, 7};
	 	int mine=INT_MAX,n=B.size();
	 	for(int i=0;i<n;i++){ mine=min(mine,B[i]);}
         int lim=A/mine;
         vector<int>ans;
         
         for(int i=0;i<n;i++){
             	if(A-B[i]>=0 and ((A-B[i])/mine)==lim-1){
                      A-=B[i];
                      cout<<i<<" ";
                       ans.push_back(i);
                       i--;
                      lim--;
                }
                 
         }
         cout<<endl;
	for(int i:ans)cout<<i<<" ";
	 }
return 0;
}
  
  
  
  
