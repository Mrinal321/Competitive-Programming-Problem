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
const ll N = 5e3 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/

ll a[35];
ll dp[35][31][31], last;

ll dfs(ll inx, ll val, ll baki){
    if(dp[inx][val][baki] != -1) return dp[inx][val][baki];
    ll ans = abs(val-a[inx]);
    if(inx == last) return ans;
    ll mn = M;
    loop(i, 0, 30){
        if(abs(val-i) <= baki){
            mn = min(mn, dfs(inx+1, i, baki-(abs(val-i))));
        }
    }
    dp[inx][val][baki] = mn+ans;
    return dp[inx][val][baki];
}

void solve(){
    ll n, q; cin >> n >> q;
    loop(i, 1, n) cin >> a[i];
    
    while(q--){
        ll l, k; cin >> l >> last >> k;
        memset(dp, -1, sizeof(dp));
        ll mx = M;
        loop(i, 0, 30){
            mx = min(mx, dfs(l, i, k));
        }
        cout << mx; ed
    }

}
 
int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}