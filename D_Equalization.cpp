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

void solve(int t){
    ll n, m; cin >> n >> m;
    ll x = 1;
    string a, b, c, d;
    while(x <= n){
        if((x&n)) a.push_back('1');
        else a.push_back('0');
        x *= 2;
    }
    x = 1;
    while(x <= m){
        if((x&m)) b.push_back('1');
        else b.push_back('0');
        x *= 2;
    }
    c = a; d = b;

    while(!a.empty() && !b.empty()){
        if(a.back() == b.back()){
            a.pop_back(); b.pop_back();
        }
        else break;
    }

    ll sum = a.size() + b.size();
    //cout << sum; ed
    ll p = sqrt(sum);
    while(1){
        if(p*(p+1)/2 >= sum) break;
        p++;
    }
    ll baki = p*(p+1)/2 - sum;

    if(baki == 2 && (a.size() == 2 || b.size() == 2)) baki = 0;
    if(baki == 1 && (a.size() == 1 || b.size() == 1)){
        if(c.size() + d.size() <= 5){
            cout << "12\n"; return;
        }
        if(sum == 2){
            cout << "14\n"; return;
        }
        ll ans = 2;
        loop(i, 3, p-1) ans += POW(2, i);
        ans += POW(2, p+1);
        cout << ans; ed return;
    }
    
    ll ans = 0;
    loop(i, 1, p){
        if(i == baki) continue;
        ans += POW(2, i);
    }

    cout << ans; ed
    //cout << a << "\n\n" << b; ed
}

int main(){
    FIO
    TC(t) 
    solve(i);
    return 0;
}