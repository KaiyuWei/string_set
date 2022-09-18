#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include "YourSet.h"
#include <string>
#include <utility>
#include <vector>
#include "search.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;

int main(){
    YourSet set({"ttt", "0", "a", "helloworld", "zein56", "ppt"});

    for (auto beg = set.begin(); beg != set.end(); beg++) {
        cout << *beg << " ";
    }
    cout << endl;
    bool res = binary_search(set.begin(), set.end() - 1, "zein56");
    cout << res;
}


