def fast_pow(a, b, m):
    if b == 0:
        return 1
    if b == 1:
        return a % m
    if b % 2 == 0:
        return fast_pow(a * a % m, b // 2, m)
    else:
        return a * fast_pow(a * a % m, b // 2, m) % m


MOD = (10**9) + 7
P = 31
"""
    Rabin Karp
    @params:
        s: string to hash
    @return:
        hash: List[int] Hash of string
        pp: List[int] Powers of P
        pinv: List[int] Inverse of powers of P
    TC: O(N)
        
"""
def rabin(s):
    n = len(s);
    pp = [1]*n
    pinv = [1]
    for i in range(1,n): 
        pp[i] = (pp[i-1]*P)%MOD
        pinv.append(fast_pow(pp[i],MOD-2,MOD));
    hash = [0]*(n+1) # 1 index hash
    for i in range(n): hash[i+1] = (hash[i] + ((ord(s[i])-ord('a')+1)*pp[i])%MOD )%MOD
    return hash,pp,pinv

"""
    Substring Hash
    @params:
        i: int start index
        j: int end index
        hash: List[int] Hash of string
        pinv: List[int] Inverse of powers of P
    @return:
        hash of substring s[i:j+1]: int
"""
def sub_hash(i,j,hash,pinv):
    return ((hash[j+1]-hash[i])*pinv[i])%MOD