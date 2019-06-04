#include <iostream>
#include <string>
#include <vector>
#include "basics.h"

using namespace std;


void inc_pass_copy(int j) {
    j++;
}


void inc_pass_ref(int& j) {
    j++;
}


void fill_vector(vector<int>& v, int n) {
    for (int i = 1; i < n; ++i){
        v.push_back(i);
    }
}


void print_vector(const vector<int>& v) {
    for (int i : v) {
        cout << i << endl;
    }
}


void print_coords(coord pos) {
    cout << "x = " << pos.x << "; y = " << pos.y << endl;
}

int square(int n) {
    return n*n;
}

double square(double d) {
    return d*d;
}

int my_abs(int n) {
    return abs(n);
}

int sum(int n) {
    int total = 0;
    int i = 0;
    while(i < n){
        total += i;
        ++i;
    }
    return total;
}

int sum2(int n) {
    int total = 0;
    for (int i = 0; i < n; i++){
        total += i;
    }
    return total;
}

void say(string s) {
    cout << s << endl;
}


void pull_apart_string(string s) {
    for (char c : s){
        cout << c << ' ';
    }
}
