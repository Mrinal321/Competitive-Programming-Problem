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
    ll n; cin >> n;
    ll a[n+1];
    map < ll, ll > mp;
    ll sum = 0, ans2;
    loop(i, 1, n) {
        cin >> a[i];
        mp[a[i]]++;
        sum += a[i];
    }
    ans2 = sum;

    ll mx = 0;
    loop(i, 0, n){
        if(!mp.count(i)){
            mx = i; break;
        }
        else if(mp[i] < 3){
            cout << "-1 -1\n"; return;
        }
    }

    if(mx == 0){
        ll mx = M, sum2 = 0;
        loop(i, 2, n-1){
            mx = min(mx, a[i]);
            sum2 += a[i];
        }

        cout << a[1]+a[n]-sum2 << " " << sum - 2*mx; ed return;
    }

    map < ll, ll > m1;
    set < ll > s;
    ll inx1, inx2;
    sum = 0;
    loop(i, 1, n){
        sum += a[i];
        if(a[i] < mx) s.insert(a[i]);
        if(s.size() == mx){
            inx1 = i; break;
        }
    }
    s.clear();
    loop2(i, n, 1){
        sum += a[i];
        if(a[i] < mx) s.insert(a[i]);
        if(s.size() == mx){
            inx2 = i; break;
        }
    }
    s.clear();
    loop(i, inx1+1, inx2-1){
        sum -= a[i];
        if(a[i] < mx) s.insert(a[i]);
    }

    //cout << inx1 << " " << inx2; ed

    if(s.size() != mx){
        cout << "-1 -1\n"; return;
    }


    map < ll, ll > m;
    ll tot = 0, ans = 10000000000000000;
    ll ix = inx1+1;
    loop(i, inx1+1, inx2-1){
        if(a[i] < mx) m[a[i]]++;
        tot += a[i];
        while(ix <= i){
            if(a[ix] >= mx){
                tot -= a[ix];
            }
            else if(m[a[ix]] > 1){
                tot -= a[ix];
                m[a[ix]]--;
            }
            else {
                break;
            }
            ix++;
        }

        if(m.size() == mx) ans = min(tot, ans);
    }

    //cout << ans; ed

    cout << sum << " " << ans2-2*ans; ed

}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}