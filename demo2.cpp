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

#define mx 200005
ll arr[mx];
ll Tree[mx * 3];

void init(int node, int b, int e){
    if(b == e){
        Tree[node] = arr[b];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(left, b, mid);
    init(right, mid+1, e);
    Tree[node] = max(Tree[left] , Tree[right]);
}

ll query(int node, int b, int e, int i, int j){
    if(i > e || j < b) return 0;
    if(b >= i && e <= j) return Tree[node];

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    ll p1 = query(left, b, mid, i, j);
    ll p2 = query(right, mid+1, e, i, j);
    return max(p1 , p2);
}

void update(int node, int b, int e, int i, int newvalue){
    if(i > e || i < b) return;
    if(b >= i && e <= i){
        Tree[node] = newvalue;
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(left, b, mid, i, newvalue);
    update(right, mid+1, e, i, newvalue);
    Tree[node] = max(Tree[left] , Tree[right]);
}
 
void solve(){ 
    ll n, q; cin >> n >> q;
    loop(i, 1, n) cin >> arr[i];
    init(1, 1, n);
    while(q--){
        int i, j; cin >> i >> j;
		if(i == 1){
			ll ans = query(1, 1, n, 1, n) - query(1, 1, n, j, j);
			cout << ans; ed
		}
		else{
			int val; cin >> val;
			update(1, 1, n, j, val);
		}
    }
}

int main(){
    FIO
    //TC(t) 
    solve();
    return 0;
}