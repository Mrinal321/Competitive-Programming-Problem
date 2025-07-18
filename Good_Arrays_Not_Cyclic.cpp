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
const ll N = 5e5 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/

ll big[5205], small[5205], dp[5205], temp[5205];

void solve(){
    ll n; cin >> n;
    string a[n];
    ll tot = 1;
    loop(i, 0, n-1) {
        cin >> a[i];
    }

    ll ans = 0;
    loop(row, 0, n/2){
        memset(big, 0, sizeof(big));
        memset(small, 0, sizeof(small));
        big[0] = 1; small[0] = 1;
        
        loop(i, row, row+n/2-1){
            memset(temp, 0, sizeof(temp));
            loop(j, 0, n-1){
                if(a[i%n][j] == '0') continue;
                ll val = j+1;
                loop2(inx, 5000, val){
                    if(big[inx-val]) {
                        temp[inx] = (temp[inx] + big[inx-val])%M;
                    }
                }
            }
            loop(inx, 0, 5000) big[inx] = temp[inx];
        }
        
        loop(i, row+n/2, row+n-1){
            memset(temp, 0, sizeof(temp));
            loop(j, 0, n-1){
                if(a[i%n][j] == '0') continue;
                ll val = j+1;
                loop2(inx, 5000, val){
                    if(small[inx-val]) {
                        temp[inx] = (temp[inx] + small[inx-val])%M;
                    }
                }
            }
            loop(inx, 0, 5000) small[inx] = temp[inx];
        }

        dp[0] = 0;
        loop(l, 1, 5000) dp[l] = (dp[l-1]+small[l]) % M;
        loop(inx, 1, 5000){
            ans = (ans + dp[inx-1]*big[inx]) % M;
        }
    }

    cout << ans; ed
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}