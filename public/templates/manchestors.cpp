#include <bits/stdc++.h>

using namespace std;

string manchestor(string &t){
        string s = "$#";
        for(auto c:t) s=s+c+'#';
        s += "&";
        vector<int> pi(s.size()+1);
        int l=1,r=1;
        for(int i=1;i<s.size();i++){
            pi[i] = max(0,min(r-i,pi[l+r-i]));
            while(s[i+pi[i]]==s[i-pi[i]]) pi[i]++;
            if(r<pi[i]+i){
                r = pi[i] + i;
                l = i-pi[i];
            }
        }
        auto mxt = max_element(pi.begin(),pi.end());
        string res = s.substr(mxt-pi.begin()-*mxt+1,2*(*mxt)-1);
        res.erase(std::remove(res.begin(), res.end(), '#'), res.end());
        return res;
}