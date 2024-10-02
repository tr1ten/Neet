#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> rnd(0,LLONG_MAX);


int main() {
	int len;
	std::cin >> len;

	std::map<int, long long> hash_vals;
	vector<int> a(len);
	for (int &i : a) {
		std::cin >> i;
		// assign a hash value to each unique number in the array
		if (!hash_vals.count(i)) { hash_vals[i] = rnd(gen); }
	}

}