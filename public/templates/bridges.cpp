
const int N = 1e5 + 5;
vector<set<int>> adj;
int av[N]; // arrival
int low[N]; // lowest id reachable from current node
bool vis[N];
int n,m;
unordered_map<int,unordered_map<int,bool>> bridge;
int timer=0;
void dfs(int u,int p){
    av[u] = low[u] = timer++;
    vis[u]  = 1;
    for(auto v:adj[u]){
        if(v==p) continue;
        if(!vis[v]) dfs(v,u);
        low[u] = min(low[v],low[u]);
        if(low[v]>av[u]){
            bridge[u][v] = 1;
            bridge[v][u] = 1;
        }
            
    }
}