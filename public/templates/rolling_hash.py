from collections import Counter
import random

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

# M = 2**61 - 1;
# B  = random.randrange(0,M)
# def code(x): return ord(x) - ord('a') + 1
# class HashedString:
#     def __init__(self,s) -> None:
#         n = len(s)
#         self.ppow =  [1]
#         self.hashes = [0]
#         for i in range(n): self.ppow.append((self.ppow[-1]*B)%M)
#         for i in range(n): self.hashes.append(((self.hashes[-1]*B)%M + code(s[i]))%M)
#     def get_hash(self,i,j):
#         return (self.hashes[j+1]-(self.hashes[i]*self.ppow[j-i+1])%M )%M
    
            