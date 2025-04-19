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
    deque<ll> q0, q1;
    ll c = 0, ans0 = 0, ans1 = 0, sum0 = 0, sum1 = 0;
    ll qe; cin >> qe;
    while(qe--){
        ll op; cin >> op;
        if(op == 3){
            ll x; cin >> x;
            if(c%2){
                q1.push_back(x);
                sum1 += x;
                ans1 += (q1.size()*x);
                q0.push_front(x);
                sum0 += x;
                ans0 += sum0;
                cout << ans1; ed
            }
            else{
                q0.push_back(x);
                sum0 += x;
                ans0 += (q0.size()*x);
                q1.push_front(x);
                sum1 += x;
                ans1 += sum1;
                cout << ans0; ed
            }

        }
        else if(op == 2){
            c++; 
            if(c%2) cout << ans1; 
            else cout << ans0; ed
        }
        else{
            if(c%2){
                ans1 = ans1 + sum1 - (q1.size()* q1.back()); 
                q1.push_front(q1.back()); q1.pop_back();
                ans0 = ans0 + (q0.size()* q0.front()) - sum0;
                q0.push_back(q0.front()); q0.pop_front();
                cout << ans1; ed
            }
            else{
                ans0 = ans0 + sum0 - (q0.size()* q0.back()); 
                q0.push_front(q0.back()); q0.pop_back();
                ans1 = ans1 + (q1.size()* q1.front()) - sum1;
                q1.push_back(q1.front()); q1.pop_front();
                cout << ans0; ed
            }
        }

        //cout << ans0 << " " << ans1; ed
    }
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}