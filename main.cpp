#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include "YourSet.h"
#include <string>
#include <utility>
#include <vector>
#include "heap.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;

int main(){
<<<<<<< HEAD
    YourSet set("tim", 5);
    YourSet set2;
    set2 = std::move(set);
    cout << set2.capacity();
=======
    YourSet set;
    set.add("t");
    set.add("ttttttt");
    set.add("tttttt");
    set.add("tttt");
    set.add("ttttt");
    set.add("0");
    set.add("ttt");
    set.add("tt");
    set.add("12");

    build_heap(set.begin(), set.end());
    heap_sort(set.begin(), set.end());
    for (auto beg = set.begin(); beg != set.end(); beg++) {
        cout << *beg << " ";
    }

>>>>>>> heapsort
}


