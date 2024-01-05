class BIT:
    def __init__(self,n:int):
       self.nums = [0]*(n+1)
    def update(self,i:int,val:int): # update rank i by val
        i +=1
        while(i<len(self.nums)):
            self.nums[i] +=val
            i += (i&(-i))
    def sum(self,i:int) -> int: # sum of rank 0...i-1
        r = 0
        # i +=1, not needed here since we need sum of rank less than i rank[0...i-1]
        while(i>0):
            r += self.nums[i]
            i -= (i&(-i))
        return r
    

# class MaxBIT:  # One-based indexing
#     def __init__(self, size):
#         self.bit = [0] * (size + 1)
#     def get(self, idx):
#         ans = 0
#         while idx > 0:
#             ans = max(ans, self.bit[idx])
#             idx -= idx & (-idx)
#         return ans
#     def update(self, idx, val):
#         while idx < len(self.bit):
#             self.bit[idx] = max(self.bit[idx], val)
#             idx += idx & (-idx)