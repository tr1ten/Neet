struct trie
{
    int v,sz;
    int val;
    trie *sons[A];
 
    trie()
    {
        v = sz = 0;
        memset(sons,0,sizeof(sons));
    }
 
    void add(int x,int m)
    {
        if ( m==-1  )
        {
            v++;
            sz++;
            val = x;
            return;
        }
        int ind = (x>>m)&1;
        if ( sons[ind ] == NULL ) sons[ind] = new trie();
 
        sz -= sons[ind]->sz;
        sons[ind]->add(x,m-1);
        sz += sons[ind]->sz;
    }
 
    void remove(int x,int m)
    {
        if ( m == -1)
        {
            v--;
            sz--;
            
            return;
        }
        int ind = (x>>m)&1;

        if ( sons[ind]->sz == 0 ) sons[ind] = new trie();
        else
        {
            sz -= sons[ind]->sz;
            sons[ind]->remove(x,m-1);
            sz += sons[ind]->sz;
            if ( sons[ind]->sz == 0 )
                sons[ind] = NULL;
        }
    }

    
    int max_xor(int x,int m){
        if(m==-1) {
            return val^x;
        }
        if(sz==0) { return 0;}
        int ind = (x>>m)&1;
        if(sons[!ind]!=NULL) return sons[!ind]->max_xor(x,m-1);
        return sons[ind]->max_xor(x,m-1);
    }
 
};