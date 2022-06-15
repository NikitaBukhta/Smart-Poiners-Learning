#include "gtest/gtest.h"    // google tests;
#include "test_class.h"

#include <vector>

TEST(SharedPointerTest, TestForCountOfElems){
    auto a_ptr = std::make_shared<test::TestClass>();
    auto b_ptr = a_ptr;

    test::TestClass *test_class_ptr = b_ptr.get();

    ASSERT_EQ(a_ptr.use_count(), 2);
}

TEST(SharedPointerTest, TestForSwappingPtrs){
    auto a_ptr = std::make_shared<test::TestClass>();
    auto b_ptr = a_ptr;

    auto c_ptr = std::make_shared<test::TestClass>();

    std::shared_ptr<test::TestClass> null_ptr (nullptr);
    std::shared_ptr<test::TestClass> null_ptr_2;

    c_ptr.swap(a_ptr);

    ASSERT_EQ(c_ptr.use_count(), 2);
    ASSERT_EQ(a_ptr.use_count(), 1);
    ASSERT_EQ(null_ptr.use_count(), 0);
}

TEST(SharedPointerTest, TestForEqualsPtrs){
    auto a_ptr = std::make_shared<test::TestClass>();
    auto b_ptr = a_ptr;

    auto c_ptr = std::make_shared<test::TestClass>();

    std::shared_ptr<test::TestClass> null_ptr (nullptr);
    std::shared_ptr<test::TestClass> null_ptr_2;

    ASSERT_EQ(a_ptr, b_ptr);
    ASSERT_NE(b_ptr, c_ptr);
    ASSERT_NE(c_ptr, null_ptr);
    ASSERT_EQ(null_ptr, null_ptr_2);
}

TEST(SharedPointerTest, TestForCopingVectors){
    std::vector<std::shared_ptr<int>> v {
        std::make_shared<int>(1),
        std::make_shared<int>(2),
        std::make_shared<int>(3)
    };

    std::vector<std::shared_ptr<int>> v2;

    // copy all elems that are not 2;
    std::remove_copy_if(v.begin(), v.end(), back_inserter(v2), [] (std::shared_ptr<int> s){
        return *s == 2;
    });

    size_t v2_size = v2.size();
    for(size_t i = 0, j = 0; i < v2_size; ++i, ++j){
        while (v2[i] != v[j]){
            ++j;
        }

        // test for equal addresses;
        ASSERT_EQ(v2[i], v[j]);
    }
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}