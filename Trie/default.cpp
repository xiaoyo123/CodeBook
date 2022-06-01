struct trie{
    trie *nxt[26];
    int sz, cnt;
    trie() : sz(0), cnt(0){
        memset(nxt, 0, sizeof(nxt));
    }
};

trie *root = new trie();

void insert(string &s){
    trie *now = root;
    for(auto i : s){
        if(now->nxt[i - 'a'] == NULL)
            now->nxt[i - 'a'] = new trie();
        now->sz++;
        now = now->nxt[i - 'a'];
    }
    now->sz++;
    now->cnt++;
}
int prefix(string &s){
    trie *now = root;
    for(auto i : s){
        if(now->nxt[i - 'a'] == NULL) return 0;
        now = now->nxt[i - 'a'];
    }
    return now->sz;
}
int count(string &s){
    trie *now = root;
    for(auto i : s){
        if(now->nxt[i - 'a'] == NULL) return 0;
        now = now->nxt[i - 'a'];
    }
    return now->cnt;
}
void del(string &s){
    trie *now = root;
    for(auto i : s){
        now->sz--;
        now = now->nxt[i - 'a'];
    }
    now->sz--; now->cnt--;
}