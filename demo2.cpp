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
const ll M = 1e9 + 7;
const ll N = 1e4 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/

long long countSubstrings(string s) {
        int n = s.size();
        long long ans = 0;
        // 1, 2, 5
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '1' || s[i] == '2' || s[i] == '5') ans += (i+1);
        }
        // 7
        int c = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '7') c++;
            else if(s[i] != '0') c = 0;
            ans += c;
        }
        // 3, 6
        int dp[10];
        int dp2[10];
        for(int i = 0; i < 10; i++) dp[i] = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '3' || s[i] == '6') dp[0]++;
            int num = s[i]-'0';
            for(int j = 0; j < 3; j++) dp2[(j+num)%3] = dp[j];
            for(int j = 0; j < 3; j++) dp[j] = dp2[j];
            
            ans += dp[0];
        }
        // 9
        for(int i = 0; i < 10; i++) dp[i] = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '9') dp[0]++;
            int num = s[i]-'0';
            for(int j = 0; j < 9; j++) dp2[(j+num)%9] = dp[j];
            for(int j = 0; j < 9; j++) dp[j] = dp2[j];
            
            ans += dp[0];
        }
        // 4
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '4'){
                ans++;
                if(i > 0){
                    int x = 10*(s[i-1]-'0') + (s[i]-'0');
                    if(x % 4 == 0) ans += i;
                }
            }
        }
        // 8
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '8'){
                ans++;
                if(i > 0){
                    int x = 10*(s[i-1]-'0') + (s[i]-'0');
                    if(x % 8 == 0) ans++;
                }
                if(i > 1){
                    int x = 100*(s[i-2]-'0') + 10*(s[i-1]-'0') + (s[i]-'0');
                    if(x % 8 == 0) ans += (i-1);
                }
            }
        }

        return ans;
    }

void solve(){
    
}
 
int main(){
    FIO
    //TC(t) 
    solve();
    return 0;
}