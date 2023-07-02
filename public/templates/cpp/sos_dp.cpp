#include <bits/stdc++.h>

using namespace std;
// N*2^N
// Think of it as N dimesion hyper cube (errichto <3): easy to visualize with 2D
// similar idea as prefix sum over each dimesion then merge 
// dimensionality reduction
const int N = 20;
int dp[1<<N];
int op=1;
void sos_bd(){ // op(operation add or sub) value of submask to super mask
    for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
	if(mask & (1<<i))
		dp[mask] += op*dp[mask^(1<<i)];
}
}
void sos_fwd(){ // op value of supermask to submask
    for(int i = 0;i < N; ++i) for(int mask = (1<<N)-1; mask >=0; --mask){
	if((mask & (1<<i))==0)
		dp[mask] += op*dp[mask^(1<<i)];
}
}