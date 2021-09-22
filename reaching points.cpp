#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
		 ll x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		while(x2>=x1&&y2>=y1){
			if(x1==x2&&y1==y2){
				cout<<"Yes";
				return 0;
			}
			else{
				if(x2>y2){
					if((x2-x1)%y2==0)x2=x1;
					else x2=x2%y2;
				}
				else {
					if((y2-y1)%x2==0)y2=y1;
					else y2=y2%x2;
				}
			}
		}
		cout<<"No";
	}
return 0;
}
//  look here for explaination:
//   if(y2>x2) then prev state has to be   (y'+x2,x2)
//   similarly for (x2>y2);
//  now  if we have (11,2):
// prev states can be:(11,2)->(9,2)->(7,2)->(5,2)->(3,2)->(1,2)
// thus (1,2) can be obtained directly (11%2,2), i.e (x2%y2,y2);
// thus while(x2>y2) we do(x2=x2%y2);
// but what if (x1,y1) required ans is in intermediate state 
// i.e for above example if (7,2) is req ans we wont get this state as (11,2)is directly converted to(1,2);
// thus before doing(x2=x2%y2) we check if((x2-x1)%y2==0)if it is we make x2 as x1;
// i.e for (11,2) (11-7)%2==0 there for 7 can be obtained by substracting 2 from 11 twice;
// therefore (7,2) is attainable; 
 
