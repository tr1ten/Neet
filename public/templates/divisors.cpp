const int N = 1e5+5;
vector<vector<int>> divs(N+1);
// find prime <sqrt(MAX)
// O(LlogL)
void preprocess(){
    for(int x=2;x<=N;x++){
        for(int u=x;u<=N;u +=x){
            divs[u].push_back(x);   
        }
    }
}
vector<long long> divisors(long long x){
    vector<long long> cur;
      for(int j=1;j*j<=x;j++)
		{		
			if(x%j==0)
			{
				cur.push_back(j);
				if(j != x/j)
					cur.push_back(x/j);
            }
        }
    return cur;
}