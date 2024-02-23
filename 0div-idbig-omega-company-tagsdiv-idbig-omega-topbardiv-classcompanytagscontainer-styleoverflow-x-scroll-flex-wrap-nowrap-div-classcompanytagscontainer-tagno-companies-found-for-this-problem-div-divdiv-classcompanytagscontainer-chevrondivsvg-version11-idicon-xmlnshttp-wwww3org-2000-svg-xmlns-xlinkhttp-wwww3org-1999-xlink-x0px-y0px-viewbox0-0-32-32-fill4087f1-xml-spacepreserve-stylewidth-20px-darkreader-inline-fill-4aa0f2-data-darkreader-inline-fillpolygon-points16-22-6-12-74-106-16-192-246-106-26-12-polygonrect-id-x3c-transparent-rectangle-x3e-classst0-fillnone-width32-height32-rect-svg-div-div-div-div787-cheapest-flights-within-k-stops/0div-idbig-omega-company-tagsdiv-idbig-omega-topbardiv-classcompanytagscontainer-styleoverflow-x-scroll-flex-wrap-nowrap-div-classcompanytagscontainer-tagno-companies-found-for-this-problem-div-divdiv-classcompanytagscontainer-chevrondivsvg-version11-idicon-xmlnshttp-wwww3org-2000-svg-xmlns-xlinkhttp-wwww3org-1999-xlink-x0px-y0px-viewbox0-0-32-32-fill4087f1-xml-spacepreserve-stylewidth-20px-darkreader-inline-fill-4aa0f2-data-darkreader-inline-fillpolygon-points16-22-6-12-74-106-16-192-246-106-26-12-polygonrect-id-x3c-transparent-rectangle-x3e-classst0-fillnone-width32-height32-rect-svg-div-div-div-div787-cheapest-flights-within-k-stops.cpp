class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int> flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            adj[u].push_back({v, w});
        }
        queue<tuple<int, int, int>> mq;
        const int oo = 1e9;
        vector<int> dist(n, oo);
        mq.push({0, src, k + 1});
        dist[src] = 0;
        while (!mq.empty()) {
            auto [cost, u, remaining] = mq.front();
            mq.pop();
            if (!remaining) {
                continue;
            }
            for (pair<int, int> um : adj[u]) {
                auto [v, w] = um;
                if (dist[v] > cost + w) {
                    dist[v] = cost + w;
                    mq.push({dist[v], v, remaining - 1});
                }
            }
        }
        return dist[dst] == oo ? -1 : dist[dst];
    }
};