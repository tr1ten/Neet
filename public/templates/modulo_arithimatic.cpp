typedef long long ll;
ll modmul(ll a, ll b, ll M) {
	ll ret = a * b - M * ll(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ll modpow(ll b, ll e, ll mod) {
	ll ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}
ll modadd(ll a,ll b,ll MOD) {
    b %= MOD;
    a %=MOD;
    return (a+b)%MOD;
}