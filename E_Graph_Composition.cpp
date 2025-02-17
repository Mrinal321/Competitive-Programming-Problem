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

set < int > s1[N], s2[N];
set < int > st, st2;
bool v1[N], v2[N];

void dfs2(int node){
    st.insert(node);
    v2[node] = 1;
    for(auto u : s2[node]){
        if(!v2[u]) dfs2(u);
    }
}

ll ans;
void dfs(int node){
    v1[node] = 1;
    st2.insert(node);
    for(auto u : s1[node]){
        if(!st.count(u)){
            s1[u].erase(node);
            ans++;
            continue;
        }
        if(!v1[u]) dfs(u);
    }
}

void solve(){
    int n, p, q; cin >> n >> p >> q;
    loop(i, 1, n){
        s1[i].clear(); s2[i].clear();
        v1[i] = 0; v2[i] = 0;
    }
    loop(i, 1, p){
        int x, y; cin >> x >> y;
        s1[x].insert(y);
        s1[y].insert(x);
    }
    loop(i, 1, q){
        int x, y; cin >> x >> y;
        s2[x].insert(y);
        s2[y].insert(x);
    }

    ans = 0;
    loop(i, 1, n){
        if(v2[i]) continue;
        st.clear(); st2.clear();
        dfs2(i);
        int p = -1;
        for(auto u : st){
            if(!v1[u]) {
                dfs(u);
                p++;
            }
        }
        ans += p;

        //cout << i << " " << ans; ed

        // int p = st.size(); int q = st2.size();
        // // for(auto u : st){
        // //     if(st2.count(u)) continue;
        // //     ans += (s1[u].size());
        // //     for(auto uu : s1[u]) s1[uu].erase(u);
        // //     s1[u].clear();
        // // }
        // ans += (p-q);
    }

    cout << ans; ed
    
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}