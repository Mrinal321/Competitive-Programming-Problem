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
const ll N = 2e5 + 5;
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
    ll a[n+1], b[m+1];
    loop(i, 1, n) cin >> a[i];
    loop(i, 1, m) cin >> b[i];
    map < ll, ll > mp, mp2;
    int inx = n;
    loop2(i, m, 1){
        while(inx > 0 && a[inx] < b[i]) inx--;
        if(inx < 1) break;
        mp[i] = inx; inx--;
    }
    inx = 1;
    loop(i, 1, m){
        while(inx <= n && a[inx] < b[i]) inx++;
        if(inx > n) break;
        mp2[i] = inx; inx++;
    }
    //for(auto u : mp2) cout << u.first << " " << u.second << endl; ed
    //for(auto u : mp) cout << u.first << " " << u.second << endl;
    mp[m+1] = n+1; mp2[0] = 0;

    if(mp.count(1)){
        cout << "0\n"; return;
    }

    inx = 0; ll ans = M; a[0] = 0;
    loop(i, 1, m){
        if(mp.count(i+1) && mp2.count(i-1) && mp[i+1] > mp2[i-1]) {
            ans = min(ans, b[i]);
            //cout << inx; ed
        }
    }

    if(ans == M) cout << "-1";
    else cout << ans; ed
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}