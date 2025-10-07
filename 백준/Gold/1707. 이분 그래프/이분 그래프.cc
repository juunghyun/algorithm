#include<bits/stdc++.h>

using namespace std;

// 0: not visited, 1: group A, -1: group B
int group[20001];
vector<int> adj[20001];
int V, E;

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    group[start] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adj[current]) {
            if (group[neighbor] == 0) {
                group[neighbor] = group[current] * -1;
                q.push(neighbor);
            } else if (group[neighbor] == group[current]) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    cin >> V >> E;

    for (int i = 1; i <= V; i++) {
        adj[i].clear();
        group[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isBipartite = true;
    for (int i = 1; i <= V; i++) {
        if (group[i] == 0) {
            if (!bfs(i)) {
                isBipartite = false;
                break;
            }
        }
    }

    if (isBipartite) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;
    while (K--) {
        solve();
    }

    return 0;
}