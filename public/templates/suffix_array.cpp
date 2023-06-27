#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

namespace SuffixArray
{
	const int MAXN = 1 << 21;
	const char *S;
	int N, gap;
	int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN]; // pos: store the rank of elements at prev step
    // sa stores sorted indices of suffixes 
    
	bool sufCmp(int i, int j)
	{
		if (pos[i] != pos[j])
			return pos[i] < pos[j];
		i += gap;
		j += gap;
		return (i < N && j < N) ? pos[i] < pos[j] : i > j;
	}

	void buildSA()
	{
		N = strlen(S);
		FOR(i,0, N) sa[i] = i, pos[i] = S[i]; 
		for (gap = 1;; gap *= 2)
		{
			sort(sa, sa + N, sufCmp);
			FOR(i,0, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
			FOR(i,0, N) pos[sa[i]] = tmp[i];
			if (tmp[N - 1] == N - 1) break;
		}
	}

	void buildLCP()
	{
		for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
		{
			for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
			++k;
			lcp[pos[i]] = k;
			if (k)--k;
		}
	}
}

// Example usage
int main()
{
	SuffixArray::S = "abracadabra";
	SuffixArray::buildSA();
	SuffixArray::buildLCP();
	FOR(i,0, strlen(SuffixArray::S))
	{
		printf("%2d\t%s\n", SuffixArray::sa[i], SuffixArray::S + SuffixArray::sa[i]);
	}
	puts("");
	FOR(i,0, strlen(SuffixArray::S))
	{
		printf("%2d\t%d\n", i, SuffixArray::lcp[i]);
	}
	return 0;
}