def lps(s):
        arr = [0]*len(s)
        i,j = 1,0
        while(i<len(s)):
            if(s[i]==s[j]):
                arr[i] = j+1
                j +=1
                i+=1
            elif(j==0):
                arr[i] = 0
                i+=1
            else:
                j = arr[j-1] # can't just use j-1 since we don't know if smaller <j-1 are equal 
        return arr
def strStr(self, haystack, needle):
    s  =  needle+"#"+haystack
    for i,x in enumerate(lps(s)):
        if(x==len(needle)): return i-2*len(needle)
    return -1