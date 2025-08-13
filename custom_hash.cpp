#include <bits/stdc++.h>
using namespace std;

// -------------------------
// Generic custom_hash for unordered_map/unordered_set
// Supports int, long long, string, pair<T1, T2>
// -------------------------
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


// -------------------------
// Example Usage
// -------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, string, custom_hash> umap_int;
    unordered_map<long long, int, custom_hash> umap_ll;
    unordered_map<string, int, custom_hash> umap_str;
    unordered_map<pair<int, int>, string, custom_hash> umap_pair;
    unordered_set<string, custom_hash> uset_str;

    umap_int[1] = "one";
    umap_ll[1000000000003LL] = 42;
    umap_str["mrinal"] = 7;
    umap_pair[{2, 3}] = "coords";
    uset_str.insert("hello");

    cout << umap_int[1] << "\n";               // Output: one
    cout << umap_ll[1000000000003LL] << "\n";  // Output: 42
    cout << umap_str["mrinal"] << "\n";        // Output: 7
    cout << umap_pair[{2, 3}] << "\n";         // Output: coords
    cout << (uset_str.count("hello") ? "YES" : "NO") << "\n"; // Output: YES

    return 0;
}
