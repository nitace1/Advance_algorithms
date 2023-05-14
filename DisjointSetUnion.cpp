class DSU{
  public:
  vector<int> parent, Size;
    void make(int n){
        parent.resize(n);
        Size.resize(n, 1);
        for(int i = 1;i<n;i++)parent[i] = i;
    }

    int Parent(int node){
        if(parent[node] == node)return node;
        return parent[node] = Parent(parent[node]);
    }
    void join(int u, int v){
        int p1 = Parent(u);
        int p2 = Parent(v);
        if(p1 != p2){
            if(Size[p2] > Size[p1])swap(p1, p2);
            parent[p2] = parent[p1];
            Size[p1] += Size[p2];
        }
    }
    bool isJoint(int u, int v){
        return Parent(u) == Parent(v);
    }
};
