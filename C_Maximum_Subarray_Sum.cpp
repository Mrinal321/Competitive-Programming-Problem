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
const ll M = 1e18;
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
    ll n, k; cin >> n >> k;
    string a; cin >> a;
    ll b[n+1], dp[n+1];
    ll mx = 0, inx = 0, sum = 0;
    loop(i, 0, n-1){
        cin >> b[i]; 
        sum += b[i]; 
        if(sum <= 0) sum = 0;
        if(sum > mx){
            mx = sum; inx = i;
        }
        dp[i] = sum;
    }

    if(mx >= k){
        ll mx2 = 0, c = 0, sum = 0;
        vector < int > v;
        loop(i, 0, n-1){
            if(a[i] == '0') {
                v.push_back(i);
                sum = 0;
            }
            sum += b[i];
            if(sum <= 0) sum = 0;
            if(sum > k){
                pn return;
            }
        }
        if(v.empty()){
            py 
            loop(i, 0, n-1) cout << b[i] << " "; ed
            return;
        }
        ll p = dp[v[0]]; mx2 = dp[v[0]];
        loop(j, v[0]+1, n-1){
            if(a[j] == '0') break;
            p += b[j];
            mx2 = max(p, mx2);
        }
        b[v[0]] = k-mx2;
        loop(i, 1, v.size()-1) b[v[i]] = -M;

        py 
        loop(i, 0, n-1) cout << b[i] << " "; ed
    }
    else{
        bool yes = 0;
        loop(i, 0, n-1){
            if(a[i] == '0'){
                ll p = dp[i], mx2 = dp[i];
                loop(j, i+1, n-1){
                    p += b[j];
                    mx2 = max(p, mx2);
                }
                yes = 1;
                b[i] = k-mx2; break;
            }
        }
        if(!yes) pn 
        else{
            py 
            loop(i, 0, n-1) cout << b[i] << " "; ed
        }
    }
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}