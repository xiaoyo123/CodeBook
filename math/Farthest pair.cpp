// do convex hull first

Type dis(convex_hull a, convex_hull b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

Type Farthest_pair(vector<convex_hull> a){
    Type ret = 0;
    for(int i = 0, j = i + 1; i < a.size(); i++){
        while(dis(a[i], a[j]) < dis(a[i], a[(j + 1) % a.size()]))
            j = (j + 1) % a.size();
        ret = max(ret, dis(a[i], a[j]));
    }
    return ret;
}