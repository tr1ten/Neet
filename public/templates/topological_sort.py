def topo(g):
    ind = [0]*len(g)
    for u in range(len(g)):
        for v in g[u]:
            ind[v] +=1
    q = deque()
    for v in range(len(g)):
        if ind[v]==0:
            q.append(v)
    topo = []
    while(q):
        u = q.popleft()
        topo.append(u)
        for v in g[u]:
            ind[v] -=1
            if ind[v]==0:
                q.append(v)
    return topo