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
const ll N = 1e5 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/

vector < ll > g[N];

void solve(){
    ll n, qe; cin >> n >> qe;
    ll a[n+1];
    //set < ll > ck;
    loop(i, 1, n){
        cin >> a[i];
        g[a[i]].push_back(i);
    }

    while(qe--){
        ll val, l, r; cin >> val >> l >> r;
        ll ans = 0;
        set < ll > s;
        for(ll i = 2; i*i <= val; i++){
            if(val%i == 0){
                s.insert(val/i); s.insert(i);
            }
        } s.insert(val);
        while(1){
            set < ll > ss;
            ll inx = n+1, div = 1;
            for(auto u : s){
                auto uu = lower_bound(g[u].begin(), g[u].end(), l); 
                if(uu != g[u].end() && *uu < inx){
                    div = u; inx = *uu;
                }
            }
            if(inx > r){
                ans += ((r-l+1)*val); break;
            }
            ans += ((inx-l)*val);
            while(val%div == 0) val /= div;
            l = inx;
            for(auto u: s){
                if(val%u) ss.insert(u);
            }
            for(auto u : ss) s.erase(u);
        }
        cout << ans; ed
    }

    loop(i, 1, n) g[a[i]].clear();
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}