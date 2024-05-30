// https://cses.fi/problemset/result/9393258/
#include<bits/stdc++.h>
using namespace std;

template <typename T> 
class segtree{
    struct Node
    {
        Node *left,*right;
        T val;
        Node(T v,Node *lp=nullptr,Node* rp=nullptr): val(v), left(lp), right(rp) {}
    };
    public:
        int n;
        T basev;
        vector<Node *> roots;
        segtree() {}
        segtree(int _n,T _bv): n(_n),basev(_bv)  {
            roots.push_back(this->_build(0,n-1));
        };
        // Make sure to save node in roots when updating
        Node* update(int index,T new_val,int time=0) {
            assert(index<n);assert(time<roots.size());
            return _update(roots[time],0,n-1,index,new_val);
        }
        T query(int lq,int rq,int time=0){
            assert(lq>=0);assert(rq<n);assert(lq<=rq);assert(time<roots.size());
            return _query(roots[time],0,n-1,lq,rq);
        }

    private:
        T merge(T a,T b) {
            return a+b;
        }
        Node *_build(int l,int r){
            if(l>r) return nullptr;
            Node *node = new Node(this->basev);
            if(l==r) return node;
            int mid = (l+r) >> 1;
            node->left = _build(l,mid);
            node->right = _build(mid+1,r);
            return node;
        }

        Node *_update(Node *node,int l,int r,int ind,T new_val) {
            if(l>r) return nullptr;
            if(ind<l || ind>r) return node;
            Node *_node = new Node(node->val,node->left,node->right);
            if(l==r) {_node->val = new_val; }
            else {
                int mid = (l+r)/2;
                if(ind<=mid)  _node->left = _update(node->left,l,mid,ind,new_val);
                else _node->right = _update(node->right, mid+1,r,ind,new_val);
                _node->val = merge((_node->left)->val,_node->right->val);
            }
            return _node;
        }
        T _query(Node *node, int l,int r, int lq,int rq) {
            if(r<lq || l>rq) return this->basev;
            if(l>=lq && r<=rq)  return node->val;
            int mid = (l+r)/2;
            return merge(_query(node->left,l,mid,lq,rq),_query(node->right,mid+1,r,lq,rq));
        }
};
int main(int argc, char const *argv[])
{
    segtree<int> s(10,0);
    for(int i=1;i<10;i++){ s.roots[0]= s.update(i,i+1); cout << i << " sum " << (s.query(i-1,i)) << endl;}
    
    return 0;
}
