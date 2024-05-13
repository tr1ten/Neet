const int MAXN = 1e6 + 5;
std::vector <int> prime;
bool is_composite[MAXN];
int mob[MAXN];

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
	mob[1] = 1;
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime.push_back (i);
			mob[i] = - 1;					//i is prime
		}
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				mob[i * prime[j]] = 0;	//prime[j] divides i
				break;
			} else {
				mob[i * prime[j]] = mob[i] * mob[prime[j]];	//prime[j] does not divide i
			}
		}
	}
}