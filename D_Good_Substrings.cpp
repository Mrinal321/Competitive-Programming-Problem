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
const ll M2 = 1e9 + 9;
const ll N = 1e5 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    static const uint64_t FIXED_RANDOM;

    // Hash for integral types
    template<typename T>
    typename enable_if<is_integral<T>::value, size_t>::type
    operator()(T x) const {
        return splitmix64(x + FIXED_RANDOM);
    }

    // Hash for string
    size_t operator()(const string& s) const {
        uint64_t hash = 0;
        uint64_t p = 31;
        uint64_t p_pow = 1;
        for (char c : s) {
            hash = (hash + (c - 'a' + 1) * p_pow) % (1ULL << 61);
            p_pow = (p_pow * p) % (1ULL << 61);
        }
        return splitmix64(hash + FIXED_RANDOM);
    }

    // Hash for pair
    template<typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        size_t h1 = (*this)(p.first);
        size_t h2 = (*this)(p.second);
        return h1 ^ (h2 << 1);
    }
};

const uint64_t custom_hash::FIXED_RANDOM =
    chrono::steady_clock::now().time_since_epoch().count();


void solve(){
    string a, ptr; cin >> a >> ptr;
    int n; cin >> n;
    int sz = a.size();
    unordered_set < pair < ll, ll >, custom_hash > ans;
    for(int i = 0; i < sz; i++){
        ll val = 0, val2 = 0, c = 0;
        //string s;
        for(int j = i; j < sz; j++){
            if(ptr[a[j]-'a'] == '0') c++;
            if(c > n) break;
            //s.push_back(a[j]);
            val = (val * 101 + (a[j]-'a'+1)) % M;
            val2 = (val2 * 31 + (a[j]-'a'+1)) % M2;
            ans.insert({val, val2});
        }
    }
    cout << ans.size(); 
}

int main(){
    FIO
    //TC(t) 
    solve();
    return 0;
}