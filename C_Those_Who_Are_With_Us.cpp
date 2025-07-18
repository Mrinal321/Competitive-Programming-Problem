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
const ll N = 5e4 + 5;
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
    ll a[n+1][m+1], b[n+1][m+1], mx = 0;;
    loop(i, 1, n){
        loop(j, 1, m) {
            cin >> a[i][j]; b[i][j] = a[i][j];
            mx = max(mx, a[i][j]);
        }
    }
    vector < pair < int, int > > vp;
    loop(i, 1, n){
        loop(j, 1, m) {
            if(a[i][j] == mx) {
                vp.push_back({i, j});
            }
        }
    }

    if(vp.size() < 3){
        cout << mx-1; ed return;
    }

    int sz = vp.size();
    int x1 = -1, x2, y1, y2;
    for(int i = 1; i < sz; i++){
        if(vp[i].first != vp[0].first && vp[i].second != vp[0].second){
            x1 = vp[i].first; y1 = vp[0].second;
            x2 = vp[0].first; y2 = vp[i].second;
        }
    }

    if(x1 == -1){
        cout << mx-1; ed return;
    }

    // cout << x1 << " " << y1 << endl << x2 << " " << y2; ed
    // cout << sz; ed

    int c = 0;
    loop(i, 1, n){
        if(a[i][y1] == mx) c++;
    }
    loop(j, 1, m){
        if(a[x1][j] == mx) c++;
    }
    if(a[x1][y1] == mx) c--;
    
    if(c >= sz){
        cout << mx-1; ed return;
    }

    c = 0;
    loop(i, 1, n){
        if(a[i][y2] == mx) c++;
    }
    loop(j, 1, m){
        if(a[x2][j] == mx) c++;
    }
    if(a[x2][y2] == mx) c--;
    
    if(c >= sz){
        cout << mx-1; ed return;
    }

    cout << mx; ed
    
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}