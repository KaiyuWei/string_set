//
// Created by kaiyu.wei on 9/18/2022.
//
#include <string>
#include <memory>

using std::string;
using std::make_shared;

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

