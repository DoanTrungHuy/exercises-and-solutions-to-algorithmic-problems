using ll = long long;

class SegmentTree {
private:
    vector<int> tree, lazy;
    vector<int> nums;
    int n;
    
public:
    SegmentTree(vector<int> nums) {
        this->nums = nums;
        n = nums.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(1, 0, n - 1);
    }
    
    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = this->nums[l];
            return;
        }
        int m = (r + l) >> 1;
        build(node << 1, l, m);
        build(node << 1 | 1, m + 1, r);
        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }
    
    void down(int node, int l, int m, int r) {
        if (lazy[node]) {
            tree[node << 1] = (m - l + 1) - tree[node << 1];
            lazy[node << 1] ^= 1;
            tree[node << 1 | 1] = (r - m) - tree[node << 1 | 1];
            lazy[node << 1 | 1] ^= 1;
            lazy[node] = 0;
        }
    }
    
    void update(int node, int l, int r, int u, int v) {
        if (v < l or r < u) {
            return;
        }
        if (u <= l and r <= v) {
            tree[node] = (r - l + 1) - tree[node];
            lazy[node] ^= 1;
            return;
        }
        int m = (l + r) >> 1;
        down(node, l, m, r);
        update(node << 1, l, m, u, v);
        update(node << 1 | 1, m + 1, r, u, v);
        tree[node] = tree[node << 1] + tree[node << 1 | 1]; 
    }
    
    ll get() {
        return 1LL * tree[1];
    }
};

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        SegmentTree it(nums1);
        ll total = 0LL;
        
        for (int num : nums2) {
            total += 1LL * num;
        }
        
        int n = nums1.size();
        vector<ll> ans;
        
        for (auto query : queries) {
            int type = query[0];
            int l = query[1], r = query[2];
            if (type == 1) {
                it.update(1, 0, n - 1, l, r);
            }
            else if (type == 2) {
                total += 1LL * l * it.get();
            }
            else {
                ans.push_back(total);
            }
        }
        
        return ans;
    }
};