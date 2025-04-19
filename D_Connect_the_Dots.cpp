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
#define loop(i, a, b)           for(int i = a; i <= b; i++)
#define loop2(i, b, a)          for(int i = b; i >= a; i--)
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
const ll N = 1e5 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/

class DSU {
    private:
        vector<int> parent, rank;
    
    public:
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for(int i = 0; i < n; ++i)
                parent[i] = i;
        }
    
        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]); // Path Compression
            return parent[x];
        }
    
        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
    
            if (rootX == rootY)
                return;
    
            // Union by Rank
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootY] < rank[rootX]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    };

void solve(){
    int n, m; cin >> n >> m;
    DSU dsu(n+5);
    int vis[n+1] = {0};
    int a[n+1][12];
    loop(i, 1, n){
        loop(j, 1, 10) a[i][j] = 0;
    }
    loop(i, 1, m){
        int x, y, z; cin >> x >> y >> z;
        a[x][y] = max(a[x][y], z);
    }
    loop(i, 1, n){
        loop(j, 1, 10){
            if(a[i][j] == 0) continue;
            dsu.unite(i, i+j);
            a[i+j][j] = max(a[i+j][j], a[i][j]-1);
        }
    }

    set < int > ans;
    loop(i, 1, n) ans.insert(dsu.find(i));
    cout << ans.size(); ed
}
 
int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}