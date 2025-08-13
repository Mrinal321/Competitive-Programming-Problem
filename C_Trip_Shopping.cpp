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
const ll M = 1e10 + 7;
const ll N = 1e5 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n+1], b[n+1];
    loop(i, 1, n) cin >> a[i];
    multiset < ll > ms;
    ll ans = 0;
    vector < pair < ll, ll > > vp;
    loop(i, 1, n){
        cin >> b[i];
        ans += abs(a[i]-b[i]);
        ll mx = max(a[i], b[i]);
        ll mn = min(a[i], b[i]);
        ms.insert(mn);
        vp.push_back({mx, mn});
    }

    vsort(vp);
    ll ans2 = M;
    for(auto [x, y] : vp){
        ms.erase(ms.find(y));
        if(ms.empty()) break;
        ll z = *ms.begin();
        if(z <= x){
            ans2 = 0; break;
        }
        ans2 = min(ans2, 2*(z-x));
    }

    cout << ans+ans2; ed
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}