//
// Created by kaiyu.wei on 9/18/2022.
//
#include <memory>
#include <utility>
#include "YourSet.h"

using std::string;
using std::allocator;
using std::pair;

YourSet::YourSet():
    first_ele(nullptr), first_free(nullptr), cap(nullptr) {}

YourSet::YourSet(const string &s, size_t n) {
    while(n) {
        check_realloc();
        alloc.construct(first_free++, s);
    }
}

YourSet::YourSet(YourSet &orig) {
    auto newdata = allocate_n_copy(orig.first_ele, orig.first_free);
    first_ele = newdata.first;
    first_free = cap = newdata.second;
}

YourSet& YourSet::operator=(const YourSet &rhs) {
    auto newdata = allocate_n_copy(rhs.first_ele, rhs.first_free);
    free();  // handling the self-assignment situation, copy rhs first then free
    first_ele = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

YourSet::YourSet(YourSet &&orig) noexcept:
    first_ele(orig.first_ele), first_free(orig.first_free), cap(orig.cap)
{
    orig.first_ele = orig.first_free = orig.cap = nullptr;
}

YourSet::~YourSet() {free();}

size_t YourSet::size() {
    // returns no. of elements in the set
    return first_free - first_ele;
}

size_t YourSet::capacity() {
    return cap - first_ele;
}

void YourSet::check_realloc() {
    // for ensuring there is at least one position
    if(size() == cap - first_ele)
        reallocate();
}

pair<string*, string*>
YourSet::allocate_n_copy(string *b, string *e) {
    // allocate memory and copy from range marked by pointers b and e
    auto begin = alloc.allocate(b - e);  // allocate memory
    auto end = std::uninitialized_copy(b, e, begin);  // copy into the raw memory
    return {begin, end}; // returns pointer to the first element and one pass the last element
}

void YourSet::free() {
    if(first_ele) {
        while(first_free != first_ele) {
            alloc.destroy(--first_free);
        }
        alloc.deallocate(first_ele, capacity());
    }
}