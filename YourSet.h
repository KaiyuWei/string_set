//
// Created by kaiyu.wei on 9/17/2022.
//
#include <string>
#include <memory>
#include <utility>

#ifndef UNTITLED8_YOURSET_H
#define UNTITLED8_YOURSET_H
using std::string;
using std::allocator;
using std::pair;

class YourSet{
public:
    YourSet();
    YourSet(const string&, size_t n = 1);
    YourSet(YourSet&);  // copy constructor
    YourSet(YourSet&&) noexcept; // moving constructor
    ~YourSet();  // destructor
    YourSet &operator=(const YourSet&);
    size_t size();
    size_t capacity();
    string *begin() {return first_ele;}
    string *end() {return first_free;}
private:
    allocator<string> alloc;
    pair<string*, string*> allocate_n_copy(string*, string*);
    void reallocate();
    void check_realloc();
    void free();
    string *first_ele;  // points to the first element in the set
    string *first_free;  // points to the first free memory after the last element
    string *cap;  // points to the on pass the end of the allocated memory

};


#endif //UNTITLED8_YOURSET_H