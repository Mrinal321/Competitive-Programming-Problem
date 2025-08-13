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
    int n; cin >> n;
    int a[n+2], b[n+2], dp[n+2], dp2[n+2];
    loop(i, 1, n) cin >> a[i];
    loop(i, 1, n) cin >> b[i]; b[n+1] = 2*n+2;
    dp[0] = 2*n+1;
    loop(i, 1, n) dp[i] = min(dp[i-1], b[i]);
    dp2[n+1] = 0;
    loop2(i, n, 1) dp2[i] = max(dp2[i+1], a[i]);
    
    int l = 1, r = n;
    while(r-l > 10){
        int md = (l+r)/2;
        set < int > s;
        loop(i, 1, md) s.insert(a[i]); s.insert(dp2[md+1]);
        s.erase(s.begin());
        if(*s.begin() >= dp[n-md+1]) l = md;
        else r = md-1;
    }

    loop2(md, r, l){
        set < int > s;
        loop(i, 1, md) s.insert(a[i]); s.insert(dp2[md+1]);
        s.erase(s.begin());
        if(*s.begin() >= dp[n-md+1]){
            cout << md; ed return;
        }
    }
    cout << "0\n";
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}