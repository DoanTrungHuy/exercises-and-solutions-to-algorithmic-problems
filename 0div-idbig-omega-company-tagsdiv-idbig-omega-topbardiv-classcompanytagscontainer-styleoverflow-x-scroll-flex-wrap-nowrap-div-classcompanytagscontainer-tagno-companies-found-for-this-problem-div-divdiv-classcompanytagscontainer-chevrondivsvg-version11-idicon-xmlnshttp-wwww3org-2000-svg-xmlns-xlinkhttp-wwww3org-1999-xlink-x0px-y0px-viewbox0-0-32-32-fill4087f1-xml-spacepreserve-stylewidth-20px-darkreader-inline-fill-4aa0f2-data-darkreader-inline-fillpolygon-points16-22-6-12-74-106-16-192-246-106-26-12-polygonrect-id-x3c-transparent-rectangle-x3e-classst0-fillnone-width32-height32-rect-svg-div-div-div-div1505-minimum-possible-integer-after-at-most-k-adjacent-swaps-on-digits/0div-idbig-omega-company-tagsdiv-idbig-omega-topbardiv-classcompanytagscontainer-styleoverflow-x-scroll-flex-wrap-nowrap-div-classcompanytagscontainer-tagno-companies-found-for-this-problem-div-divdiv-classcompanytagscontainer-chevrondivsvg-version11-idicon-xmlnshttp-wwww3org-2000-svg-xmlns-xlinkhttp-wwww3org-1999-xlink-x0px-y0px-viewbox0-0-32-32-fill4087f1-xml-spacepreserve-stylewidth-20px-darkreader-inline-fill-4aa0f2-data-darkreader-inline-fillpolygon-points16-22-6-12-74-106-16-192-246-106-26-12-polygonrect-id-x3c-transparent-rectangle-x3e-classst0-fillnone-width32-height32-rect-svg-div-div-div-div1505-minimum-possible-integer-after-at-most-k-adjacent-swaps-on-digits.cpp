class Solution {
private:
    vector<int> tree;
    
public:
    void update(int node, int left, int right, int index, int value) {
        if (index < left or right < index) {
            return;
        }    
        if (left == right) {
            tree[node] = value;
            return;
        }
        int mid = (left + right) / 2;
        update(node*2, left, mid, index, value);
        update(node*2 + 1, mid + 1, right, index, value);
        tree[node] = tree[node*2] + tree[node*2 + 1];
    }
    
    int get(int node, int left, int right, int q_left, int q_right) {
        if (q_left > right or q_right < left) {
            return 0;
        }    
        if (q_left <= left and right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        int left_node = get(node*2, left, mid, q_left, q_right);
        int right_node = get(node*2 + 1, mid + 1, right, q_left, q_right);
        return left_node + right_node;
    }
    
    string minInteger(string num, int k) {
        map<int, vector<int>> um;
        const int n = num.size();
        
        for (int i = 0; i < n; ++i) {
            um[num[i] - '0'].push_back(i);
        }
        
        for (auto &[_, v] : um) {
            sort(v.begin(), v.end(), [&](int a, int b) {
                return a > b;
            });
        }
        
        string ans = "";
        tree.resize(4*n);
        
        for (int i = 0; i < n; ++i) {
            for (auto &[d, _] : um) {
                if (um[d].size()) {
                    int p_d = um[d].back();
                    
                    int shift = p_d - get(1, 0, n - 1, 0, p_d - 1);
                    
                    if (k - shift >= 0) {
                        k -= shift;
                        ans.push_back(d + '0');
                        um[d].pop_back();
                        update(1, 0, n - 1, p_d, 1);
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};