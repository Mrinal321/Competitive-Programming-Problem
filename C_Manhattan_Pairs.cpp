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

void solve(){
    ll n; cin >> n;
    vector < pair < ll, pair < ll, ll > > > vp1, vp2;
    loop(i, 1, n){
        ll x, y; cin >> x >> y;
        vp1.push_back({x, {y, i}});
        vp2.push_back({y, {x, i}});
    }

    vsort(vp1); vsort(vp2);
    ll ans1 = 0;
    multiset < pair < ll, ll > > s1, s2;
    loop(i, 0, n/2-1){
        //ans1 += (abs(vp1[i+n/2].first-vp1[i].first));
        s1.insert({vp1[i].second.first, vp1[i].second.second}); s2.insert({vp1[i+n/2].second.first, vp1[i+n/2].second.second});
    }

    auto uu = s2.rbegin();

    for(auto u : s1){
        //ans1 += (abs (u - *uu)); uu++;
        cout << u.second << " " << uu->second; ed
        uu++;
    }

    //cout << ans1; ed
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}