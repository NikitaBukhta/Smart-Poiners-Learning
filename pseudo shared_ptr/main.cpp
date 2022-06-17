#include "shared_ptr"

#include <iostream>

int main(int argc, char **argv){
    smart_ptr::SharedPtr<int> shared(new int(10));

    return 0;
}