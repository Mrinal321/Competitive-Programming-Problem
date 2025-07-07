#include<bits/stdc++.h>
using namespace std;
 
#define ll                      long long int
const ll N = 1e5 + 5;

vector < int > g[N];
int arr[N];
bool vis[N];
vector < int > st;

void dfs(int node){
    vis[node] = 1;
    st.push_back(arr[node]);
    for(auto u : g[node]){
        if(!vis[u]) dfs(u);
    }
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++){
        vis[i] = 0; g[i].clear();
    }
    while(m--){
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    vector < vector < int > > v;
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        st.clear();
        dfs(i);
        v.push_back(st);
    }

    int sz = v.size(); k++;
    if(k > sz) k = sz;
    //cout << sz; ed
    int bitmask = (1 << sz);
    int ans = 0;
    for(int mask = 0; mask < bitmask; mask++){
        if(__builtin_popcountll(mask) != k) continue;
        if((mask & 1) != 1) continue;
        set < int > val;
        for(int bit = 0; bit < sz; bit++){
            if(((1 << bit) & mask)){
                for(auto u : v[bit]) val.insert(u);
            }
        }
        for(int i = 0; ; i++){
            if(!val.count(i)){
                ans = max(ans, i); break;
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    solve();
    return 0;
}