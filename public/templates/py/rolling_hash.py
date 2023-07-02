
MOD = (10**9) + 7
P = 31
MAXN = 10**5+ 3;
pp = [1]
def code(x):  # return unsigned int representation of key
    return ord(x)-ord('a') + 1 
def powers():
    for i in range(len(pp),MAXN):
        pp.append((pp[-1]*P)%MOD)
def hash(s): # hash using a0*P^(k-1) + a1*P^(k-2) ... ak-1*P^0
    n = len(s)
    h = 0
    for i in range(n):
        h = (h + (code(s[i]))*pp[n-i-1])%MOD
    return h
"""
@params: 
    old_hash: hash of previous substring
    k: length of previous substring
    prev: first character of previous substring
    next: last character of new substring
    
"""
def rolling_hash(old_hash:int,k:int,prev: str,next:str): # get new hash from old hash
    return (((old_hash + MOD-(code(prev))*(pp[k-1]))*P)%MOD + code(next))%MOD
powers()
# N
# substring search nlogn
def substr(s,p):
    tar = hash(p)
    k = len(p)
    old = hash(s[:k])
    if old==tar: return 0
    for i in range(k,len(s)):
        old = rolling_hash(old,k,s[i-k],s[i])
        if old==tar: return i-k+1
    return -1
print(substr("01234","234"));