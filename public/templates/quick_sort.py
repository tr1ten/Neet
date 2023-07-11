import random
def quick(A,k):
    if len(A)==1: return A[0]
    if not A: return -1
    x = random.choice(A)
    left = [y for y in A if y<x]
    mid =  [y for y in A if y==x]
    right =  [y for y in A if y>x]
    if len(left)<k<=len(left)+len(mid): return mid[0]
    if len(left)>=k: return quick(left,k)
    else: return quick(right,k-(len(left)+len(mid)))