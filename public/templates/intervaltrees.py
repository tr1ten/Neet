from math import ceil, log2
# Coordinate compressed
class IntervalTree:
    def __init__(self, xs,merge=lambda x,y:x+y):
        self.xs = sorted(set(xs))
        self.merge= merge
        self.n = len(xs)
        self.tree = [0] *  ( 4*self.n + 2 )
        self.cnt = [0] * ( 4*self.n + 2 )
        
    
    def query(self):
        return self.tree[0]

    def _update_util(self, i, ln,rn,ql,qr,val):
        if qr<ql:
            return
        if ql==self.xs[ln] and self.xs[rn]==qr:
            self.cnt[i] +=val
        else:
            mid = (ln+rn)//2
            if ql<self.xs[mid]:
                self._update_util(2*i+1,ln,mid,ql,min(qr,self.xs[mid]),val)
            if qr>self.xs[mid]:
                self._update_util(2*i+2,mid,rn,max(ql,self.xs[mid]),qr,val)
        if self.cnt[i]:
            self.tree[i] = self.xs[rn] - self.xs[ln] 
        else:
            self.tree[i] = (self.merge(self.tree[2*i+1],self.tree[2*i+2]) if 2*i+2 < len(self.tree) else 0)
        print(i,ln,rn,self.tree[i],self.cnt[i])
    def update(self, l,r, v):
        self._update_util( 0, 0,self.n-1,l,r,v)
   
def main():
    n = 5               
    rq = IntervalTree([2,3,5])
    # rq.update(2,4,1)
    rq.update(3,5,1)
    print(rq.query())
    rq.update(3,5,-1)
    
    print(rq.query())
    
    
main()