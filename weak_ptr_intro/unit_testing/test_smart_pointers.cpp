#include "gtest/gtest.h"    // google tests;
#include "test_class.h"

TEST(WeakPtrTest, WeakWithoutSharedPtr){
    std::weak_ptr<test::TestClass> w_a_ptr;

    ASSERT_TRUE(w_a_ptr.expired());
}

TEST(WeakPtrTest, WeakWithSharedPtr){
    auto shared = std::make_shared<int>();

    std::weak_ptr weak(shared);
    
    ASSERT_FALSE(weak.expired());
}

TEST(WeakPtrTest, WeakAndSharedIsEqual){
    auto shared = std::make_shared<int>();

    std::weak_ptr weak(shared);
    std::weak_ptr weak_2(shared);
    std::weak_ptr weak_3(shared);

    ASSERT_EQ(weak.lock(), shared);
    ASSERT_EQ(*weak.lock(), *shared);
}

TEST(WeakPtrTest, CounterNotIncrease){
    auto shared = std::make_shared<int>();

    std::weak_ptr weak(shared);
    std::weak_ptr weak_2(shared);
    std::weak_ptr weak_3(shared);

    ASSERT_EQ(weak.use_count(), 1);
}

TEST(WeakPtrTest, WeakAfterReset){
    auto shared = std::make_shared<int>();

    std::weak_ptr weak(shared);

    ASSERT_EQ(weak.use_count(), 1);
    ASSERT_EQ(shared.use_count(), 1);

    weak.reset();

    ASSERT_EQ(weak.use_count(), 0);
    ASSERT_EQ(shared.use_count(), 1);
}

TEST(WeakPtrTest, SharedAfterReset){
    auto shared = std::make_shared<int>();

    std::weak_ptr weak(shared);

    ASSERT_EQ(weak.use_count(), 1);
    ASSERT_EQ(shared.use_count(), 1);

    shared.reset();

    ASSERT_EQ(weak.use_count(), 0);
    ASSERT_EQ(shared.use_count(), 0);
    ASSERT_EQ(weak.lock(), nullptr);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}