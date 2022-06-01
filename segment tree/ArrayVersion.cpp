#define N (int)1e5

struct Tree{
    int val;
    int lz;
    Tree():val(0), lz(0){}
};

Tree tree[4 * N];
int array[N];

void push(int i, int l, int r){
    if(tree[i].lz != 0){
        tree[i].val += tree[i].lz;
        if(l != r){
            tree[2 * i].lz += tree[i].lz;
            tree[2 * i + 1].lz += tree[i].lz;
        }
        tree[i].lz = 0;
    }
}
void build(int i, int l, int r){
    if(l == r){
        tree[i].val = array[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    tree[i].val = tree[2 * i].val + tree[2 * i + 1].val;
}
int query(int i, int l, int r, int ql, int qr){
    // push(i, l, r);
    if(ql <= l && r <= qr) return tree[i].val;
    int mid = (l + r) / 2, sum = 0;
    if(ql <= mid) sum += query(2 * i, l, mid, ql, qr);
    if(qr > mid) sum += query(2 * i + 1, mid + 1, r, ql, qr);
    return sum;
}
void updateSingle(int i, int l, int r, int pos, int val){
    if(l == r){
        tree[i].val = val;
        return;
    }
    int mid = (l + r) / 2;
    if(pos <= mid) updateSingle(2 * i, l, mid, pos, val);
    else updateSingle(2 * i, mid + 1, r, pos, val);
    tree[i].val = tree[2 * i].val + tree[2 * i + 1].val;
}
void updateInterval(int i, int l, int r, int ql, int qr, int val){
    push(i, l, r);
    if(ql <= l && r <= qr){
        tree[i].lz += val;
        return;
    }
    int mid = (l + r) / 2;
    if(ql <= mid) updateInterval(2 * i, l, mid, ql, qr, val);
    if(qr > mid) updateInterval(2 * i + 1, mid + 1, r, ql, qr, val);
    push(2 * i, l, mid);
    push(2 * i + 1, mid + 1, r);
    tree[i].val = tree[2 * i].val + tree[2 * i + 1].val;
}
