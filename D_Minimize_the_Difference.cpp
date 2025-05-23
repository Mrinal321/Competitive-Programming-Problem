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
#define loop(i, a, b)           for(int i = a; i <= b; i++)
#define loop2(i, b, a)          for(int i = b; i >= a; i--)
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

void solve(){
    ll n; cin >> n;
    ll a[n+1], mn[n+1], mx[n+1];
    mn[0] = 1000000000000000; mx[0] = 0;
    ll dp[n+1]; dp[0] = 0;
    loop(i, 1, n){
        cin >> a[n-i+1];
        dp[i] = a[i] + dp[i-1];
    }
    loop(i, 1, n) dp[i] = a[i] + dp[i-1];
    // loop(i, 1, n){
    //     cout << a[i] << " ";
    // } ed
    
    ll m1 = 1000000000000000, m2 = 0;
    stack < pair < ll, ll > > st; st.push({m1, 0});
    loop(i, 1, n){
        while(1){
            ll x = st.top().first, y = st.top().second;
            ll sum = dp[i]-dp[y];
            ll inx = i-y;
            if(sum/inx < x){
                if(sum%inx) {
                    st.push({sum/inx+1, i-1});
                    st.push({sum/inx, i});
                }
                else st.push({sum/inx, i});
                break;
            }
            st.pop();
        }
    }
    ll p = st.top().first;
    ll q = p;
    while(1){
        if(st.top().first == m1) break;
        q = st.top().first;
        st.pop();
    }

    cout << q-p; ed
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}