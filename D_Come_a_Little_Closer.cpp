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
    ll n; cin >> n;
    vector < pair < ll, ll > > vp1, vp2;
    loop(i, 1, n){
        ll x, y; cin >> x >> y;
        vp1.push_back({x, y}); vp2.push_back({y, x});
    }
    if(n <= 2){
        cout << n; ed return;
    }
    vsort(vp1); vsort(vp2);
    ll p1 = 0, p2 = M, p3 = 0, p4 = M;
    ll q1 = 0, q2 = M, q3 = 0, q4 = M;
    // cout << vp1[0].first << " " << vp1[0].second; ed
    // cout << vp1[n-1].first << " " << vp1[n-1].second; ed
    // cout << vp2[0].first << " " << vp2[0].second; ed
    // cout << vp2[n-1].first << " " << vp2[n-1].second; ed
    
    loop(i, 0, n-2){
        p1 = max(p1, vp1[i].first); p3 = max(p3, vp1[i].second); 
        p2 = min(p2, vp1[i].first); p4 = min(p4, vp1[i].second); 
        q1 = max(q1, vp2[i].first); q3 = max(q3, vp2[i].second); 
        q2 = min(q2, vp2[i].first); q4 = min(q4, vp2[i].second); 
    }
    ll x = (p1-p2+1)*(p3-p4+1); 
    if(x < n) x += min((p1-p2+1), (p3-p4+1));
    ll y = (q1-q2+1)*(q3-q4+1); 
    if(y < n) y += min((q1-q2+1), (q3-q4+1));
    ll ans1 = min(x, y);

    p1 = 0; p2 = M; p3 = 0; p4 = M;
    q1 = 0; q2 = M; q3 = 0; q4 = M;
    loop(i, 1, n-1){
        p1 = max(p1, vp1[i].first); p3 = max(p3, vp1[i].second); 
        p2 = min(p2, vp1[i].first); p4 = min(p4, vp1[i].second); 
        q1 = max(q1, vp2[i].first); q3 = max(q3, vp2[i].second); 
        q2 = min(q2, vp2[i].first); q4 = min(q4, vp2[i].second); 
    }
    x = (p1-p2+1)*(p3-p4+1); 
    if(x < n) x += min((p1-p2+1), (p3-p4+1));
    y = (q1-q2+1)*(q3-q4+1); 
    if(y < n) y += min((q1-q2+1), (q3-q4+1));
    ll ans2 = min(x, y);

    cout << min(ans1, ans2); ed
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}