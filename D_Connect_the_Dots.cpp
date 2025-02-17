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
 
void solve(){
    int n, m; cin >> n >> m;
    int vis[n+1] = {0};
    map < pair < int, int >, int > map1;
    loop(i, 1, m){
        int x, y, z; cin >> x >> y >> z;
        int p = map1[{x,y}];
        map1[{x,y}] = max(p,z);
    }
    int again[n+1] = {0};
    vector < int > v[n+1];
    
    set < pair < int, int > > ache;
    int tot = 0;

    for(auto u : map1){
        int x = u.first.first, y = u.first.second, z = u.second+1;
        int xx = u.first.first;
        if(ache.count({x,y})) continue;
        ache.insert({x,y});

        vector < int > v3, v2;
        //set < int > v2;
        bool y1 = 1, y2 = 1;

        while(z--){
            if(vis[x]){
                if(v[again[x]].empty()) y2 = 0;
                else {
                    v[again[x]].clear(); 
                    v2.push_back(again[x]);
                }
                y1 = 0;
            }
            else{
                vis[x] = 1; v3.push_back(x);
                again[x] = xx;
            }

            if(map1.count({x,y})){
                int p = map1[{x,y}];
                z = max(p,z);
            }
            x += y;
        }

        if(y1){
            tot++;
            //cout << xx << ": M"; ed
            for(auto uu : v3){
                again[uu] = xx;
                v[xx].push_back(uu);
                //cout << uu << " ";
            }
            
        }
        else{
            tot -= v2.size(); 
            //cout << xx << " " << y << " " << v2.size() << " " << y2; ed
            if(y2) tot++;
            for(auto uu : v2) {
                if(v[uu].clear())
                v[uu].clear();
            }
        }
    }

    loop(i, 1, n) {
        if(vis[i] == 0) tot++;
    }
    cout << tot; ed
}
 
int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}