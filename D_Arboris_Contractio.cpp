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

vector < int > g[N];
bool vis[N];
int single, ans;

void dfs(int node){
    int c = 0;
    vis[node] = 1;
    if(g[node].size() == 1) c++;
    for(int nd : g[node]){
        if(g[nd].size() == 1) c++;
        if(!vis[nd]) dfs(nd);
    }
    ans = min(ans, single-c);
}

void solve(){
    ll n; cin >> n;
    loop(i, 1, n){
        vis[i] = 0; g[i].clear();
    }
    loop(i, 1, n-1){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if(n <= 3){
        cout << "0\n"; return;
    }

    single = 0; ans = n;
    loop(i, 1, n){
        if(g[i].size() == 1) single++;
    }

    dfs(1);
    cout << ans; ed
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}