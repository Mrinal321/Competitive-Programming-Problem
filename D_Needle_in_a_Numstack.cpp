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
// #define flush                   cout.flush();
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

ll ar[100];

void solve(){
    ll n, k; cin >> n >> k;

    if(2*k < n && k == 1){
        cout << "! " << "-1"; ed 
        cout.flush();
        return;
    }
    if(2*k == n){
        cout << "! " << k << " " << k; ed 
        cout.flush();
        return;
    }

    loop(i, 1, k){
        cout << "? "<< i << endl;
        ll val; cin >> val;
        ar[i] = val;
    }

    //loop(i, 1, k) cout << ar[i] << " "; ed

    ll l = 1, r = (n-1)/k;
    while(r-l > 3){
        ll mid = (l+r)/2;
        cout << "? " << mid*k+1 << endl;
        ll x; cin >> x;
        if(x == ar[1]) l = mid;
        else r = mid-1;
    }

    bool yes = 0;
    ll inx = 1;
    for(ll mid = l*k+1; mid <= n; mid++){
        cout << "? " << mid << endl;
        ll x; cin >> x;
        ll p = mid%k; if(p == 0) p == k;
        if(x != ar[inx]){
            if(n-mid+1 < k){
                mid = n-k+1;
            }
            cout << "! " << mid-1 << " " << n-mid+1; ed 
            yes = 1; break;
            
        }
        inx++; if(inx > k) inx = 1;
    }
    if(!yes){
        cout << "! " << "-1"; ed 
    }
    
    cout.flush();
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}