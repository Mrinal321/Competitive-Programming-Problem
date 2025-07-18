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

vector < pair < int, int > > g[N];
int root[N], a[N];
map < int, int > mp[N];
map < pair < int, int >, int > pr;
ll sum;
void dfs(int node, int rt){
    root[node] = rt;
    for(auto [x, y] : g[node]){
        if(x == rt) continue;
        mp[node][a[x]]+=y;
        //cout << a[x] << " " << a[node]; ed
        if(a[node] != a[x]) sum += y;
        dfs(x, node);
    }
}

void solve(){
    int n, q; cin >> n >> q;
    loop(i, 1, n) {
        cin >> a[i];
        g[i].clear();
        mp[i].clear();
    }
    loop(i, 2, n){
        int x, y, z; cin >> x >> y >> z;
        pr[{x, y}] = z; pr[{y, x}] = z;
        g[x].push_back({y, z}); g[y].push_back({x, z});
    }

    sum = 0;
    dfs(1, 0);
    
    while(q--){
        int nd, val1, val2; cin >> nd >> val2;
        if(val1 == val2){
            cout << sum; ed continue;
        }
        ll pre = mp[nd][val1];
        ll now = mp[nd][val2];
        cout << val1 << " " << pre << " " << now; ed
        sum += (pre - now);
        cout << sum; ed
        if(nd != 1){
            int nrt = root[nd];
            int ct = pr[{nrt, nd}];
            if(a[nrt] == val2) {
                sum -= ct;
                mp[nrt][val2] += ct;
            }
            else {
                sum += ct;
                mp[nrt][val1] += ct;
            }
            //mp[nrt][val2] -= ct;
            //mp[nrt][val2] += ct;
        }

        mp[nd][val1] -= pr[{}]
        mp[nd][val2]
        a[nd] = val2;

        cout << mp[1][2] << " " << mp[2][2]; ed

        cout << sum; ed
    }
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}