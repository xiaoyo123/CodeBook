struct treap{
    int key, pri, sz, tag;
    treap *l, *r;
    treap(){};
    treap(int _key){
        key = _key;
        pri = rand();
        sz = 1;
        l = r = nullptr;
    }
};

treap *root = nullptr;

int Size(treap *x){
    return x ? x->sz : 0;
}
void pull(treap *x){
    x->sz = Size(x->l) + Size(x->r) + 1;
}
void push(treap *x){
    if(x->tag){
        swap(x->l, x->r);
        if(x->l) x->l->tag ^= 1;
        if(x->r) x->r->tag ^= 1;
        x->tag = 0;
    }
}
treap* merge(treap *a, treap *b){
    if(!a || !b) return a ? a : b;
    if(a->pri > b->pri){
        // push(a);
        a->r = merge(a->r, b);
        pull(a);
        return a;
    }
    else{
        // push(b)
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
}
void splitByKey(treap *x, int k, treap *&a, treap *&b){
    if(!x){
        a = b = nullptr;
        return;
    }
    // push(x)
    if(x->key <= k){
        a = x;
        splitByKey(x->r, k, a->r, b);
        pull(a);
    }
    else{
        b = x;
        splitByKey(x->l, k, a, b->l);
        pull(b);
    }
}
void splitByKth(treap *x, int k, treap *&a, treap *&b){
    if(!x){
        a = b = nullptr;
        return;
    }
    // push(x);
    if(Size(x->l) + 1 <= k){
        a = x;
        splitByKth(x->r, k - Size(x->l) - 1, a->r, b);
        pull(a);
    }
    else{
        b = x;
        splitByKth(x->l, k, a, b->l);
        pull(b);
    }
}
void insert(int val){
    treap *x = new treap(val);
    treap *l, *r;
    splitByKey(root, val, l, r);
    // splitByKth(root, val, l, r);
    root = merge(merge(l, x), r);
}
void erase(int val){
    treap *l, *mid, *r;
    splitByKey(root, val, l, r);
    splitByKey(l, val - 1, l, mid);
    // splitByKth(root, val, l, r);
    // splitByKth(l, val - 1, l, r);
    root = merge(l, r);
}