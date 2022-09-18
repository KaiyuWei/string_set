//
// Created by kaiyu.wei on 9/17/2022.
//
#include <string>
#include <memory>
#include <utility>
#include <vector>

#ifndef UNTITLED8_YOURSET_H
#define UNTITLED8_YOURSET_H
using std::string;
using std::allocator;
using std::pair;
using std::vector;

class YourSet{
public:
    YourSet();
    YourSet(const string&);
    YourSet(vector<string>);
    YourSet(YourSet&);  // copy constructor
    YourSet(YourSet&&) noexcept; // moving constructor
    ~YourSet();  // destructor
    YourSet &operator=(const YourSet&);  // copy assignment
    YourSet &operator=(YourSet&&) noexcept;  // moving assignment
    size_t size();
    size_t capacity();
    string *begin() {return first_ele;}
    string *end() {return first_free;}
    void add(const string&);
    bool contains(const string&);
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
