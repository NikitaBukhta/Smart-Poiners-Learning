#include "shared_ptr"

#include <iostream>

int main(int argc, char **argv){
    smart_ptr::SharedPtr<int> shared(new int(10));
    auto b(std::move(shared));
    std::shared_ptr<int> a;

    return 0;
}