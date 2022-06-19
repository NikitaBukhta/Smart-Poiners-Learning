#include "unique_ptr"

#include <iostream>

struct Struct{
    int a1;
    int a2;
};

int main(int argc, char **argv){
    auto a = std::make_unique<Struct>();
    a.reset();
    
    smart_ptr::UniquePtr<Struct> b (new Struct());
    b.reset();

    return 0;
}