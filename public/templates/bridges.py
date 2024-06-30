def bridges(n,adj,ty):
    low = [0]*n
    tin = [0]*n
    timer = 0
    cnt = 0
    vis = set()
    def dfs(u,p):
        nonlocal cnt,timer
        low[u] = timer
        tin[u] = timer
        timer+=1
        vis.add(u)
        for t,v in adj[u]:
            if v==p:
                continue
            if v in vis:
                low[u] = min(low[u],tin[v])
            else:
                dfs(v,u)
                low[u] = min(low[u],low[v])
                if low[v]>tin[u] and t==ty:
                    cnt +=1
    c= 0 
    for i in range(n):
        if i not in vis:
            dfs(i,-1)
            c +=1
    return cnt,c