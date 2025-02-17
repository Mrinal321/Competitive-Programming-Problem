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
const ll N = 5e3 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/

void solve(){
    ll n, k; cin >> n >> k;
    ll sum = 0, tot = 0;
    vector < pair < int, int > > vp;
    multiset < pair < int, int > > sp;
    loop(i, 1, n){
        ll p, q; cin >> p >> q;
        if(p > q) swap(p, q);
        sum += (p*q);
        tot += (p+q);
        vp.push_back({p*q, p});
    }

    if(tot < k){
        cout << "-1\n"; return;
    }
    if(tot == k){
        cout << sum; ed return;
    }
    tot -= k;
    vsort(vp); vrev(vp);
    ll ans = sum;
    for(auto [xy, x] : vp){
        tot -= (x+xy/x);
        sum -= xy;
        sp.insert({x, xy/x});
        ll tot2 = tot, sum2 = sum; 
        if(tot < 0){
            //cout << x << " " << xy/x << " " << sum2; ed

            for(auto [p, q] : sp){
                if(p+q + tot2 < 0){
                    tot2 += (p+q);
                    sum2 += (p*q);
                }
                else{
                    ll baki = p+q+tot;
                    if(baki <= 1) {
                        sum2 += (p*q);
                        break;
                    }
                    ll c = baki/2; ll d = baki-c;
                    if(c > p){
                        c = p;
                        d = baki-c;
                    }
                    sum2 += (p*q - c*d);
                    break;
                }
            }
        }
        //cout << sum2; ed
        ans = min(ans, sum2);
    }
    cout << ans; ed
}
 
int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}