#include<bits/stdc++.h>
using namespace std;
 
#define ll                      long long int
#define lld                     long double
//Ordered set(tree)
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set             tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set       tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
template <typename T> using order_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define mxheap                  priority_queue<ll>
#define mnheap                  priority_queue<ll, vector<ll>, greater<ll>>
#define mxheap2                 priority_queue<pair<ll,ll>>
#define mnheap2                 priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>
//Macros
#define FIO                     ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(NULL);
#define TC(t)                   int t; cin >> t; for(int i = 1; i <= t; i++)
#define ini(x, y)               memset(x, y, sizeof(x))
#define loop(i, a, b)           for(ll i = a; i <= b; i++)
#define loop2(i, b, a)          for(ll i = b; i >= a; i--)
#define pn                      cout << "NO\n";
#define py                      cout << "YES\n";
#define ed                      cout << "\n";
#define flush                   cout.flush();
#define vrev(v)                 reverse(v.begin(),v.end());
#define vsort(v)                sort(v.begin(),v.end());
#define uni(v)                  v.erase(unique(v.begin(), v.end()), v.end()); // last it is like e set
#define vlowerB(v,x)            lower_bound(v.begin(), v.end(), x); 
#define vupperB(v,x)            upper_bound(v.begin(), v.end(), x); 
#define bits(x)                 __builtin_popcountll(x)
#define zrbits(x)               __builtin_ctzll(x)
//Constants
const ll M = 1e9;
const ll N = 1e5 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/

vector<int> graph[N], g[N], g2[N];
bool visited[N];
bool in_stack[N];
bool vis[N] = {0};
set<pair<int, int>> seen; // to ignore duplicate edges

bool dfs(int node) {
    visited[node] = true;
    in_stack[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor] && vis[neighbor]) {
            if (dfs(neighbor)) return true;
        } else if (in_stack[neighbor]) {
            return true; // cycle found in the current path
        }
    }

    in_stack[node] = false;
    return false;
}

void dfs2(int node){
    vis[node] = 1;
    for(auto u : g2[node]){
        if(!vis[u]) dfs2(u);
    }
}

int dp[N];
int func(int node){
    if(!vis[node]) return 0;
    if(dp[node] != -1) return dp[node];
    int ans = 0;
    for(auto x : g[node]){
        ans = (ans+func(x)) % M;
    }
    return dp[node] = ans;
}

void solve(){
    int n, m; cin >> n >> m;
    // Clean up
    memset(visited, 0, sizeof(visited));
    memset(in_stack, 0, sizeof(in_stack));

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g2[v].push_back(u);
        graph[u].push_back(v);
    }
    dfs2(n);
    
    if (dfs(1)){
        cout << "INFINITE PATHS\n"; return;
    }
    loop(i, 1, n-1) dp[i] = -1;
    dp[n] = 1;
    cout << func(1); ed
    //loop(i, 1, n) cout << dp[i] << " "; ed
}

int main(){
    FIO
    //TC(t) 
    solve();
    return 0;
}