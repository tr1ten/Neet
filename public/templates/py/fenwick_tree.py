class BIT:
    def __init__(self,n:int):
       self.nums = [0]*(n+1)
    def update(self,i:int,val:int):
        i +=1
        while(i<len(self.nums)):
            self.nums[i] +=val
            i += (i&(-i))
    def sum(self,i:int) -> int:
        r = 0
        # i +=1, not needed here since we need sum of rank less than i rank[0...i-1]
        while(i>0):
            r += self.nums[i]
            i -= (i&(-i))
        return r