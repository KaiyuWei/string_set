//
// Created by kaiyu.wei on 9/18/2022.
//
#include <memory>
#include <utility>
#include <iterator>
#include "YourSet.h"
#include "heap.h"
#include <vector>
#include "search.h"

using std::string;
using std::allocator;
using std::pair;
using std::uninitialized_copy;
using std::make_move_iterator;
using std::vector;

YourSet::YourSet():
    first_ele(nullptr), first_free(nullptr), cap(nullptr) {}

YourSet::YourSet(const string &s):
        first_ele(nullptr), first_free(nullptr), cap(nullptr)
{
    check_realloc();
    alloc.construct(first_free++, s);

}

YourSet::YourSet(vector<string> vs):
    first_ele(nullptr), first_free(nullptr), cap(nullptr)
{
    if (!vs.empty()) {
        for (auto cur = vs.begin(); cur != vs.end(); cur++) {
            add(*cur);
        }
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

YourSet& YourSet::operator=(YourSet &&rhs) noexcept {
    if (this != &rhs) {
        free();
        first_ele = rhs.first_ele;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.first_ele = rhs.first_free = rhs.cap = nullptr;
    }
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

void YourSet::reallocate() {
    size_t new_cap = size() ? 2 * size() : 1;
    auto new_begin = alloc.allocate(new_cap);
    auto new_end = uninitialized_copy(
            make_move_iterator(first_ele),
            make_move_iterator(first_free), new_begin);
    free();
    first_ele = new_begin;
    first_free = new_end;
    cap = first_ele + new_cap;
}

pair<string*, string*>
YourSet::allocate_n_copy(string *b, string *e) {
    // allocate memory and copy from range marked by pointers b and e
    auto begin = alloc.allocate(e - b);  // allocate memory
    auto end = uninitialized_copy(b, e, begin);  // copy into the raw memory
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

void YourSet::add(const string &s) {
    bool exist = binary_search(first_ele, first_free - 1, s);
    if (!exist) {
        check_realloc();
        alloc.construct(first_free++, s);
        heap_sort(first_ele, first_free);
    }
}

bool YourSet::contains(const string &s) {
    bool res = binary_search(first_ele, first_free-1, s);
    return res;
}