long long fast_pow(long long a,long long b,long long MOD){
    if(b==0) return 1;
    long long res = fast_pow(a,b/2,MOD);
    if(b%2==0) return (res*res)%MOD;
    return (((res*res)%MOD)*a)%MOD;
}