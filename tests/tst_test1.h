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
    double* roots = (double*)malloc(2 * sizeof(double));
    myfunc(roots, 4, -1, -5);
    ASSERT_EQ(roots[0], 1.25);
    ASSERT_EQ(roots[1], -1.00);
    free(roots);
}

TEST(mytestB, root1)
{
    double* roots = (double*)malloc(2 * sizeof(double));
    myfunc(roots, 1, 12, 36);
    ASSERT_EQ(roots[0], -6.00);
    ASSERT_TRUE(isnan(roots[1]));
    free(roots);
}

TEST(mytestB, root0)
{
    double* roots = (double*)malloc(2 * sizeof(double));
    myfunc(roots, 2, 1, 67);
    ASSERT_TRUE(isnan(roots[0]));
    ASSERT_TRUE(isnan(roots[1]));
    free(roots);
}

TEST(mytestI, integrated)
{
    double* roots = (double*)malloc(2 * sizeof(double));
    myfunc(roots, 1, -6, 9);
    ASSERT_EQ(fibonachi((int)roots[0]), 2);
    free(roots);
}

#endif // MYTEST_H
