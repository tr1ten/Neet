import heapq
def dijsktra(adj,S,K):
    N = len(adj)
    dist = [[float('inf')]*(K+1) for i in range(N)]
    for i in range(K+1): dist[S][i] = 0
    dq = [(0,0,0)] # no skip
    while(dq):
        cost,u,k = heapq.heappop(dq)
        if dist[u][k]<cost: continue
        # if k==K: continue
        for v,c in adj[u]:
            if dist[v][k]>dist[u][k] + c:
                dist[v][k] = dist[u][k]+c; # no skip
                heapq.heappush(dq,(dist[v][k],v,k))
            if k+1<=K and dist[v][k+1]>dist[u][k]: # skip
                dist[v][k+1] = dist[u][k];
                heapq.heappush(dq,(dist[v][k+1],v,k+1))
    return dist

def dijkstra(S, adj):
    n = len(adj)
    dist = [float('inf')] * n
    par = [-1] * n
    dist[S] = 0
    par[S] = S
    pq = [(0, S)]

    while pq:
        du, u = heapq.heappop(pq)
        if du > dist[u]:
            continue

        for v, w in adj[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                par[v] = u
                heapq.heappush(pq, (dist[v], v))

    return par  # or dist according to needs
# General K smallest distance dijsktra
def main():
    N,M,K = map(int,input().split())
    adj = [[] for i in range(N)]
    for i in range(M):
        u,v,c = map(int,input().split())
        adj[u-1].append((v-1,c))
        adj[v-1].append((u-1,c))
    dist = dijsktra(adj,0,K)
    print(" ".join(map(lambda x:str(x[-1]),dist)))