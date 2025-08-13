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
    ll n, m; cin >> n >> m;
    ll a[n+1], b[n+1];
    set < ll > s0, s1;
    loop(i, 1, n) cin >> a[i];
    loop(i, 1, m){
        cin >> b[i];
        if(b[i] == 0) s0.insert(i);
        else s1.insert(i);
    }

    ll ans = 0;
    loop(i, 1, n){
        if(a[i] == 0){
            if(s0.empty() || *s0.begin() > i) continue;
            auto u = s0.lower_bound(i+1); u--;
            ll x = i-*u;
            //cout << x; ed
            if(x <= ans) ans++;
        }
        else{
            if(s1.empty() || *s1.begin() > i) continue;
            auto u = s1.lower_bound(i+1); u--;
            ll x = i-*u;
            //cout << x; ed
            if(x <= ans) ans++;
        }
    }
    cout << n-ans; ed
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}