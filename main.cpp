#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>

using std::allocator;

int main(){
    allocator<int> alloc;
    auto p = alloc.allocate(10);

}


