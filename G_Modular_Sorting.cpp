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
#define mxheap                  priority_queue<ll>
#define mnheap                  priority_queue<ll, vector<ll>, greater<ll>>
#define mxheap2                 priority_queue<pair<ll,ll>>
#define mnheap2                 priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>
//Macros
#define FIO                     ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(NULL);
#define TC(t)                   int t; cin >> t; for(int i = 1; i <= t; i++)
#define loop(i, a, b)           for(ll i = a; i <= b; i++)
#define loop2(i, b, a)          for(ll i = b; i >= a; i--)
#define pn                      cout << "NO\n";
#define py                      cout << "YES\n";
#define ed                      cout << "\n";
#define flush                   cout.flush();
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

int mp[500005];

void solve(){
    int n, m, qe; cin >> n >> m >> qe;
    vector < int > divisor; divisor.push_back(1);
    for(int i = 2; i*i <= m; i++){
        if(m%i == 0){
            divisor.push_back(i);
            if(i != m/i) divisor.push_back(m/i);
        }
    }
    vsort(divisor);
    int sz = divisor.size();
    for(int i = 0; i < sz; i++) mp[divisor[i]] = i;
    int dp[n+2][sz+1], cunt[sz+1] = {0};

    int arr[n+1]; arr[0] = 0;
    loop(i, 1, n) cin >> arr[i];

    loop(i, 0, n){
        int ar = arr[i];
        for(int j = 0; j < sz; j++) dp[i][j] = ar%divisor[j];
    }
    for(int j = 0; j < sz; j++) dp[n+1][j] = m;

    loop(i, 1, n){
        for(int j = 0; j < sz; j++){
            if(dp[i][j] < dp[i-1][j]) cunt[j]++;
        }
    }

    while(qe--){
        int tr; cin >> tr;
        if(tr == 2){
            int k; cin >> k;
            int gd = __gcd(k, m);
            int updown = cunt[mp[gd]];
            if(updown < m/gd) py 
            else pn
        }
        else{
            int inx, k; cin >> inx >> k;
            //if(arr[inx] == k) continue;
            for(int j = 0; j < sz; j++){
                int p = dp[inx-1][j], q = dp[inx][j], r = dp[inx+1][j];
                if(p <= r && p > q) cunt[j]--;
                if(p <= r && r < q) cunt[j]--;
                if(p > r && (p > q && r < q)) cunt[j]--;
                q = k%divisor[j];
                if(p <= r && p > q) cunt[j]++;
                if(p <= r && r < q) cunt[j]++;
                if(p > r && (p > q && r < q)) cunt[j]++;
                dp[inx][j] = q;
            }
        }
    }

}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}