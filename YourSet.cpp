//
// Created by kaiyu.wei on 9/18/2022.
//
#include <memory>
#include <utility>
#include "YourSet.h"

using std::string;
using std::allocator;
using std::pair;

// constructors
YourSet::YourSet():
    first_ele(nullptr), first_free(nullptr), cap(nullptr) {}

YourSet::YourSet(const string &s, size_t n) {

}

size_t YourSet::size() {
    // returns no. of elements in the set
    return first_free - first_ele;
}

size_t YourSet::capacity() {
    return cap - first_ele;
}

void YourSet::check_realloc() {
    if(size() == cap - first_ele)
        reallocate();
}

pair<string*, string*>
YourSet::allocate_n_copy(string *b, string *e) {
    auto begin = alloc.allocate(b - e);  // allocate memory
    auto end = std::uninitialized_copy(b, e, begin);  // copy into the raw memory
    return {begin, end};
}

void YourSet::free() {
    if(first_ele) {
        while(first_free != first_ele) {
            alloc.destroy(first_free--);
        }
        alloc.deallocate(first_ele, capacity());
    }
}