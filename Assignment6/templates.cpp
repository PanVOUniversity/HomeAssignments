/*Pan Vladimir st128934@student.spbu.ru
"Home assignment 6 - templates*/
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// General template
template <typename T1, typename T2>
class Transformer {
private:
    int number;
    std::vector<float> vec;
    T1 instance;

public:
    Transformer(int num, const std::vector<float>& v, const T1& obj)
        : number(num), vec(v), instance(obj) {}

    bool foo() {
        return instance.bar(number, vec);
    }
};

// Partial specialization
template <typename T>
class Transformer<int, T> {
private:
    int number;
    std::vector<float> vec;

public:
    Transformer(int num, const std::vector<float>& v, const T& obj)
        : number(num), vec(v) {}

    bool foo() {
        return true;
    }
};

// Partial specialization
template <typename T>
class Transformer<double, T> {
private:
    int number;
    std::vector<float> vec;

public:
    Transformer(int num, const std::vector<float>& v, const T& obj)
        : number(num), vec(v) {}

    bool foo() {
        return false;
    }
};


class Class1 {
public:
    bool bar(int num, const std::vector<float>& vec) {
        return num > 0;
    }

    int c_1_1() {
        std::cout << "c_1_1\n";
        return 1;
    }

    float c_1_2() {
        std::cout << "c_1_2\n";
        return 0.1f;
    }

    void c_1_3() {
        std::cout << "c_1_3\n";
    }
};

class Class2 {
public:
    bool bar(int num, const std::vector<float>& vec) {
        return !vec.empty();
    }

    int c_2_1() {
        std::cout << "c_2_1\n";
        return 2;
    }

    float c_2_2() {
        std::cout << "c_2_2\n";
        return 0.2f;
    }

    void c_2_3() {
        std::cout << "c_2_3\n";
    }
};

class Class3 {
public:
    bool bar(int num, const std::vector<float>& vec) {
        return num == -static_cast<int>(vec.size());
    }

    int c_3_1() {
        std::cout << "c_3_1\n";
        return 3;
    }

    float c_3_2() {
        std::cout << "c_3_2\n";
        return 0.3f;
    }

    void c_3_3() {
        std::cout << "c_3_3\n";
    }
};

// Google Test
class TransformerTest : public ::testing::Test {
protected:
    Class1 cl1;
    Class2 cl2;
    Class3 cl3;
};

// Tests for Class1
TEST_F(TransformerTest, Class1FooTrue) {
    std::vector<float> vec = {1.0f, 2.0f, 3.0f};
    Transformer<Class1, int> transformer(5, vec, cl1);
    EXPECT_TRUE(transformer.foo());
}

TEST_F(TransformerTest, Class1FooFalse) {
    std::vector<float> vec = {1.0f, 2.0f, 3.0f};
    Transformer<Class1, int> transformer(-5, vec, cl1);
    EXPECT_FALSE(transformer.foo());
}

// Tests for Class2
TEST_F(TransformerTest, Class2FooTrue) {
    std::vector<float> vec = {1.0f, 2.0f, 3.0f};
    Transformer<Class2, int> transformer(1, vec, cl2);
    EXPECT_TRUE(transformer.foo());
}

TEST_F(TransformerTest, Class2FooFalse) {
    std::vector<float> vec;
    Transformer<Class2, int> transformer(-5, vec, cl2);
    EXPECT_FALSE(transformer.foo());
}

// Tests for Class3
TEST_F(TransformerTest, Class3FooTrue) {
    std::vector<float> vec = {1.0f, 2.0f, 3.0f};
    Transformer<Class3, int> transformer(-3, vec, cl3);
    EXPECT_TRUE(transformer.foo());
}

TEST_F(TransformerTest, Class3FooFalse) {
    std::vector<float> vec = {1.0f, 2.0f, 3.0f};
    Transformer<Class3, int> transformer(3, vec, cl3);
    EXPECT_FALSE(transformer.foo());
}

// Tests for specializations
TEST_F(TransformerTest, IntSpecializationAlwaysTrue) {
    Transformer<int, Class1> transformer(0, {}, cl1);
    EXPECT_TRUE(transformer.foo());
}

TEST_F(TransformerTest, DoubleSpecializationAlwaysFalse) {
    Transformer<double, Class1> transformer(0, {}, cl1);
    EXPECT_FALSE(transformer.foo());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
