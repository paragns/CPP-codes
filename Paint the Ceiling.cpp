#include <bits/stdc++.h>
using namespace std;
 
  #define mod 1000000000+7 
// Driver code
int main()
{
long long int n,s,k,b,m,a;
  cin>>n>>s>>k>>b>>m>>a;
  vector<long long int > sides(n);
  sides[0]=s;
  
	  for(int i=1;i<n;i++){
  		sides[i]=(((k*sides[i-1]+b)%m)+1+sides[i-1]);
  		
	  }
	  
		int i=0,j=n-1;  
	  long long int ans=0;
while (i <= j){
    if ( sides[i] <= a/sides[j]){
		ans+=2*(j - i) + 1;
		 i++;
	}  
    else
        j--;
	
}
   cout<<ans;
return 0;
}
