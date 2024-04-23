
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        adj = [[] for i in range(n)]
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        def bfs(u):
            q = deque()
            q.append(u)
            dist = [float('inf')]*n
            par = [-1]*n
            par[u] = u
            dist[u] = 0
            while q:
                u = q.popleft()
                for v in adj[u]:
                    if dist[v]>dist[u]+1:
                        dist[v] = dist[u] + 1
                        par[v] = u
                        q.append(v)
            mxd = max(dist) # assuming connected
            v = dist.index(mxd)
            path = [v]
            while par[path[-1]]!=path[-1]:
                path.append(par[path[-1]])
            return mxd,path[::-1]
        d,p2 = bfs(0)
        d2,p = bfs(p2[-1])
        if len(p)%2:
            return [p[len(p)//2]]
        else:
            return [p[len(p)//2  - 1],p[len(p)//2]]
        return []


                    
            