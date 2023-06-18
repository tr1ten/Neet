const int MOD = 1e9+7;
void update(int BIT[],int x,int val,int N) { ++x;  while(x<=N)  {  BIT[x]+=val;BIT[x] %=MOD; x+=(x&-x);  } }
long long query(int BIT[],int x) {  ++x;  long long res=0;  while(x>0)  {  res+=BIT[x];res%=MOD;  x-=(x&-x);  } return res; } 
long long range(int bit[],int a,int b){ return (query(bit,b) - query(bit,a-1) + MOD)%MOD;}