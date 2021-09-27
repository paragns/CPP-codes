 ll lcm=1;
    for(ll i=0;i<len;i++){
        for(ll j=i+1;j<len && A[i]!=1 ;j++){
            A[j] = A[j]/__gcd(A[j], A[i]);
        }
        lcm = 1ll*(lcm%mod*(A[i])%mod)%mod;
    }
    return lcm%mod;
