#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MOD = 998244353;
const int MAX = 2e5 + 5;

vector<int> inv(MAX);

void precompute_inv() {
    inv[1] = 1;
    for (int i = 2; i < MAX; ++i) {
        inv[i] = MOD - (MOD / i) * 1LL * inv[MOD % i] % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute_inv();
    
    int n, m;
    cin >> n >> m;
    
    map<int, vector<pair<int, int>>> start_events;
    map<int, vector<pair<int, int>>> end_events;
    
    for (int i = 0; i < n; ++i) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        start_events[l].emplace_back(p, q);
        end_events[r + 1].emplace_back(p, q);
    }
    
    long long current_sum = 0; // sum of p_i / (q_i - p_i)
    long long current_product = 1; // product of (q_i - p_i)/q_i
    long long result = 1;
    
    for (int x = 1; x <= m; ++x) {
        // Process segments ending at x-1 (i.e., end_events[x])
        if (end_events.count(x)) {
            for (auto &[p, q] : end_events[x]) {
                long long term = p * 1LL * inv[q - p] % MOD;
                current_sum = (current_sum - term + MOD) % MOD;
                long long term_product = (q - p) * 1LL * inv[q] % MOD;
                long long inv_term_product = inv[term_product];
                current_product = current_product * inv_term_product % MOD;
            }
        }
        
        // Process segments starting at x (start_events[x])
        if (start_events.count(x)) {
            for (auto &[p, q] : start_events[x]) {
                long long term = p * 1LL * inv[q - p] % MOD;
                current_sum = (current_sum + term) % MOD;
                long long term_product = (q - p) * 1LL * inv[q] % MOD;
                current_product = current_product * term_product % MOD;
            }
        }
        
        long long prob = current_sum * current_product % MOD;
        result = result * prob % MOD;
    }
    
    cout << result << endl;
    
    return 0;
}