// Copyright (c) 2020 Zhurba Yaroslav

// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:

// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include <iostream>
#include <gtest/gtest.h>
#include "puzzle_helper.h"

class puzzle_helper_test :public ::testing::Test
{

};

TEST_F(puzzle_helper_test, possible_sums)
{
    auto results = puzzle_helper::possible_sums(5, 2);
    ASSERT_EQ(results.size(),4);
    for(const auto& result : results )
    {
        ASSERT_EQ(result.size(),2);
        ASSERT_EQ(result[0]+result[1],5);
    }
}

TEST_F(puzzle_helper_test, possible_sums1)
{
    auto res = puzzle_helper::possible_sums(1, 1);
    ASSERT_EQ(res.size(),1);
}
