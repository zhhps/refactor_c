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

    LengthPtr length = nullptr;
    LengthPtr result = nullptr;
};

TEST_F(LengthTest, should_1_inch_equals_1_inch) {
    length = NewLength(1, Inch);
    result = As(length, Inch);

    EXPECT_EQ(result->value, 1.0);
    EXPECT_EQ(result->unit, Inch);
}

TEST_F(LengthTest, should_2_feet_equals_2_feet) {
    length = NewLength(2, Foot);
    result = As(length, Foot);

    EXPECT_EQ(result->value, 2.0);
    EXPECT_EQ(result->unit, Foot);
}

TEST_F(LengthTest, should_1_yard_equals_1_yard) {
    length = NewLength(1, Yard);
    result = As(length, Yard);

    EXPECT_EQ(result->value, 1.0);
    EXPECT_EQ(result->unit, Yard);
}

TEST_F(LengthTest, should_1_foot_equals_12_inches) {
    length = NewLength(1, Foot);
    result = As(length, Inch);

    EXPECT_EQ(result->value, 12.0);
    EXPECT_EQ(result->unit, Inch);
}

TEST_F(LengthTest, should_3_feet_equals_1_yard) {
    length = NewLength(3, Foot);
    result = As(length, Yard);

    EXPECT_EQ(result->value, 1);
    EXPECT_EQ(result->unit, Yard);
}

TEST_F(LengthTest, should_1_yard_equals_3_feet) {
    length = NewLength(1, Yard);
    result = As(length, Foot);

    EXPECT_EQ(result->value, 3);
    EXPECT_EQ(result->unit, Foot);
}

TEST_F(LengthTest, should_1_yard_equals_36_inches) {
    length = NewLength(1, Yard);
    result = As(length, Inch);

    EXPECT_EQ(result->value, 36);
    EXPECT_EQ(result->unit, Inch);
}

TEST_F(LengthTest, should_12_inches_equals_1_foot) {
    length = NewLength(12, Inch);
    result = As(length, Foot);

    EXPECT_EQ(result->value, 1);
    EXPECT_EQ(result->unit, Foot);
}

TEST_F(LengthTest, should_36_inches_equals_1_yard) {
    length = NewLength(36, Inch);
    result = As(length, Yard);

    EXPECT_EQ(result->value, 1);
    EXPECT_EQ(result->unit, Yard);
}

TEST_F(LengthTest, should_18_inches_equals_half_yard) {
    length = NewLength(18, Inch);
    result = As(length, Yard);

    EXPECT_EQ(result->value, 0.5);
    EXPECT_EQ(result->unit, Yard);
}
