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
    ll n, m; cin >> n >> m;

    ll p = 1;
    set < ll > s;
    while(p <= n){
        if((p&n)) cout << "1";
        else cout << "0";
        p *= 2;
    } 
    ed
    p = 1;
    while(p <= m){
        if((p&m)) cout << "1";
        else cout << "0";
        p *= 2;
    } 
    ed

    ll x = 1, ans = 0;
    while(x < M){
        if((x&n) != 0 && (x&m) != 0){
            ll ch = 0;
            ll high = x;
            while(high < M){
                if((high&n&m) == 0){
                    if((high&n) == 0 && (high&m) == 0) ch = 1;
                    else if((high&n) == 0) ch = 2;
                    else if((high&m) == 0) ch = 3;
                    break;
                }
                high *= 2;
            }
            cout << ch; ed

            ll low = x;
            bool yes = 0;
            while(1){
                if(ch == 1){
                    if((low&n) == 0 && (low&m) == 0){
                        if(s.count(low)){
                            cout << "-1\n"; return;
                        }
                        ans += low; s.insert(low);
                    }
                    if((low&n) == 0 || (low&m) == 0){
                        if(s.count(low)){
                            cout << "-1\n"; return;
                        }
                        ans += low; s.insert(low);
                        yes = 1;
                        break;
                    }
                }
                else if(ch == 2){
                    if((low&m) == 0){
                        if(low == 0) low = 1;
                        else low *= 2;
                        if(s.count(low)){
                            cout << "-1\n"; return;
                        }
                        ans += low; s.insert(low);
                        yes = 1;
                        break;
                    }
                }
                else if(ch == 3){
                    if((low&n) == 0){
                        if(low == 0) low = 1;
                        else low *= 2;
                        if(s.count(low)){
                            cout << "-1\n"; return;
                        }
                        ans += low; s.insert(low);
                        yes = 1;
                        break;
                    }
                }
                if(low == 0) break;
                low /= 2;
            }
            cout << ch; ed

            if(!yes){
                cout << "-1\n"; return;
            }

            x = high;
            
        }
        x *= 2;
    }

    cout << ans; ed
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}