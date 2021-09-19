ll int power(ll int x, ll int y){
    if (y == 0)return 1;
    ll int st= power(x, y / 2)%mod;   
     if (y % 2 == 0)
        return ((st)%mod * (st)%mod)%mod;
    else
        return (x%mod *(st)%mod * (st)%mod)%mod;
}
