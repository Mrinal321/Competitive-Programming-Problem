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

set < int > g[N];

void solve(){
    int n; cin >> n;
    loop(i, 1, n) g[i].clear();
    loop(i, 2, n){
        int x, y; cin >> x >> y;
        g[x].insert(y); g[y].insert(x);
    }
    loop(i, 1, n){
        if(g[i].size() == 0){
            pn return;
        }
    }
    if(n == 2){
        pn return;
    }
    int inx = 1;
    vector < pair < int, int > > ans;
    set < int > in, out; 
    loop(i, 1, n){
        if(g[i].size() == 2) {
            inx = i;
            int v = *g[inx].begin();
            ans.push_back({v, inx});
            g[inx].erase(v); g[v].erase(inx);
            int v2 = *g[inx].begin();
            ans.push_back({inx, v2});
            g[v2].erase(inx); g[inx].erase(v2);
            in.insert(v2); out.insert(v);
            break;
        }
    }

    if(ans.empty()){
        pn return;
    }
 
    while(!out.empty() || !in.empty()){
        if(!out.empty()){
            int x = *out.begin();
            for(auto u : g[x]){
                g[u].erase(x); in.insert(u);
                ans.push_back({x, u});
            }
            out.erase(x); g[x].clear();
        }
        if(!in.empty()){
            int x = *in.begin();
            for(auto u : g[x]){
                g[u].erase(x); out.insert(u);
                ans.push_back({u, x});
            }
            in.erase(x); g[x].clear();
        }
    }
    py 
    for(auto [x, y] : ans){
        cout << x << " " << y; ed
    }
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}