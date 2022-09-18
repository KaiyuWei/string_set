//
// Created by kaiyu.wei on 9/18/2022.
//
#include <string>
#include "search.h"

string* binary_search(string *begin, string *boundary, string s) {
    // boundary is the pointer to the last element here.
    if (!begin || !boundary) return nullptr;
    string *left = begin;
    string *right = boundary;
    while (left <= right) {
        string *mid = left + ((right - left) / 2);
        if (*mid == s) return mid;
        else if (*mid > s) right = mid - 1;
        else left = mid + 1;
    }
    return nullptr;
}
