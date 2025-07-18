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

void solve(){
    ll n; cin >> n;
    ll a[n+1], dp[n+1], sum = 0;
    loop(i, 1, n) {
        cin >> a[i]; sum += a[i];
    }
    sort(a+1, a+n+1); reverse(a+1, a+n+1);
    //loop(i, 1, n) cout << a[i] << " "; ed
    dp[0] = 0;
    loop(i, 1, n) dp[i] = dp[i-1]+a[i];
    loop(c, 1, 2*n){
        ll coin = c;
        ll tot = 0;
        ll ans = dp[min(coin, n)];
        ll l = 0, r = coin/2;
        while(r-l > 5){
            ll m1 = l + (r - l) / 3;
            ll m2 = r - (r - l) / 3;

            ll c1 = coin - 2*m1;
            ll t1 = dp[m1] + m1*(m1-1)/2;
            ll tot1 = t1 + m1 * (min(m1+c1, n) - m1) + (dp[min(m1+c1, n)]-dp[m1]);

            ll c2 = coin - 2*m2;
            ll t2 = dp[m2] + m2*(m2-1)/2;
            ll tot2 = t2 + m2 * (min(m2+c2, n) - m2) + (dp[min(m2+c2, n)]-dp[m2]);

            if(tot1 >= tot2) r = m2;
            else l = m1;
        }

        loop(m1, l, r){
            ll c1 = coin - 2*m1;
            ll t1 = dp[m1] + m1*(m1-1)/2;
            ll tot1 = t1 + m1 * (min(m1+c1, n) - m1) + (dp[min(m1+c1, n)]-dp[m1]);
            ans = max(ans, tot1);
        }

        cout << ans << " ";
    }
    ed
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}