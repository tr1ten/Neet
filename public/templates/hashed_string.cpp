// use c++20 compiler
using ll = long long;
class HashedString {
public:
	static const long long M = (1LL<<61) -1;
	static const long long B;
    static vector<long long> ppow;
    vector<long long> hashes;
    __int128 mul(ll a, ll b) { return (__int128)a * b; }
	ll mod_mul(ll a, ll b) { return mul(a, b) % M; }
    HashedString(string s) {
        int n = s.length();
        ppow = {1};
        hashes = {0};

        for (int i = 0; i < n; ++i) {
            ppow.push_back(mod_mul(ppow.back(),B) );
        }

        for (int i = 0; i < n; ++i) {
            hashes.push_back((mod_mul(hashes.back(), B) + (s[i] - 'a' + 1)) % M);
        }
    }

    long long getHash(int i, int j) {
        return (hashes[j + 1] - mod_mul(hashes[i], ppow[j - i + 1]) + M) % M;
    }
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll HashedString::B = uniform_int_distribution<ll>(0, M - 1)(rng);
vector<long long> HashedString::ppow = {1};