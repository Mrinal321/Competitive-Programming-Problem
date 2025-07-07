#include<bits/stdc++.h>
using namespace std;
 
#define ll                      long long int
const ll M = 505;
const ll N = 1e4 + 5;

int arr[N], frute[N];
int total[M];

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++) cin >> frute[i];
    int total[1005];
    for(int i = 1; i <= 1000; i++) total[i] = 0;
    for(int i = 1; i <= n; i++){
        int mx = 0, val = arr[i];
        for(int j = 1; j <= val; j++) mx = max(total[j], mx);
        total[val] = frute[i] + mx;
    }
    
    int mx = 0;
    for(int i = 1; i <= 1000; i++) mx = max(mx, total[i]);
    cout << mx << "\n";
}

int main(){
    solve();
    return 0;
}