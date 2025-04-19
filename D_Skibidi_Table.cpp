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
const ll N = 1e5 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/

void func(ll x, ll y){
    ll val = (1LL << 32);
    ll sum = 1;
    while(val){
        if(x > val || y > val){
            ll p = (x-1)/val + 1, q = (y-1)/val + 1;
            if(x > val) x -= val; 
            if(y > val) y -= val;
            //cout << val << " " << p << " " << q; ed
            if(p == 2 && q == 2) sum += (val*val);
            else if(p == 2 && q == 1) sum += (2*val*val);
            else if(p == 1 && q == 2) sum += (3*val*val);
        }
        val /= 2;
    }
    cout << sum; ed
}

void func2(ll sum2){
    ll x = 1, y = 1;
    ll val = (1LL << 30);
    ll sum = 1;
    while(val){
        if(sum + (3*val*val) <= sum2){
            sum += (3*val*val);
            y += val;
        }
        if(sum + (2*val*val) <= sum2){
            sum += (2*val*val);
            x += val;
        }
        if(sum + (val*val) <= sum2){
            sum += (val*val);
            x += val; y += val;
        }

        val /= 2;
    }

    cout << x << " " << y; ed
}

void solve(){
    ll n; cin >> n;
    ll qe; cin >> qe;
    cin.ignore(); // to proper use for getline
    while(qe--){
        string str;
        getline(cin, str);
        if(str[0] == '-'){
            ll x = 0, y = 0, xx = 1, yy = 1;
            while(str.back() != ' '){
                ll p = str.back() - '0';
                x += (p*xx); xx *= 10;
                str.pop_back();
            }
            while(str.back() == ' ') str.pop_back();
            while(str.back() != ' '){
                ll p = str.back() - '0';
                y += (p*yy); yy *= 10;
                str.pop_back();
            }
            //cout << x << " " << y; ed

            func(y, x);
        }
        else{
            ll x = 0, xx = 1;
            while(str.back() != ' '){
                ll p = str.back() - '0';
                x += (p*xx); xx *= 10;
                str.pop_back();
            }

            func2(x);
        }
    }
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}