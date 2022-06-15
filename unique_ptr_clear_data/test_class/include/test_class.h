#ifndef TEST_CLASS_H
#define TEST_CLASS_H

#include <iostream>

namespace test
{
    class TestClass{
    private:
        int *_var;
    public:
        TestClass(void);

        ~TestClass(void);

        TestClass(const TestClass &other);

        TestClass(TestClass &&other);

        TestClass& operator= (const TestClass &other);

        TestClass& operator= (TestClass &&other);

        TestClass* operator-> (void);

        int get_var(void);

        void do_something(void);
    };
}

#endif // !TEST_CLASS_H