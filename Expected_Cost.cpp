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
    ll n; cin >> n;
    ll a[n+1], b[n+1];
    loop(i, 1, n) cin >> a[i];
    loop(i, 1, n) cin >> b[i];
    long double dp[n+2], pre[n+2]; dp[1] = pre[1] = 0;
    loop(i, 1, n) {
        pre[i+1] = dp[i+1] = dp[i]+a[i];
    }
    loop(i, 2, n+1){
        dp[i] = min(dp[i], dp[i-1] + a[i-1]);
        long double x = b[i]*(n+1); int c = 1;
        loop2(j, n+1, i){
            dp[j] = min(dp[j], dp[i-1] + pre[j] - pre[i-1]);
            if(dp[j] <= dp[i-1]+x/c) break;
            dp[j] = dp[i-1]+x/c;
            c++;
        }
        loop(j, 1, n+1) cout << dp[j] << " "; ed
    }
    cout << dp[n+1]; ed
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}