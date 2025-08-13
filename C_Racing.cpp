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
#define mxheap                  priority_queue<ll>
#define mnheap                  priority_queue<ll, vector<ll>, greater<ll>>
#define mxheap2                 priority_queue<pair<ll,ll>>
#define mnheap2                 priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>
//Macros
#define FIO                     ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(NULL);
#define TC(t)                   int t; cin >> t; for(int i = 1; i <= t; i++)
#define loop(i, a, b)           for(ll i = a; i <= b; i++)
#define loop2(i, b, a)          for(ll i = b; i >= a; i--)
#define pn                      cout << "NO\n";
#define py                      cout << "YES\n";
#define ed                      cout << "\n";
#define flush                   cout.flush();
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

void solve(int t){
    ll n; cin >> n;
    ll a[n+1];
    loop(i, 1, n) cin >> a[i];
    ll b[n+1], c[n+1];
    loop(i, 1, n) cin >> b[i] >> c[i];
    ll h = 0, pow = 0;
    ll ans[n+1]; ans[0] = 0;
    ll pw[n+1]; pw[0] = 0;
    loop(i, 1, n){
        if(a[i] == -1) pow++;
        else if(a[i] == 1) h++;
        
        ll x = b[i]-h;
        if(pow < x){
            cout << "-1\n"; return;
        }
        if(x >= 0) {
            pow -= x;
            h = b[i];
        }
        x = c[i]-h;
        if(x < 0){
            cout << "-1\n"; return;
        }
        pow = min(pow, x);
        ans[i] = h; pw[i] = pow;
    }

    ll a2[n+1]; a2[0] = 0;
    loop(i, 1, n) a2[i] = ans[i]+pw[i];
    ll ans2[n+1];
    a2[n] = ans[n];
    loop2(i, n, 1){
        if(a2[i-1] < a2[i]) {
            ll x = a2[i]-a2[i-1];
            int j = i;
            while(j <= n && x > 0){
                if(a[j] != 0){
                    x--; ans2[j] = 1;
                }
                j++;
            }
            
        }
        else {
            a2[i-1] = a2[i];
            if(a[i] == -1) ans2[i] = 0;
            else ans2[i] = a[i];
        }
    }
    loop(i, 1, n) cout << ans2[i] << " ";
    ed
}

int main(){
    FIO
    TC(t) 
    solve(i);
    return 0;
}