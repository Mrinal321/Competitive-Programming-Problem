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
const ll M = 1e15 + 7;
const ll N = 2e2 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/

ll n, m, k;
ll a[N][N], dp[N][N];

void f2(int inx){
    ll sum = inx*k;
    int ij = 0; 
    loop(i, inx, inx+m-1){
        sum += a[0][i%m];
        dp[0][ij] = min(dp[0][ij], sum);
        ij++;
    }

}

void func(int inx, int row){
    ll sum =  inx*k + a[row][inx];
    ll v[m]; v[0] = sum + dp[row-1][0];
    int ij = 1;
    loop(i, inx+1, inx+m-1){
        sum += a[row][i%m];
        v[ij] = min(v[ij-1]+a[row][i%m], dp[row-1][ij]+k*inx+a[row][i%m]);
        ij++;
    }
    loop(i, 0, m-1) {
        dp[row][i] = min(dp[row][i], v[i]);
        //cout << v[i] << " ";
    }
    //ed
}

void solve(){
    cin >> n >> m >> k;
    loop(i, 0, n-1){
        loop(j, 0, m-1) {
            cin >> a[i][j];
            dp[i][j] = M;
        }
    }

    loop(i, 0, m-1) f2(i);
    loop(i, 1, n-1){
        loop(ix, 0, m-1){
            func(ix, i);
        }
    }

    // loop(i, 0, n-1){
    //     loop(j, 0, m-1) {
    //         cout << dp[i][j] << " "; 
    //     } ed
    // }

    cout << dp[n-1][m-1]; ed
}
 
int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}