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
    int n, qe; cin >> n >> qe;
    int a[n+1], b[n+1];
    loop(i, 1, n) {
        cin >> a[i]; b[a[i]] = i;
    }
    while(qe--){
        int l, r, val; cin >> l >> r >> val;
        int inx = b[val];
        if(inx > r || inx < l){
            cout << "-1 "; continue;
        }
        int c = 0, d = 0, t1 = 0, t2 = 0;
        while(r >= l){
            int mid = (l+r)/2;
            if(mid == inx) break;
            if(mid > inx && a[mid] < val) {
                c++; 
            }
            if(mid < inx && a[mid] > val) {
                d++;
            }
            if(mid > inx) r = mid-1;
            else l = mid+1;
            if(a[mid] < val) t1++;
            else t2++;
        }
        //cout << c << " " << d << " " << t1 << " " << t2; ed
        int x = abs(c-d);
        if(c > d){
            //cout << val+t2+x; ed
            if(val+t2+x > n) cout << "-1 ";
            else cout << c+d+x << " ";
        }
        else{
            if(val-t1-x < 1) cout << "-1 ";
            else cout << c+d+x << " ";
        }
    }
    ed
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}