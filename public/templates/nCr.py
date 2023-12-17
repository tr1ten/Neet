MOD = int(1e9+7)
N = 100000 + 5

fact = [0] * N
inv = [0] * N
finv = [0] * N

def pre():
    fact[0] = 1
    for i in range(1, N):
        fact[i] = (fact[i-1] * i) % MOD
    inv[1] = 1
    for i in range(2, N):
        inv[i] = (MOD - MOD // i) * inv[MOD % i] % MOD
    finv[0] = finv[1] = 1
    for i in range(2, N):
        finv[i] = (inv[i] * finv[i-1]) % MOD

def nCk(n, k):
    return (((fact[n] * finv[k]) % MOD) * finv[n-k]) % MOD

def main():
    pre()
    print(nCk(5, 2))
main()