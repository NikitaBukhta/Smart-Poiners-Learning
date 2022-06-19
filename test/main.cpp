#include "test_class.h"

#include <memory>
#include <array>

void deleter(test::TestClass *object){
    delete object;
}

struct Deleter{
    void operator() (test::TestClass *object){
        delete object;
    }
};

int main(int argc, char **argv){
    std::unique_ptr<test::TestClass, Deleter> shared_4(new test::TestClass);

    std::array<std::shared_ptr<test::TestClass>, 4> a {
        std::make_shared<test::TestClass>(),
        std::shared_ptr<test::TestClass> (new test::TestClass, [](auto *a) { delete a; }),
        std::shared_ptr<test::TestClass> (new test::TestClass, deleter),
    };

    for (int i = 0; i < a.size(); ++i){
        std::cout << sizeof(a[i]) << std::endl;
    }

    return 0;
}