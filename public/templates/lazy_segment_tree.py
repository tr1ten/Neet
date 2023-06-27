from typing import List

class RangeQuery :
    def __init__(self,n:int) :
        # approx power of 2
        self.n =  2**(n-1).bit_length()
        self.tree = [0] * (2 * self.n + 1) # 1 based indexing 
        self.lazy = [0]*(2*self.n + 1) # for keeping info about updated values
        
    def _parent(self,i:int) -> int:
        return i//2;
    def _childs(self,i:int) -> List[int]:
        return [2*i,2*i+1];
    def _isleaf(self,i:int)->bool:
        return i>=self.n;
    def lazy_update(self,hi:int,lo:int,node:int):
        if(self.lazy[node]!=0):
            self.tree[node] += (hi-lo+1)*self.lazy[node];
            if(not self._isleaf(node)):
                lc,rc = self._childs(node)
                self.lazy[lc] = self.lazy[node];
                self.lazy[rc] = self.lazy[node];
            self.lazy[node] = 0
    def update(self,index:int,diff:int) -> None:
        i = index+self.n # node in the tree
        self.tree[i] +=diff
        i = self._parent(i)
        while(i>0):
            left,right = self._childs(i);
            self.tree[i] = (self.tree[left]+self.tree[right])
            i = self._parent(i)
    # update value from l to r
    def _range_update(self,low:int,high:int,l:int,r:int,diff:int,node:int):
        # check for lazy updates
        self.lazy_update(high,low,node);
        if(high<l or r<low): return;
        if(low>=l and high<=r):
            self.tree[node] +=(high-low+1)*diff;
            if(not self._isleaf(node)):
                lc,rc = self._childs(node)
                self.lazy[lc] += diff
                self.lazy[rc] += diff
            return;
        mid = (low+high) >> 1;
        lc,rc = self._childs(node)
        self._range_update(low,mid,l,r,diff,lc)
        self._range_update(mid+1,high,l,r,diff,rc);
        self.tree[node] = self.tree[lc]+self.tree[rc]
    
    def range_update(self,left:int,right:int,diff:int):
        self._range_update(0,self.n-1,left,right,diff,1)
    
    def _query_sum(self,ns:int,ne:int,start:int,end:int,node:int) -> int:
        self.lazy_update(ne,ns,node);
        if(ns>=start and ne<=end): # perfect match
            return self.tree[node] 
        if(ne < start or end<ns): return 0 # doesn't lie in the range
        mid = (ns+ne)//2;
        left,right = self._childs(node)
        return self._query_sum(ns,mid,start,end,left) + self._query_sum(mid+1,ne,start,end,right)
    def query_sum(self,left:int,right:int):
        return self._query_sum(0,self.n-1,left,right,1);

def main():
    n = 5                                       
    arr = [1,2,3]
    rq = RangeQuery(3)
    for i in range(3):
        rq.update(i,arr[i])
    print(rq.query_sum(0,2))
    rq.range_update(0,1,2);
    print(rq.query_sum(0,2))
    
    
if __name__ == "__main__":
    main()
    