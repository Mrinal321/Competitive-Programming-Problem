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
const ll M = 998244353;
const ll N = 3e5 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/

void solve(int t){
    ll n; cin >> n;
    ll a[n+1];
    multiset < ll > ms;
    ll c = 0;
    loop(i, 1, n){
        cin >> a[i];
        if(a[i] == 0) c++;
        else ms.insert(a[i]);
    }
    
    if(c == 0){
        cout << n; ed return;
    }
    if(a[1] == 0){
        cout << ms.size() + 1; ed return;
    }
    
    ll ans = n - c;
    ll p = 0, val = 0;
    set < ll > s;
    //ms.erase(0);
    loop2(i, n, 1){
        if(a[i] > 0){
            //val++;
            ms.erase(ms.find(a[i]));
            s.insert(a[i]);
            while(s.count(val)) val++;
            if(!ms.empty() && *ms.begin() < val){
                //cout << i; ed
                cout << ans; ed return;
            }
        }
        else{
            c--;
            if(c == 0){
                ms.erase(0);
                s.insert(a[i]);
                while(s.count(val)) val++;
                if(!ms.empty() && *ms.begin() < val){
                    //cout << i << "M";
                    cout << ans; ed return;
                }
            }
        }
    }
    cout << ans+1; ed
}

int main(){
    FIO
    TC(t) 
    solve(i);
    return 0;
}