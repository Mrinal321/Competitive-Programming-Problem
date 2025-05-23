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

    ll x = 1;
    while(x <= n){
        if((x&m)) cout << 1;
        else cout << 0;
        x *= 2;
    } ed
    x = 1;
    while(x <= n){
        if((x&n)) cout << 1;
        else cout << 0;
        x *= 2;
    }

    ll p = 1, ans = 0;
    set < ll > s;
    

    while(p <= m || p <= n){
        if((p&m)== 0 || (p&n) == 0) {
            p *= 2;
            continue;
        }
        ll x = p;
        bool yes = 0;
        while(x <= m || x <= n){
            if((x&m) == 0 && (x&n) == 0) {
                break;
            }
            else if((x&m) == 0 || (x&n) == 0){
                ans += p; s.insert(p);
                n += p; m += p;
                p = x; yes = 1; break;
            }
            x *= 2;
        }

        if(p > 1 && (((p/2)&n) ^ ((p/2)&m)) != 0){
            //cout << p; ed
            ll c = 1; if(((p/2)&m) != 0) c = 2;
            ll x = p; p/=2;
            while(x <= m && x <= n){
                if((x&m) == 0 && (x&n) == 0) {
                    ans += p; s.insert(p);
                    n += p; m += p;
                    p = x; yes = 1; break;
                }
                else if(((x&m) == 0 && c == 2) || ((x&n) == 0 && c == 1)){
                    break;
                }
                x *= 2;
            }
            
        }

        if(!yes){
            cout << "-1\n"; return;
        }


        p *= 2;
    }

    cout << ans; ed
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}