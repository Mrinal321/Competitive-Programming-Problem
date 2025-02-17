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
    ll n; cin >> n;
    ll a[n+1];
    map < ll, ll > m1, m2;
    loop(i, 1, n){
        cin >> a[i];
        m1[a[i]]++;
    }

    ll j = 1;
    set < ll > s1, s2;
    vector < ll > v;
    loop(i, 1, n){
        if(s2.count(a[i])) continue;
        m1[a[i]]--;
        m2[a[i]]++;
        if(m1[a[i]] == 0){
            ll val;
            while(1){
            if(v.size() % 2 == 0){
                val = m2.rbegin()->first;
                v.push_back(val);
                s2.insert(val);
                m2.erase(val);
            }
            else{
                val = m2.begin()->first;
                v.push_back(val);
                s2.insert(val);
                m2.erase(val);
            }
            while(1){
                if(a[j] == val){ 
                    j++;
                    break;
                }
                if(m2.count(a[j])) m2[a[j]]--;
                if(m2[a[j]] == 0) m2.erase(a[j]);
                j++;
            }

                if(val == a[i]) break;
            }
            m1.erase(a[i]);
        }
    }

    cout << v.size(); ed
    for(auto u : v) cout << u << " "; ed
}
 
int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}