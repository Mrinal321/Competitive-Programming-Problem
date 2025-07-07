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
#define loop(i, a, b)           for(int i = a; i <= b; i++)
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
const ll N = 5e4 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/

// Helper function to multiply elements of a vector
int product(const vector<int>& vec) {
    return accumulate(vec.begin(), vec.end(), 1, multiplies<int>());
}

// Recursive function to generate all partitions
void generatePartitions(vector<int>& primes, int index, vector<vector<int>>& current, set<vector<int>>& unique) {
    if (index == primes.size()) {
        vector<int> products;
        for (auto& group : current) {
            products.push_back(product(group));
        }
        sort(products.begin(), products.end()); // to avoid duplicates like [6,5] and [5,6]
        unique.insert(products);
        return;
    }

    for (int i = 0; i < current.size(); ++i) {
        current[i].push_back(primes[index]);
        generatePartitions(primes, index + 1, current, unique);
        current[i].pop_back(); // backtrack
    }

    // Add new group with the current prime
    current.push_back({primes[index]});
    generatePartitions(primes, index + 1, current, unique);
    current.pop_back(); // backtrack
}

set<vector<int>> countUniqueFactorCombinations(vector<int>& primes) {
    set<vector<int>> unique;
    vector<vector<int>> current;
    generatePartitions(primes, 0, current, unique);
    return unique;
}


void solve(){
    int n; cin >> n;
    int a[n+1], gd = 0;
    loop(i, 1, n){
        cin >> a[i];
        gd = __gcd(gd, a[i]);
    } 

    loop(i, 1, n){
        if(a[i] == gd){
            int c = 0;
            loop(j, 1, n){
                if(a[j] != gd) c++;
            }
            cout << c; ed return;
        }
    }

    loop(i, 1, n) a[i] /= gd;

    bool dp[5005] = {0};
    //loop(i, 1, n) cout << a[i] << " "; ed
    loop(i, 1, 5000){
        loop(j, 1, n){
            if(__gcd(a[j], i) == 1) {
                dp[i] = 1; break;
            }
        }
    }
    //loop(i, 1, 15) cout << dp[i] << " "; ed

    int ans = 1000000;
    loop(inx, 1, n){
        ll x = a[inx];
        vector < int > primes;
        for(int i = 2; i*i <= x; i++){
            if(x%i == 0){
                primes.push_back(i); 
                while(x%i == 0) x /= i;
            }
        }
        if(x > 1) primes.push_back(x); 
        //for(auto u : primes) cout << u << " "; ed
        set<vector<int>> unique = countUniqueFactorCombinations(primes);
        for(vector < int > v : unique){
            bool no = 0;
            for(auto u : v){
                if(!dp[u]){
                    no = 1; break;
                }
            }
            int p = v.size();
            if(!no) ans = min(ans, p);
        }
    }

    

    cout << n-1+ans; ed 
    
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}