#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include "YourSet.h"
#include <string>
#include <utility>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

void min_heapify(string *begin, string *cur, string *end) {
    auto n = end - begin;  // size of the set
    auto cur_script = cur - begin + 1;  // subscript in heap "array"

    if (2 * cur_script - 1 > n) return;  // if current node no child, return;

    // compare the values and find out the largest value in root, left and right child
    string *minimum = cur;
    string *left;
    string *right;
    if (2 * cur_script - 1 <= n) {
        left = begin + (2 * cur_script - 1);
        if (*cur > *left) {
            minimum = left;
        }
    }
    if (2 * cur_script <= n) {
        right = begin + (2 * cur_script);
        if (*minimum > *right) {
            minimum = right;
        }
    }
    if (minimum != cur) {
        string temp = *cur;
        *cur = *minimum;
        *minimum = temp;   // Is "std::swap" applicable here in continouse memory?
        min_heapify(begin, minimum, end);
    }
}

int main(){
    vector<string> vs{"c", "b", "a", "d", "e", "f", "g"};
    YourSet set;
    set.add("c");
    set.add("b");
    set.add("a");

//    min_heapify(vs.begin(), vs.begin(), vs.end());

}


