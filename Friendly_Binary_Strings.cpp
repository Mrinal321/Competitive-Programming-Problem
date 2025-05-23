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

void solve(){
    int n; cin >> n;
    string a, b; cin >> a >> b;
    if(n == 1){
        py return;
    }
    int p1 = 0, p0 = 0, s1 = 0, s0 = 0;
    int c = 0, d = 0;
    loop(i, 0, n-1){
        if(a[i] == b[i]){
            if(a[i] == '1') {
                p1++; c += 2;
            }
            else {
                p0++; d += 2;
            }
        }
        else{
            s1++; s0++;
            c++; d++;
        }
    }

    if(n%2){
        if(c%2==1 || d%2==1){
            if(c%4 == 1 && d%4 == 1) py 
            else pn
        }
        else py 
    }

    if(p1%2==1 && p0%2==1){
        if(s1 >= 2 ) s1 -= 2;
        else if(s0 >= 2) s0 -= 2;
        else pn
        if(c%2 == 0 && d%2 == 0 || n%2)
    }
    else{
        if(c%2 == 0 && d%2 == 0) py 
        else pn
    }
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}