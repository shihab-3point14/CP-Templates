/// p/q % mod == (p % mod * q^(-1) % mod) == p % mod * binpow(q,mod-2) % mod
long long binpow(long long a,long long b)
{
    if(b==0)
    {
        return 1;
    }
    if(b%2)
    {
        return (a*binpow(a,b-1))%MOD;
    }
    return binpow((a*a)%MOD,b/2);
}