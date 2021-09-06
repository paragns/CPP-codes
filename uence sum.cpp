#include <bits/stdc++.h>
using namespace std;

  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k;
	cin>>i>>j>>k;
	
	long long int sum=0;
	if(i==j)sum=2*i;
	else while(i<j){
		sum+=i;
		i++;
	}
	
	while(j>=k){
		sum+=j;
		j--;
	}

	cout <<sum;
return 0;
}
