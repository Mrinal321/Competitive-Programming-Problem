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

void solve(){
    string a, b; cin >> a;
    b = a; vrev(b);
    //cout << b; ed
    int n = a.size();
    //cout << n; ed
    int m = n/2-1, index = 0;
    bool no3 = 0;
    loop(i, 0, m){
        if(a[i] != a[n-i-1]) {
            no3 = 1;
            index = i; break;
        }
    }
    if(!no3){
        cout << "0\n"; return;
    }
    int l = 1, r = n;
    while(r-l > 2){
        int mid = l + (r-l)/2;
        multiset < int > ma, mb;
        bool na = 0, nb = 0; int pa = 0, pb = 0;
        int inx = -1;
        loop(i, index, m){
            if(pa == 0){
                if(a[i] == a[n-i-1]) continue;
                loop(j, i, i+mid-1){
                    if(j >= n) break;
                    ma.insert(a[j]);
                    inx = j;
                }
                pa = 1;
                if(inx >= n-i-1) break;
                if(ma.count(a[n-i-1])) ma.erase(ma.find(a[n-i-1]));
                else if(ma.empty() && a[i] == a[n-i-1]);
                else{
                    na = 1; break;
                }
            }
            else{
                if(inx >= n-i-1) break;
                if(ma.count(a[n-i-1])) ma.erase(ma.find(a[n-i-1]));
                else if(ma.empty() && a[i] == a[n-i-1]);
                else{
                    na = 1; break;
                }
            }
        }

        inx = -1;
        loop(i, index, m){
            if(pb == 0){
                if(b[i] == b[n-i-1]) continue;
                loop(j, i, i+mid-1){
                    if(j >= n) break;
                    mb.insert(b[j]);
                    inx = j;
                }
                pb = 1;
                if(inx >= n-i-1) break;
                if(mb.count(b[n-i-1])) mb.erase(mb.find(b[n-i-1]));
                else if(mb.empty() && b[i] == b[n-i-1]);
                else{
                    nb = 1; break;
                }
            }
            else{
                if(inx >= n-i-1) break;
                if(mb.count(b[n-i-1])) mb.erase(mb.find(b[n-i-1]));
                else if(mb.empty() && b[i] == b[n-i-1]);
                else{
                    nb = 1; break;
                }
            }
        }


        if(na == 0 || nb == 0) r = mid;
        else l = mid+1;
    }

    //cout << l << " " << r; ed
    for(int mid = l; mid <= r; mid++){
        multiset < int > ma, mb;
        bool na = 0, nb = 0; int pa = 0, pb = 0;
        int inx = -1;
        loop(i, index, m){
            if(pa == 0){
                if(a[i] == a[n-i-1]) continue;
                loop(j, i, i+mid-1){
                    if(j >= n) break;
                    ma.insert(a[j]);
                    inx = j;
                }
                pa = 1;
                if(inx >= n-i-1) break;
                if(ma.count(a[n-i-1])) ma.erase(ma.find(a[n-i-1]));
                else if(ma.empty() && a[i] == a[n-i-1]);
                else{
                    na = 1; break;
                }
            }
            else{
                if(inx >= n-i-1) break;
                if(ma.count(a[n-i-1])) ma.erase(ma.find(a[n-i-1]));
                else if(ma.empty() && a[i] == a[n-i-1]);
                else{
                    na = 1; break;
                }
            }
        }

        inx = -1;
        loop(i, index, m){
            if(pb == 0){
                if(b[i] == b[n-i-1]) continue;
                loop(j, i, i+mid-1){
                    if(j >= n) break;
                    mb.insert(b[j]);
                    inx = j;
                }
                pb = 1;
                if(inx >= n-i-1) break;
                if(mb.count(b[n-i-1])) mb.erase(mb.find(b[n-i-1]));
                else if(mb.empty() && b[i] == b[n-i-1]);
                else{
                    nb = 1; break;
                }
            }
            else{
                if(inx >= n-i-1) break;
                if(mb.count(b[n-i-1])) mb.erase(mb.find(b[n-i-1]));
                else if(mb.empty() && b[i] == b[n-i-1]);
                else{
                    nb = 1; break;
                }
            }
        }

        if(na == 0 || nb == 0) {
            cout << mid; ed return;
        }
    }

    cout << "M"; ed
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}