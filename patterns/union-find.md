# Union Find

```cpp
class UnionFind {
public:
    vector<int> parent;
    
    UnionFind(int n) {
        // Add dummy node to the tail
        for(int i = 0; i < n; ++i) {
            parent.push_back(i);
        }
    }
    
    int find(int i) {
        if(i == parent[i]) return i;
        return find(parent[i]);
    }
    
    void unite(int i, int j) {
        int pi = find(i);
        int pj = find(j);
        if(pi != pj) parent[pj] = pi;
    }
    
    bool isConnect(int i, int j) {
        return find(i) == find(j);
    }
};
```
