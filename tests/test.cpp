#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>

#include "../source/client.h"
int ccov(void);

class MockOutput {
public:
    MOCK_METHOD(void, print, (const std::string&), (const));
};

class MockOutputTest : public ::testing::Test {
protected:
    MockOutput output;
};

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(HelloWorldTest, OutputTest) {
    ccov();
    testing::internal::CaptureStdout();
    EXPECT_EQ(0, system("./main"));
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Hello, world!\n");
}

TEST_F(MockOutputTest, OutputTest) {
    EXPECT_CALL(output, print("Hello, world!"));
    output.print("Hello, world!");
}

class MockPrinter : public printer {
public:
    MOCK_METHOD(void, print, (const std::string&), (override));
};

TEST(ClientTest, SendMessageTest) {
    MockPrinter mockPrinter;
    Client client;
    EXPECT_CALL(mockPrinter, print("Hello, world!"));
    client.sendMessage("Hello, world!");
}

class MockCalculator : public Calculator {
public:
    MOCK_METHOD(int, add, (int a, int b), (override));
};

TEST(CalculatorTest, AddTest) {
    MockCalculator mockCalculator;
    EXPECT_CALL(mockCalculator, add(2, 3)).WillOnce(::testing::Return(5));
    int result = mockCalculator.add(2, 3);
    EXPECT_EQ(result, 5);
    int *p = (int *)0x99;
    *p = 9;
}

// 要模拟的类
class MyClass {
public:
    // 虚拟函数
    virtual int virtualFunction(int x) {
        return x;
    }

    // 非虚拟函数
    int nonVirtualFunction(int x) {
        return x * 2;
    }

    // 静态函数
    static int staticFunction(int x) {
        return x * x;
    }

    // 模板函数
    template<typename T>
    T templateFunction(T x) {
        return x * 3;
    }
};
#if 0
using namespace testing;
// 测试用例
TEST(MockTest, MockVariousFunctions) {
    // 创建 Mock 对象
    NiceMock<MyClass> mock;

    // 设置虚拟函数的行为
    EXPECT_CALL(mock, virtualFunction(5))
        .WillOnce(Return(10));

    // 测试虚拟函数
    EXPECT_EQ(mock.virtualFunction(5), 10);

    // 测试非虚拟函数
    EXPECT_EQ(mock.nonVirtualFunction(3), 6);

    // 测试静态函数
    EXPECT_EQ(MyClass::staticFunction(5), 25);

    // 由于 Google Mock 不能直接模拟模板函数，因此我们需要手动定义一个模板函数，并将其模拟为普通成员函数
    EXPECT_EQ(mock.templateFunction(4), 12);


}
#endif
