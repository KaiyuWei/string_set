//
// Created by kaiyu.wei on 9/18/2022.
//
#include <string>
#include "heap.h"

using std::string;

void max_heapify(string *begin, string *cur, string *end) {
    auto n = end - begin;  // size of the set
    auto cur_script = cur - begin + 1;  // subscript in heap "array"

    if (2 * cur_script - 1 >= n) return;  // if current node no child, return;

    // compare the values and find out the largest value in root, left and right child
    string *largest = cur;
    string *left;
    string *right;
    if (2 * cur_script - 1 < n) {
        left = begin + (2 * cur_script - 1);
        if (*cur < *left) {
            largest = left;
        }
    }
    if (2 * cur_script < n) {
        right = begin + (2 * cur_script);
        if (*largest < *right) {
            largest = right;
        }
    }
    if (largest != cur) {
        string temp = *cur;
        *cur = *largest;
        *largest = temp;   // Is "std::swap" applicable here in continouse memory?
        max_heapify(begin, largest, end);
    }
}

void build_heap(string *begin, string *end) {
    auto n = end - begin;
    for (auto cur = end - 1; cur >= begin; cur--) {
        max_heapify(begin, cur, end);
    }
}

void heap_sort(string *begin, string *end) {
    if (!begin || !end || begin == end) return;
    auto boundary = end;
    build_heap(begin, boundary);
    for (auto cur = end - 1; cur != begin; cur-- ) {
        string temp = *cur;
        *cur = *begin;
        *begin = temp;  // swap value
        boundary--;
        max_heapify(begin, begin, boundary);
    }
}