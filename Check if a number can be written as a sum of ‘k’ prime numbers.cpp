#include <bits/stdc++.h>

using namespace std;

long long mulmod(long long a, long long b, long long c)
{
	long long x = 0, y = a%c;
	while(b>0)
	{
		if(b&1) x = (x+y)%c;
		y = (y<<1)%c;
		b = b>>1;
	}
	return x;
}

long long modulo(long long a, long long b, long long c)
{
	long long x = 1, y = a%c;
	while(b>0)
	{
		if(b&1) x = mulmod(x,y,c);
		y = mulmod(y,y,c);
		b = b>>1;
	}
	return x;
}

bool miller(long long p, int iter)
{
    	if(p<2) return false;
    	if(p==2) return true;
    	if(!(p&1)) return false;
    	long long s = p-1, a, temp, mod;
   	 while(!(s&1)) s = s>>1;
    	for(int i=0; i<iter; i++)
    	{
      		a = rand()%(p-1)+1;
      		temp = s;
      		mod = modulo(a, temp, p);
    		  while(temp!=p-1 && mod!=1 && mod!=p-1)
    		  {
    			  mod = mulmod(mod, mod, p);
    			  temp = temp<<1;
   		   }
    		  if(mod!=p-1 && !(temp&1)) return false;
    	}
    	return true;
}


int main()
{
    long long t,n,k;
    cin >> t;
    while ( t-- ) {
        cin >> n >> k;
        if ( n == 1 ) {
            cout << "No" << endl;
        }
        else if ( n == 2 || n == 3 ) {
            if ( k == 1 ) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else if ( k == 1 ) {
            if ( miller(n,2) ) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else if ( n%2 == 0 ) {
            if ( n/2 >= k ) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else {
            if ( k == 2 ) {
                if ( miller(n-2,2) ) cout << "Yes" << endl;
                else cout << "No" << endl;
            }
            else {
                n -= 3;
                k -= 1;
                if ( n/2 >= k ) cout << "Yes" << endl;
                else cout << "No" << endl;
            }
        }
    }
    return 0;    
}
