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
    ll a[n+1], mp[n+1];
    loop(i, 1, n) {
        cin >> a[i]; mp[a[i]] = i;
    }
    ll dp[n+2], dp2[n+2]; dp[0] = 0; dp2[n+1] = 0;
    ordered_set os, os2; 
    loop(i, 1, n){
        int x = i - os.order_of_key(a[i]) - 1;
        dp[i] = x;
        os.insert(a[i]);
    }
    os.clear();
    loop2(i, n, 1){
        int x = n - i - os.order_of_key(a[i]);
        dp2[i] = x;
        os.insert(a[i]);
    }
    
    loop(i, 1, n){
        ll inx = mp[i];
        if(dp[inx] > dp2[inx]) a[inx] = 2*n - i;
    }
    os.clear();
    ll ans = 0;
    loop(i, 1, n){
        //cout << a[i] << " ";
        int x = i - os.order_of_key(a[i]) - 1;
        ans += x;
        os.insert(a[i]);
    }
    
    cout << ans; ed
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}