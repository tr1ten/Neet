#include<bits/stdc++.h>
using namespace std;

template <typename T> 
class SegmentTree{
    struct Node
    {
        Node *left,*right;
        T val;
    };
    
    T merge(T &a,T &b) {
        return a+b;
    }

    int n,basev;
    
    SegmentTree(int siz,int bv=0) n(size),basev(bv) {}
    
     
};