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



int main(){
    YourSet set;
    set.add("e");
    set.add("g");
    set.add("f");
    set.add("d");
    set.add("a");
    set.add("c");
    set.add("b");

    build_heap(set.begin(), set.end());

    for (auto beg = set.begin(); beg != set.end(); beg++) {
        cout << *beg << " ";
    }

}


