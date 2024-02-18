#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
long long fast_pow(long long a,long long b,long long MOD){
    if(b==0) return 1;
    long long res = fast_pow(a,b/2,MOD);
    if(b%2==0) return (res*res)%MOD;
    return (((res*res)%MOD)*a)%MOD;
}

bool isprime(LL n){
	if(n<2) return false;
	for(LL i=2;i*i*i<=n;++i) if(n%i==0) return false;
	for(int it=0;it<1e5;++it){
		LL i = rand()%(n-1)+1;
		if(__gcd(i,n)!=1) return false;
		if(fast_pow(i,n-1,n)!=1) return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
    cout << isprime(1000000008989311) << '\n';
    return 0;
}
