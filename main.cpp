#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include "YourSet.h"
#include <string>
#include <utility>

using std::string;
using std::cout;
using std::endl;

int main(){
    YourSet set("tim", 5);
    YourSet set2;
    set2 = std::move(set);
    cout << set2.capacity();
}


