#define MAX_SUM_S 1200006


int tr[26][MAX_SUM_S] ,root ,nn; // don't forget to set me
unsigned int val[MAX_SUM_S];
void add(string&s,unsigned int cost,int&p=root ,int i=0){
    if(!p) p = ++nn;
    if(i == s.size()){
        val[p]=min(val[p],cost);
        return;
    }
    add(s,cost,tr[s[i]-'a'][p] ,i+1);
}
bool check(string&s ,int&p=root ,int i=0){
    if(!p) return false;
    if(i == s.size()){
        return true;}
    return check(s ,tr[s[i]-'a'][p] ,i+1);
}