#include <gtest/gtest.h>

#include "length.h"

class LengthTest : public testing::Test {
protected:
    void SetUp() override {
        length = nullptr;
        result = nullptr;
    }

    void TearDown() override {
        if (length != result && result != nullptr) {
            free(result);
            result = nullptr;
        }

        if (length != nullptr) {
            free(length);
            length = nullptr;
        }
    }

    Length *length = nullptr;
    Length *result = nullptr;
};

TEST_F(LengthTest, should_1_inch_equals_1_inch) {
    length = newLength(1, INCH);
    result = as(length, INCH);

    EXPECT_EQ(result->val, 1.0);
    EXPECT_EQ(result->uint, INCH);
}

TEST_F(LengthTest, should_2_feet_equals_2_feet) {
    length = newLength(2, FOOT);
    result = as(length, FOOT);

    EXPECT_EQ(result->val, 2.0);
    EXPECT_EQ(result->uint, FOOT);
}

TEST_F(LengthTest, should_1_yard_equals_1_yard) {
    length = newLength(1, YARD);
    result = as(length, YARD);

    EXPECT_EQ(result->val, 1.0);
    EXPECT_EQ(result->uint, YARD);
}

TEST_F(LengthTest, should_1_foot_equals_12_inches) {
    length = newLength(1, FOOT);
    result = as(length, INCH);

    EXPECT_EQ(result->val, 12.0);
    EXPECT_EQ(result->uint, INCH);
}

TEST_F(LengthTest, should_3_feet_equals_1_yard) {
    length = newLength(3, FOOT);
    result = as(length, YARD);

    EXPECT_EQ(result->val, 1);
    EXPECT_EQ(result->uint, YARD);
}

TEST_F(LengthTest, should_1_yard_equals_3_feet) {
    length = newLength(1, YARD);
    result = as(length, FOOT);

    EXPECT_EQ(result->val, 3);
    EXPECT_EQ(result->uint, FOOT);
}

TEST_F(LengthTest, should_1_yard_equals_36_inches) {
    length = newLength(1, YARD);
    result = as(length, INCH);

    EXPECT_EQ(result->val, 36);
    EXPECT_EQ(result->uint, INCH);
}

TEST_F(LengthTest, should_12_inches_equals_1_foot) {
    length = newLength(12, INCH);
    result = as(length, FOOT);

    EXPECT_EQ(result->val, 1);
    EXPECT_EQ(result->uint, FOOT);
}

TEST_F(LengthTest, should_36_inches_equals_1_yard) {
    length = newLength(36, INCH);
    result = as(length, YARD);

    EXPECT_EQ(result->val, 1);
    EXPECT_EQ(result->uint, YARD);
}

TEST_F(LengthTest, should_18_inches_equals_half_yard) {
    length = newLength(18, INCH);
    result = as(length, YARD);

    EXPECT_EQ(result->val, 0.5);
    EXPECT_EQ(result->uint, YARD);
}
