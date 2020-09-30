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

#include "standart_japan_puzzle_line_condition.h"

#include <iostream>
#include <gtest/gtest.h>

class standart_condition_test
{
public:
    void generator_check(const std::list<std::vector<uint8_t>>& results, std::vector<size_t>& vec_lines_length, size_t length)
    {
        for(const auto& result : results)
        {
            //check_result(result);
        }
    }
};

TEST(standart_condition_test, test_generation_simple)
{
    std::vector<size_t> vec = {1};
    standart_japan_puzzle_line_condition condition(vec, 7);
    auto possibilities = condition.generate_possibilities();
    ASSERT_EQ(possibilities.size(), 7);
}

TEST(standart_condition_test, test_generation_simple_2_segments)
{
    std::vector<size_t> vec = {1,2};
    standart_japan_puzzle_line_condition condition(vec, 7);
    auto possibilities = condition.generate_possibilities();
    ASSERT_EQ(possibilities.size(), 10);
}

TEST(standart_condition_test, test_generation_simple_1_possibility)
{
    std::vector<size_t> vec = {1,2,2};
    standart_japan_puzzle_line_condition condition(vec, 7);
    auto possibilities = condition.generate_possibilities();
    ASSERT_EQ(possibilities.size(), 1);
    ASSERT_EQ(possibilities.front(), std::vector<uint8_t>({1,0,1,1,0,1,1}));
}
