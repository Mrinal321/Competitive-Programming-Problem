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

ll arr[1005][1005];

void solve(){
    ll n; cin >> n;
    loop(i, 1, n){
        loop(j, 1, n) cin >> arr[i][j];
    }

    ll a[n+1], b[n+1];
    loop(j, 1, n) cin >> a[j];
    loop(j, 1, n) cin >> b[j];

    ll zero = 0, ck_zero = 1, one = a[1], ck_one = 1;
    map < ll, ll > mp; mp[0] = 0; mp[1] = a[1];

    loop(i, 2, n){
        bool p = 0, q = 0, r = 0;
        loop(j, 1, n){
            ll x = arr[i][j]-arr[i-1][j];
            if(x == 0) p = 1;
            else if(x == 1) q = 1;
            else if(x == -1) r = 1;
        }

        //for(auto u : mp) cout << u.first << " " << u.second << endl;

        map < ll, ll > tmp;
        if(p == 0){
            for(auto u : mp){
                if(u.first == 0){
                    if(!tmp.count(0)) tmp[0] = u.second;
                    else tmp[0] = min(tmp[0], u.second);

                    if(r == 0){
                        if(!tmp.count(1)) tmp[1] = u.second+a[i];
                        else tmp[1] = min(tmp[1], u.second+a[i]);
                    }
                }
                else{
                    if(!tmp.count(1)) tmp[1] = u.second+a[i];
                    else tmp[1] = min(tmp[1], u.second+a[i]);

                    if(q == 0){
                        if(!tmp.count(0)) tmp[0] = u.second;
                        else tmp[0] = min(tmp[0], u.second);
                    }
                }
            }
        }
        else{
            //cout << "1"; ed
            for(auto u : mp){
                if(u.first == 0){
                    if(r == 0){
                        if(!tmp.count(1)) tmp[1] = u.second+a[i];
                        else tmp[1] = min(tmp[1], u.second+a[i]);
                    }
                }
                else{
                    if(q == 0){
                        if(!tmp.count(0)) tmp[0] = u.second;
                        else tmp[0] = min(tmp[0], u.second);
                    }
                }
            }
        }

        if(tmp.empty()){
            cout << "-1\n"; return;
        }

        mp = tmp;

        //for(auto u : mp) cout << u.first << " " << u.second << endl; ed

    }

    ll ans = min(mp.begin()->second, mp.rbegin()->second);
    mp[0] = 0; mp[1] = b[1];

    loop(i, 2, n){
        bool p = 0, q = 0, r = 0;
        loop(j, 1, n){
            ll x = arr[j][i]-arr[j][i-1];
            if(x == 0) p = 1;
            else if(x == 1) q = 1;
            else if(x == -1) r = 1;
        }

        //for(auto u : mp) cout << u.first << " " << u.second << endl;

        map < ll, ll > tmp;
        if(p == 0){
            for(auto u : mp){
                if(u.first == 0){
                    if(!tmp.count(0)) tmp[0] = u.second;
                    else tmp[0] = min(tmp[0], u.second);

                    if(r == 0){
                        if(!tmp.count(1)) tmp[1] = u.second+b[i];
                        else tmp[1] = min(tmp[1], u.second+b[i]);
                    }
                }
                else{
                    if(!tmp.count(1)) tmp[1] = u.second+b[i];
                    else tmp[1] = min(tmp[1], u.second+b[i]);

                    if(q == 0){
                        if(!tmp.count(0)) tmp[0] = u.second;
                        else tmp[0] = min(tmp[0], u.second);
                    }
                }
            }
        }
        else{
            //cout << "1"; ed
            for(auto u : mp){
                if(u.first == 0){
                    if(r == 0){
                        if(!tmp.count(1)) tmp[1] = u.second+b[i];
                        else tmp[1] = min(tmp[1], u.second+b[i]);
                    }
                }
                else{
                    if(q == 0){
                        if(!tmp.count(0)) tmp[0] = u.second;
                        else tmp[0] = min(tmp[0], u.second);
                    }
                }
            }
        }

        if(tmp.empty()){
            cout << "-1\n"; return;
        }

        mp = tmp;

        //for(auto u : mp) cout << u.first << " " << u.second << endl; ed

    }

    ans += min(mp.begin()->second, mp.rbegin()->second);

    cout << ans; ed
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}