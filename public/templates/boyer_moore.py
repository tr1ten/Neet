def majority(A):
    cand = -1
    votes = 0
    for x in A:
        if votes==0: 
            cand = x
            votes +=1
        elif x==cand: votes+=1
        else: votes -=1
    return cand 
print(majority([ 1, 1, 1, 1, 2, 3, 4]))