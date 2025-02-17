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
const ll N = 1e5 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/
vector < pair < ll, ll > > v[200005];
void solve(){
    ll n, m, q; cin >> n >> m >> q;
    ll a[n+1], b[m+1];
    loop(i, 1, n){
        v[i].clear();
        cin >> a[i];
    }
    set < ll > s, ans;
    stack < ll > st;
    loop2(i, n, 1){
        st.push(a[i]);
    }
    loop(i, 1, m){
        cin >> b[i];
    }

    int inx = 1;
    map < ll, ll > mp, m2;

    loop(i, 1, m){
        if(mp.count(b[i])) continue;
        mp[b[i]] = i;
        if(b[i] != a[inx]) m2[i] = a[inx];
        else inx++;
    }
    if(m2.empty()) ans.insert(0);
    loop(i, 1, q){
        ll x, y; cin >> x >> y;
        if(mp.count(b[x]) && mp[b[x]] == x){
            m2[x]=b[x];
            mp.erase(b[x]);
            continue;
        }
        mp[y] = x;
        auto u = m2.lower_bound(x);
        set < ll > ss;
        while(u != m2.end()){
            if(mp.count(u->second) && mp[u->second] <= u->first){
                ss.insert(u->first);
            }
            else break;
            u++;
        }
        for(auto u : ss) m2.erase(u);

        if(m2.empty()) ans.insert(i);
    }
    
    loop(i, 0, q){
        if(ans.count(i)) cout << "YA";
        else cout << "TIDAK"; ed
    }
}
 
int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}