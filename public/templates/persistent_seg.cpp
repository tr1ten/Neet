#include<bits/stdc++.h>
using namespace std;

template <typename T> 
class segtree{
    public:
        int n;
        T basev;
        segtree() {}
        segtree(int _n,T _bv): n(_n),basev(_bv)  { };

    struct Node
    {
        Node *left,*right;
        T val;
        Node(T v,Node *lp=nullptr,Node* rp=nullptr): val(v), left(lp), right(rp) {}
    };
    private:
        T merge(T &a,T &b) {
            return a+b;
        }
        Node *_build(int l,int r){
            Node *node = new Node(this->basev);
            if(l==r) return node;
            int mid = (l+r) >> 1;
            node->left = build(l,mid);
            node->right = build(mid+1,r);
            return node;
        }

        Node *_update(Node *node,int l,int r,int ind,T new_val) {
            if(l>r) return nullptr;
            Node *_node = new Node(node->val);
            if(l==r) {node->val = new_val; }
            else {
                int mid = (l+r)/2;
                _node->left = _update(node->left,l,mid,ind,new_val);
                _node->right = _update(node->right, mid+1,r,ind,new_val);
            }
            return _node;
        }
     
};

int main(int argc, char const *argv[])
{
    segtree<int> s(10,0);
    return 0;
}
