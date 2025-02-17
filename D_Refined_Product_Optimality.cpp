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
const ll N = 1e4 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/

void solve(){
    ll n, qe; cin >> n >> qe;
    ll a[n+1], b[n+1];
    loop(i, 1, n) cin >> a[i];
    loop(i, 1, n) cin >> b[i];
    multi_ordered_set s1, s2;
    loop(i, 1, n){
        s1.insert(a[i]); s2.insert(b[i]);
    }
    ll ans = 1;
    auto uu = s2.begin();
    for(auto u : s1){
        ll x = min(*uu, u);
        ans = (ans * x) % M;
        uu++;
    }
    //cout << ans << " ";
    //cout << s1.order_of_key(*s1.upper_bound(1)); ed
    s1.insert(2);
    for(auto u : s1) cout << u << " "; ed

    while(qe--){
        ll p, q; cin >> p >> q;
        if(p == 1){
            int i = s1.order_of_key(*s1.upper_bound(a[q]));
            int ii = s1.order_of_key(*s1.upper_bound(a[q]+1));
            int iii = s1.order_of_key(*s1.lower_bound(a[q]-1));
            if(ii == 0){
                ll val = min(*s2.find_by_order(i), *s1.find_by_order(i)+1);
                ll val2 = min(*s2.find_by_order(i), *s1.find_by_order(i));
                ans = (ans * val) % M;
                val2 = POW(val2, M-2);
                ans = (ans * val2) % M;
            }
            else{
                ll val = min(*s2.find_by_order(i), *s1.find_by_order(i)+1);
                ll val2 = min(*s2.find_by_order(i), *s1.find_by_order(i));
                ans = (ans * val) % M;
                val2 = POW(val2, M-2);
                ans = (ans * val2) % M;
            }
            cout << i << " " << ii << " " << iii; ed
        }
    }

}
 
int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}