/*
    LINK  : http://p.ip.fi/srYK

    How to use this file?
    Just copy the contents of this file, and paste it in a file and save it as A_NAME_YOU_LIKE.hpp
    in your directory where you usually code.
    Now, in your template just include these lines
    -
    #ifndef ONLINE_JUDGE
        #include "debug.hpp"
    #else
        #define print(...)
    #endif
    -
    You're done!
    What this does is, if it is an online judge, it just ignore the print() commands (debugs)
    else executes them to stderr.

    NOTE : You can copy the contents of this file and paste it directly in your template, but just to make things look simple, 
    copying it to a .hpp file is much simpler.
    ------------
    print(x) for single element (any container)
    debug(x,y,z...) for multiple
*/


#include "bits/stdc++.h"
using namespace std;
template<class Fun> class y_combinator_result {
    #define endl '\n'
    Fun fun_;
    public:
        template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
        template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename TT, typename... UU> void dbg_out(TT H, UU... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
template <class T>
void print(T x) {cerr << x;}
void print(bool x) {cerr << (x ? "true" : "false");}
template <typename T, typename... V>
void print(T t, V... v) {cerr << "["; print(t); if (sizeof...(v)) cerr << ", "; print(v...); cerr << "]";}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = "; print(x)
#else
#define debug(x...)
#endif
template <class T> void print(vector<T> a);
template <class T, class U> void print(pair<T, U> a);
template <class T> void print(vector<vector<T>> a);
template <class T, size_t n> void print(T (&a)[n]/*, bool not_part_of_2d = 1*/);
template <class T, size_t rows, size_t cols> void print(T (&a)[rows][cols]);
template <class T, class U> void print(map<T, U> a);
template <class T, class U> void print(vector<pair<T, U>> a);
template <class S, class T, class U> void print(map<S, pair<T, U>> a);
template <class T> void print(set<T> a);
template <class T, class U> void print(set<pair<T, U>> a);
template <class T> void print(unordered_set<T> a);
template <class T> void print(multiset<T> a);
template <class T> void print(priority_queue<T> a);
template <class T> void print(priority_queue<T, vector<T>, greater<T>> a);
template <class T> void print(queue<T> a);
template <class T> void print(stack<T> a);
template <class T, size_t n> void print(vector<T> (&a)[n]);

template <class T>
void print(vector<T> a) {
    /*
        Prints a vector of supported types
    */
   bool k = 0;
    cerr << "[";
    for(auto& i : a) {
        if(k) cerr << ", ";
        print(i);
        k = 1;
    }
    cerr << "]";
}
template <class T>
void print(vector<vector<T>> a) {
    /*
        Prints a vector of vector of supported types
    */
    bool k = 0;
    cerr << "[\n";
    for(auto& i : a) {
        if(k) cerr << ", ";
        print(i);
        k = 1;
    }
    cerr << "\n]";
}
template <class T, int m>
void print(T (&a)[m], int n, bool not_part_of_2d = 1) {
    /*
        Prints an array of supported types
    */
    cerr << "[";
    bool k = 0;
    for(int i = 0; i < n; ++i) {
        if(k) cerr << ", ";
        cerr << a[i];
        k = 1;
    }
    cerr << "]";
    if(not_part_of_2d) cerr << "\n";
}
template <class T, size_t rows, size_t cols>
void print(T (&a)[rows][cols]){
    // cerr << __func__ << endl;
    /*
        Prints a 2d array of supported types
    */
    bool k = 0;
    cerr << "[";
    for (size_t i = 0; i < rows; ++i){
        if(k) cerr << ",\n ";
        print(a[i],0);
        k = 1;
    }
    cerr << "]";
}
template <class T, class U>
void print(map<T, U> a){
    /*
        Prints a map of supported types
    */
    cerr << "[\n";
    for(auto& i : a) {
        print(i.first);
        cerr << " : ";
        print(i.second);
        cerr << "\n";
    }
    cerr << "]";
}
template <class T, class U>
void print(pair<T, U> a){
    /*
        Prints a pair of supported types
    */
    cerr << "(";
    print(a.first);
    cerr << " : ";
    print(a.second);
    cerr << ")";
}
template <class T, class U>
void print(vector<pair<T, U>> a){
    /*
        Prints a vector of pairs of supported types
    */
    bool k = 0;
    cerr << "[";
    for(auto& i : a) {
        if(k) cerr << ", ";
        cerr << "(";
        print(i.first);
        cerr << " : ";
        print(i.second);
        cerr << ")";
        k = 1;
    }
    cerr << "]";
}
template <class S, class T, class U>
void print(map<S, pair<T, U>> a){
    /*
        Prints a map of int to a pair of supported types
    */
    bool k = 0;
    cerr << "[";
    for(auto& i : a) {
        if(k) cerr << ",\n ";
        cerr  << i.first << " : " << "(" << i.second.first << ", " <<  i.second.second << ")";
        k = 1;
    }
    cerr << "]";
}
template <class T>
void print(set<T> a){
    /*
        Prints a set of all supported types
    */
    bool k = 0;
    cerr << "[\n";
    for(auto& i : a) {
        if(k) cerr << ", ";
        print(i);
        k = 1;
    }
    cerr << "]";
}
template <class T, class U>
void print(set<pair<T, U>> a){
    /*
        Prints a set of pair of all supported types
    */
    cerr << "[\n";
    for(auto& i : a) {
        print(i.first);
        cerr << " : ";
        print(i.second);
    }
    cerr << "]";
}
template <class T>
void print(unordered_set<T> a){
    /*
        Prints an unordered_ set of all supported types
    */
    bool k = 0;
    cerr << "[\n";
    for(auto& i : a) {
        if(k) cerr << ", ";
        print(i);
        k = 1;
    }
    cerr << "]";
}
template <class T>
void print(multiset<T> a){
    /*
        Prints a multiset of all supported types
    */
    bool k = 0;
    cerr << "[\n";
    for(auto& i : a) {
        if(k) cerr << ", ";
        print(i);
        k = 1;
    }
    cerr << "]";
}
template <class T>
void print(priority_queue<T> a){
    /*
        Prints a pririty queue of all supported types
        MAX HEAP (Descending order pq)
    */
    bool k = 0;
    cerr << "[";
    while(!a.empty()) {
        if(k) cerr << ", ";
        cerr << a.top();
        a.pop();
        k = 1;
    }
    cerr << "]";
}
template <class T>
void print(priority_queue<T, vector<T>, greater<T>> a){
    /*
        Prints a pririty queue of all supported types
        MIN HEAP (Ascending order pq)
    */
    bool k = 0;
    cerr << "[";
    while(!a.empty()) {
        if(k) cerr << ", ";
        cerr << a.top();
        a.pop();
        k = 1;
    }
    cerr << "]";
}
template <class T>
void print(queue<T> a) {
    /*
        Prints a queue of supported types
    */
    bool k = 0;
    cerr << "[";
    while(!a.empty()) {
        if(k) cerr << ", ";
        cerr << a.front();
        a.pop();
        k = 1;
    }
    cerr << "]";
}
template <class T>
void print(stack<T> a) {
    /*
        Prints a stack of supported types
    */
    bool k = 0;
    cerr << "[";
    while(!a.empty()) {
        if(k) cerr << ", ";
        cerr << a.top();
        a.pop();
        k = 1;
    }
    cerr << "]";
}
template <class T, size_t n>
void print(vector<T> (&a)[n]) {
    /*
        Prints an adjacency list of a graph stored in the form
        vector<type> array[n]; (array of vectors)
    */
    cerr << "[\n";
    // bool k = 0;
    for(size_t i = 0; i < n; ++i) {
        if(int(a[i].size()) == 0) continue;
        cerr << i << " : ";
        print(a[i]);
    }
    cerr << "]";
    cerr << "\n";
}
