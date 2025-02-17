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
const ll N = 1e6 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/

ll dp[N] = {0};

ll InclusionExclusion (ll n, int inx) {
    vector<ll> p;
    ll val = 1;
    for (ll i=2; i*i<=n; ++i)
        if (n % i == 0) {
            val *= i;
            p.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        p.push_back (n);
    
    if(inx == 1){
        for (ll msk=1; msk<(1<<p.size()); ++msk) {
            ll mult = 1,
                bits = 0;
            for (ll i=0; i<(ll)p.size(); ++i)
                if (msk & (1<<i)) {
                    ++bits;
                    mult *= p[i];
                }
            dp[mult] = 1;
            //cout << dp[mult] << " ";
        }
        return 1;
    }

    if(p.size() == 1) {
        dp[p[0]] = (dp[p[0]]+1) % M;
        return dp[p[0]];
    }

    ll sum = 0;
    //cout << "M : ";
    //for(auto u : p) cout << u << " "; ed
    for (ll msk=1; msk<(1<<p.size()); ++msk) {
        ll mult = 1,
            bits = 0;
        for (ll i=0; i<(ll)p.size(); ++i)
            if (msk & (1<<i)) {
                ++bits;
                mult *= p[i];
            }
        if (bits % 2 == 1)
            sum = (sum + dp[mult]) % M;
        else
            sum = (sum + M - dp[mult]) % M;
    }
    // cout << dp[val] << " " << sum; ed
    //dp[val] = (dp[val] + sum) % M;
    for (ll msk=1; msk<(1<<p.size()); ++msk) {
        ll mult = 1,
            bits = 0;
        for (ll i=0; i<(ll)p.size(); ++i)
            if (msk & (1<<i)) {
                ++bits;
                mult *= p[i];
            }
        dp[mult] = (dp[mult] + sum) % M;
        cout << dp[mult] << " ";
    } 
    ed
    //cout << dp[val];

    return dp[val];
}

void solve(){
    ll n; cin >> n;
    ll a[n+1];
    loop(i, 1, n){
        cin >> a[i];
    }

    loop(i, 1, n){
        //cin >> a[i];
        ll x = a[i];
        ll ans = InclusionExclusion(x, i);
        if(i == n){
            cout << ans; ed return;
        }
    }

}
 
int main(){
    FIO
    //TC(t) 
    solve();
    return 0;
}