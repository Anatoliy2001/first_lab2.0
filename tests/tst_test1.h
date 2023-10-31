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
    double* roots = static_cast<double*>(malloc(2 * sizeof(double)));
    roots = myfunc(4, -1, -5, roots);
    ASSERT_EQ(roots[0], 1.25);
    ASSERT_EQ(roots[1], -1.00);
    free(roots);
}

TEST(mytestB, root1)
{
    double* roots = static_cast<double*>(malloc(2 * sizeof(double)));
    roots = myfunc(1, 12, 36, roots);
    ASSERT_EQ(roots[0], -6.00);
    ASSERT_TRUE(isnan(roots[1]));
    free(roots);
}

TEST(mytestB, root0)
{
    double* roots = static_cast<double*>(malloc(2 * sizeof(double)));
    roots = myfunc(2, 1, 67, roots);
    ASSERT_TRUE(isnan(roots[0]));
    ASSERT_TRUE(isnan(roots[1]));
}

TEST(mytestI, integrated)
{
    double* roots = static_cast<double*>(malloc(2 * sizeof(double)));
    roots = myfunc(1, -6, 9, roots);
    ASSERT_EQ(fibonachi((int)roots[0]), 2);
}

#endif // MYTEST_H
