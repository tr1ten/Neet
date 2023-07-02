def comb(n,r):
    res = set()
    _comb(n,r,0,0,res)
    return res

def _comb(n:int,r:int,i:int,cur:int,subset:set):
    if(r==0):
        subset.add(cur);
        return;
    for j in range(i,n):
        _comb(n,r-1,j+1,cur | (1<<j),subset)
    
def main():
    print(comb(4,2))

main()