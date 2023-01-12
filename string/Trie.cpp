struct trie{
    trie *nxt[26];
    int cnt, sz;
    set<int> pass, ending;
    trie():cnt(0), sz(0){
        memset(nxt, 0, sizeof(nxt));
        pass.clear(); ending.clear();
    }
};
trie *root = new trie();
int n, q;
string s[100005];

void insert(string &s, int pos){
    trie *now = root;
    for(auto i : s){
        now->sz++;
        now->pass.insert(pos);
        if(now->nxt[i - 'a'] == NULL) now->nxt[i - 'a'] = new trie();
        now = now->nxt[i - 'a'];
    }
    now->sz++; now->cnt++;
    now->pass.insert(pos); now->ending.insert(pos);
}
void dlt(string &s, int pos){
    trie *now = root;
    for(auto i : s){
        now->sz--;
        now->pass.erase(pos);
        now = now->nxt[i - 'a'];
    }
    now->sz--; now->cnt--;
    now->pass.erase(pos); now->ending.erase(pos);
}