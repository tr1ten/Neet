MAX=2*(10**4) + 1
def sieves():
    primes = [True]*MAX
    for i in range(2,MAX):
        if(not primes[i]): continue
        for j in range(i*i,MAX,i):
            primes[j] = False
    only_primes = [i for i in range(2,MAX) if(primes[i])]
    return only_primes  
PRIMES = sieves()