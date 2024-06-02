#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>

#include "../../source/client.h"
int ccov(void);

class MockOutput {
public:
    MOCK_METHOD(void, print, (const std::string&), (const));
};

class MockOutputTest : public ::testing::Test {
protected:
    MockOutput output;
};

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
    //*p = 9;
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
