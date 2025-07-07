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
const ll M = 505;
const ll N = 1e4 + 5;

int arr[N], frute[N];
int total[M];

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++) cin >> frute[i];
    int dp[1005], total[1005];
    for(int i = 1; i <= 1000; i++) {
        dp[i] = 0; total[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        int mx = 0, val = arr[i];
        for(int j = 1; j <= val; j++) mx = max(total[j], mx);
        if(mx == 0){
            total[val] = frute[i];
            dp[val] = 1;
        }
        else{
            int tot = 0;
            for(int j = 1; j <= val; j++){
                if(total[j] == mx) tot += dp[j];
            }
            cout << mx; ed
            total[val] = frute[i] + mx;
            dp[val] = tot;
        }
    }
    
    int ans = 0, mx = 0;
    for(int i = 1; i <= 1000; i++) mx = max(mx, total[i]);
    for(int i = 1; i <= 1000; i++){
        if(mx == total[i]) ans += dp[i];
    }
    cout << mx << " " << ans; ed
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}