#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
/*
EXPLAINATION:
 FIB SERIES: 0 1 1 2 3 5 8 13
FIB SERIES  FROM INDEX 2: 1 2 3 5 8 13 18 

1      -1
10
100
101
1000
1001
1010
10000  -8
10001  -9  
10010  
10100  
10101

NOTICE THAT 9TH NUMBER IS 10001. INT FIB SERIES(2- INDEXED) 1ST NO. <= 9 IS AT INDEX 5 SO WE TRAVERSE FIB(2 -INDXED) ARRAY FROOM BEHIND AND
AS WE GET NO.<=N WE START OUR SOLN STRING BY APPENDING '1' AND UPDATING N TO N-FIB[i] AND THEN WE CONTINUE TRAVERSING AND APPENDING '0' TO SOLN STRING
BUT AS SOON AS WE GET FIN[i]<=N  WE APPEND 1; THIS PATTERN WILL ALWAYS YIELD THE ANS;
00 01 10 11 100 101 110 111 1000 1001 1010 1011 1100 1101 1110 1111 10000 10001 10010 10011 
0  1   2     4   5           8     9    10                           16
*/

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll int>A;
	 	A.push_back(1);
	 	A.push_back(2);
	 	while(A[A.size()-1]<100000001)A.push_back(A[A.size()-1]+A[A.size()-2]);
	int t=1;
	cin>>t;
	 while(t--){
	 	// 1 2 3 5 8 13
	 	// 1 0 0 0 1
	 	ll int n; 
	 	cin>>n;
	 	int i=A.size()-1;
	 	while(A[i]>n){
	 		i--;
		}
		 string ans="";
	 	for(;i>=0;i--){
		 	if(A[i]<=n){ ans+='1'; n=n-A[i]; continue;}
		 	ans+='0';
		 }
	 	cout<<ans<<'\n';
	 }
	
	
return 0;
}
