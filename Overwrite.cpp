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


// Booth's Algorithm to find the smallest rotation
vector<int> lexicographically_minimal_rotation(vector<int> &arr) {
    int n = arr.size();
    vector<int> concatArr(arr.begin(), arr.end());
    concatArr.insert(concatArr.end(), arr.begin(), arr.end()); // Concatenate itself
    
    int len = 2 * n;
    vector<int> f(len, -1); // Failure function
    int k = 0;  // Minimum lexicographic rotation index
    
    for (int j = 1; j < len; ++j) {
        int i = f[j - k - 1];
        while (i != -1 && concatArr[j] != concatArr[k + i + 1]) {
            if (concatArr[j] < concatArr[k + i + 1]) k = j - i - 1;
            i = f[i];
        }
        
        if (concatArr[j] != concatArr[k + i + 1]) { 
            if (concatArr[j] < concatArr[k]) k = j;
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }

    vector<int> result(arr.begin() + k, arr.end());
    result.insert(result.end(), arr.begin(), arr.begin() + k);
    
    return result;
}

void solve(){
    int n, m; cin >> n >> m;
    ll a[n+1], b[m+1];
    loop(i, 1, n) cin >> a[i];
    vector < int > v;
    loop(i, 1, m) {
        cin >> b[i];
        v.push_back(b[i]);
    }
    vector<int> result = lexicographically_minimal_rotation(v);
    //for(auto u : result) cout << u << " "; ed

    if(result[0] != result[m-1]){

        loop(i, 1, n){
            if(a[i] > result[0] && i+m-1 <= n){
                int inx = n-m+1;
                loop(j, i, inx) a[j] = result[0];
                for(auto u: result){
                    a[inx] = u; inx++;
                } 
                break;
            }
        }
        int j = 0; 
        bool yes = 0;
        loop(i, n-m+1, n){
            if(yes){
                a[i] = result[j]; j++; continue;
            }
            if(a[i] < result[j]) break;
            if(a[i] > result[j]){
                yes = 1; a[i] = result[j];  
            }
            j++;
        }
        loop(i, 1, n) cout << a[i] << " "; ed
    }
    else{
        int i = 1;
        while(i <= n){
            if(a[i] > result[0]){
                int p = m;
                while(p--){
                    a[i] = result[0];
                    i++;
                }
                while(a[i] > result[0]){
                    a[i] = result[0];
                    i++;
                }
            }
            else  i++;
        }
        loop(i, 1, n) cout << a[i] << " "; ed
    }
    //
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}