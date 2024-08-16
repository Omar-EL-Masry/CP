#ifndef DEBUG_H
#define DEBUG_H

#include <bits/stdc++.h>
#include <chrono>
#include <iomanip>  // For setprecision
using namespace std;

// Output Stream Operator for Pair
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

// Output Stream Operator for Containers
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

// Function to print a single name-value pair using cout
void debug_print_one(const string& name, const string& value) {
    cout << name << " = " << value;
}

// Variadic template function to handle multiple arguments and print them using cout
template <typename T, typename... Args>
void debug_print(const string& names, const T& value, const Args&... args) {
    istringstream iss(names);
    string var_name;
    getline(iss, var_name, ',');

    cout << var_name << " = " << value;

    if constexpr (sizeof...(args) > 0) {
        cout << ", ";
        string rest;
        getline(iss, rest);
        debug_print(rest, args...);
    } else {
        cout << endl;
    }
}

// Macro to facilitate debugging with file name and line number
#define dbg(...) \
    cout << "LINE " << __LINE__ << " : "; \
    debug_print(#__VA_ARGS__, __VA_ARGS__)

// Function to redirect file input/output
void FileRedirect(const string& name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

// Timer class to measure execution time
class Timer {
public:
    Timer() : start_time(chrono::high_resolution_clock::now()) {}

    ~Timer() {
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end_time - start_time;
        cerr << setprecision(15) << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    }

private:
    chrono::time_point<chrono::high_resolution_clock> start_time;
};

#endif // DEBUG_H
