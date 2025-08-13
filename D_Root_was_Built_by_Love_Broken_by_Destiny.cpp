#include<bits/stdc++.h>
using namespace std;

#define ll                      long long int
//Ordered set(tree)
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set             tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set       tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
template <typename T> using order_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//Macros
#define FIO                     ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(NULL);
#define TC(t)                   int t; cin >> t; for(int i = 1; i <= t; i++)
#define loop(i, a, b)           for(int i = a; i <= b; i++)
#define loop2(i, b, a)          for(int i = b; i >= a; i--)
#define pn                      cout << "NO\n";
#define py                      cout << "YES\n";
#define ed                      cout << "\n";
#define vrev(v)                 reverse(v.begin(),v.end());
#define vsort(v)                sort(v.begin(),v.end());
#define bits(x)                 __builtin_popcountll(x)
//Constants
const ll M = 1e9 + 7;
const ll N = 2e5 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/

bool isBipartite(int n, const vector<vector<int>>& graph) {
    vector<int> color(n + 1, -1);

    for (int start = 1; start <= n; ++start) {
        if (color[start] != -1) continue;

        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : graph[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

vector < int > g[N], vpar;
bool vis[N], no;
ll yes;

void dfs(int node){
    vis[node] = 1;
    int c = 0, d = 0;
    for(int u : g[node]){
        if(g[u].size() == 1) {
            c++;
            vis[u] = 1;
        }
        else{
            d++; if(!vis[u]) dfs(u);
        }
    }
    if(d > 2) no = 1;
    if(d > 0) yes++;
    if(c > 1) vpar.push_back(c);
}

ll parmutation[N+5];

void solve(){
    int n, m; cin >> n >> m;
    no = 0; vpar.clear();
    loop(i, 1, n){
        vis[i] = 0; g[i].clear();
    }
    vector<vector<int>> graph(n + 1);
    loop(i, 1, m){
        int x, y; cin >> x >> y;
        g[x].push_back(y); g[y].push_back(x);
        graph[x].push_back(y); graph[y].push_back(x);
    }
    if(n == 2){
        cout << "2\n"; return;
    }
    if(!isBipartite(n, graph) || m != n-1){
        cout << "0\n"; return;
    }

    int nd = 1;
    loop(i, 1, n){
        if(g[i].size() == 1){
            int nd = g[i][0]; break;
        }
    }

    yes = 0;
    dfs(nd);
    if(no){
        cout << "0\n"; return;
    }
    ll ans = 1;
    for(int x : vpar){
        ans = (ans * parmutation[x]) % M;
    }
    if(yes > 1) ans = (ans * 4) % M;
    else ans = (ans * 2) % M;
    cout << ans; ed
}

int main(){
    FIO
    parmutation[0] = 1;
    loop(i, 1, N) parmutation[i] = (i * parmutation[i-1]) % M;
    TC(t) 
    solve();
    return 0;
}