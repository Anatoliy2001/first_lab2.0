#ifndef MYTEST_H
#define MYTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>

/* using namespace testing; */
extern "C" {
#include "myfunc.h"
}

TEST(mytestB, root2)
{
    double* result = myfunc(4, -1, -5);
    ASSERT_EQ(result[0], 1.25);
    ASSERT_EQ(result[1], -1.00);
}

TEST(mytestB, root1)
{
    double* result = myfunc(1, 12, 36);
    ASSERT_EQ(result[0], -6.00);
    ASSERT_TRUE(isnan(result[1]));
}

TEST(mytestB, root0)
{
    double* result = myfunc(2, 1, 67);
    ASSERT_TRUE(isnan(result[0]));
    ASSERT_TRUE(isnan(result[1]));
}

TEST(mytestI, integrated)
{
    double* result = myfunc(1, -6, 9);
    ASSERT_EQ(fibonachi((int)result[0]), 2);
}

#endif // MYTEST_H
