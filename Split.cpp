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
//Macros
#define FIO                     ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(NULL);
#define TC(t)                   int t; cin >> t; for(int i = 1; i <= t; i++)
#define loop(i, a, b)           for(int i = a; i <= b; i++)
#define loop2(i, b, a)          for(int i = b; i >= a; i--)
#define pn                      cout << "NO\n";
#define py                      cout << "YES\n";
#define ed                      cout << "\n";
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

int n, k; 
string a; 

bool func(int md){
    int c0 = 0, c1 = 0, t = 0;
    loop(i, 0, n-1){
        if(a[i] == '0') c0++;
        else c1 = max(c0+1, c1+1);
        if(c0 >= md || c1 >= md){
            c0 = 0; c1 = 0; t++;
        }
    }
    if(t >= k) return 1;
    return 0;
}

void solve(){
    cin >> n >> k;
    cin >> a;
    int l = 1, r = n/k;
    while(r-l > 10){
        int md = (l+r)/2;
        if(func(md)) l = md;
        else r = md+1;
    }

    loop2(md, r, l){
        if(func(md)){
            cout << md; ed return;
        }
    }
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}