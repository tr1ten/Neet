MOD = (10**9) + 7
P = 31
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

def sub_hash(i,j,hash,pinv):
    return ((hash[j+1]-hash[i])*pinv[i])%MOD