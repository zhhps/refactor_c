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
    length = newLength(1, "inch");
    result = unitTransfer(length, "inch");

    EXPECT_EQ(result->value, 1.0);
    EXPECT_EQ(result->unit, "inch");
}

TEST_F(LengthTest, should_2_feet_equals_2_feet) {
    length = newLength(2, "feet");
    result = unitTransfer(length, "feet");

    EXPECT_EQ(result->value, 2.0);
    EXPECT_EQ(result->unit, "feet");
}

TEST_F(LengthTest, should_1_yard_equals_1_yard) {
    length = newLength(1, "yard");
    result = unitTransfer(length, "yard");

    EXPECT_EQ(result->value, 1.0);
    EXPECT_EQ(result->unit, "yard");
}

TEST_F(LengthTest, should_1_foot_equals_12_inches) {
    length = newLength(1, "feet");
    result = unitTransfer(length, "inch");

    EXPECT_EQ(result->value, 12.0);
    EXPECT_EQ(result->unit, "inch");
}

TEST_F(LengthTest, should_3_feet_equals_1_yard) {
    length = newLength(3, "feet");
    result = unitTransfer(length, "yard");

    EXPECT_EQ(result->value, 1);
    EXPECT_EQ(result->unit, "yard");
}

TEST_F(LengthTest, should_1_yard_equals_3_feet) {
    length = newLength(1, "yard");
    result = unitTransfer(length, "feet");

    EXPECT_EQ(result->value, 3);
    EXPECT_EQ(result->unit, "feet");
}

TEST_F(LengthTest, should_1_yard_equals_36_inches) {
    length = newLength(1, "yard");
    result = unitTransfer(length, "inch");

    EXPECT_EQ(result->value, 36);
    EXPECT_EQ(result->unit, "inch");
}

TEST_F(LengthTest, should_12_inches_equals_1_foot) {
    length = newLength(12, "inch");
    result = unitTransfer(length, "feet");

    EXPECT_EQ(result->value, 1);
    EXPECT_EQ(result->unit, "feet");
}

TEST_F(LengthTest, should_36_inches_equals_1_yard) {
    length = newLength(36, "inch");
    result = unitTransfer(length, "yard");

    EXPECT_EQ(result->value, 1);
    EXPECT_EQ(result->unit, "yard");
}

TEST_F(LengthTest, should_18_inches_equals_half_yard) {
    length = newLength(18, "inch");
    result = unitTransfer(length, "yard");

    EXPECT_EQ(result->value, 0.5);
    EXPECT_EQ(result->unit, "yard");
}
