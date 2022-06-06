struct convex_hull{
    Type x, y;
    convex_hull(){}
    convex_hull(Type _x, Type _y){
        x = _x, y = _y;
    }
    convex_hull operator - (const convex_hull &a){
        return convex_hull(x - a.x, y - a.y);
    }
    bool operator < (const convex_hull &a) const{
        return x < a.x || (x == a.x && y < a.y);
    }
    friend Type cross(convex_hull &o, const convex_hull &a, const convex_hull &b){
        convex_hull lhs = o - a, rhs = o - b;
        return lhs.x * rhs.y - lhs.y * rhs.x;
    }
};

vector<convex_hull> Pt;

vector<convex_hull> Convex_Hull(vector<convex_hull> hull){
    sort(hull.begin(), hull.end());
    int top = 0;
    vector<convex_hull> ret;
    for(int i = 0; i < hull.size(); i++){
        while(top >= 2 && cross(ret[top - 2], ret[top - 1], hull[i]) <= 0)
            ret.pop_back(), top--;
        ret.push_back(hull[i]);
        top++;
    }
    for(int i = hull.size() - 2, t = top + 1; i >= 0; i--){
        while(top >= t && cross(ret[top - 2], ret[top - 1], hull[i]) <= 0)
            ret.pop_back(), top--;
        ret.push_back(hull[i]);
        top++;
    }
    ret.pop_back();
    return ret;
}
