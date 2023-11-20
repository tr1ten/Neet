import math

K = 25
N = 10**5 + 5

st = [[0]*(K+1) for _ in range(N)]

def merge(x, y):
    return min(x, y)

def log2_floor(i):
    return int(math.log2(i)) if i else -1

def build(A):
    global K
    K = log2_floor(len(A))
    for i in range(len(A)):
        st[i][0] = A[i]
    for k in range(1, K+1):
        for i in range(len(A)):
            st[i][k] = merge(st[i][k-1], st[i+(1<<(k-1))][k-1])

def query(l, r):
    k = log2_floor(r-l+1)
    return merge(st[l][k], st[r-(1<<k) +1][k])