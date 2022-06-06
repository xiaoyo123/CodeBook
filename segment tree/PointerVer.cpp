struct node{
    node *l, *r;
    int val, tag;
    node(){
        val = tag = 0;
        l = r = nullptr;
    }
    void get(){/*to do*/}
};
node *build(int l, int r){
    node *a = new node();
    if(l == r){
        a->val = array[l];
        return;
    }
    int mid = (l + r) >> 1;
    a->l = build(l, mid);
    a->r = build(mid + 1, r);
    a->get();
    return a;
}
int query(int l, int r, int ql, int qr, node *now){
    if(ql <= 0 || qr <= 0) return 0;
    if(l == ql && qr == r) return now->val;
    int mid = (l + r) >> 1;
    int ls = 0, rs = 0;
    if(l <= ql && ql <= mid)
        ls = query(l, mid, ql, qr, now->l);
    if(mid + 1 <= qr && qr <= r)
        rs = query(mid + 1, r, mid + 1, qr, now->r);
    return ls + rs;
}
void push(node *&x, int l, int r){
    if(x->tag != 0){
        x->val += x->tag;
        if(l != r){
            x->l->tag += x->tag;
            x->r->tag += x->tag;
        }
        x->tag = 0;
    }
}
void update(node *x, int l, int r, int ql, int qr, int v){
    push(x, l, r);
    if(ql <= l && r <= qr){
        x->tag += v;
        return;
    }
    int mid = (l + r) >> 1;
    if(ql <= mid){
        if(x->l == nullptr) x->l = new node();
        update(x->l, l, mid, ql, qr, v);
    }
    if(qr > mid){
        if(x->r == nullptr) x->r = new node();
        update(x->r, mid + 1, r, ql, qr, v);
    }
    push(x->l, l, mid);
    push(x->r, mid + 1, r);
    x->get();
}