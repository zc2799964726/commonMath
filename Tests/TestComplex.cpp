#include <Complex.h>
#include <gtest/gtest.h>

class ComplexTest : public ::testing::Test
{
protected:
    static void SetUpTestCase()
    {}

    static void TearDownTestCase()
    {}

    void SetUp() override
    {}

    void TearDown() override
    {}
};

TEST_F(ComplexTest, ComplexCommonTest)
{
    using namespace CommonMath;
    Complex c1(1, 2);
    Complex c2(1, 2);
    auto c3 = c1 + c2;
    EXPECT_EQ(2, c3.getR());
}
