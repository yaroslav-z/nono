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

#include "standart_japan_puzzle.h"

#include <iostream>
#include <gtest/gtest.h>

class standart_nono_test :public ::testing::Test
{
public:
    void nono_test(const std::vector<std::vector<size_t>>& rows, const std::vector<std::vector<size_t>>& columns, const std::vector<std::vector<uint8_t>>& expected)
    {
        standart_japan_puzzle puzzle(rows, columns);
        EXPECT_TRUE(puzzle.start_row_column_logic());
        auto sol = puzzle.get_result();
        EXPECT_EQ(sol, expected);
    }
};

TEST_F(standart_nono_test, test1)
{
    std::vector<std::vector<size_t>> rows_c = {{3},
                                               {2},
                                               {1, 1},
                                               {2},
                                               {3},
                                               {1,1}};

    std::vector<std::vector<size_t>> columns_c = {{1,1,2},
                                                  {1, 2},
                                                  {6},
                                                  {1}};

    std::vector<std::vector<uint8_t>> expected = {{1,1,1,0},
                                                  {0,0,1,1},
                                                  {1,0,1,0},
                                                  {0,1,1,0},
                                                  {1,1,1,0},
                                                  {1,0,1,0}};
    nono_test(rows_c, columns_c, expected);
}

TEST_F(standart_nono_test, test2)
{
    std::vector<std::vector<size_t>> rows_c = {{3},
                                               {5},
                                               {3, 1},
                                               {2, 1},
                                               {3, 3, 4},
                                               {2, 2, 7},
                                               {6, 1, 1},
                                               {4, 2, 2},
                                               {1, 1},
                                               {3, 1},
                                               {6},
                                               {2, 7},
                                               {6, 3, 1},
                                               {1, 2, 2, 1, 1},
                                               {4, 1, 1, 3},
                                               {4, 2, 2},
                                               {3, 3, 1},
                                               {3, 3},
                                               {3},
                                               {2, 1}};

    std::vector<std::vector<size_t>> columns_c = {{2},
                                                  {1, 2},
                                                  {2, 3},
                                                  {2, 3},
                                                  {3, 1, 1},
                                                  {2, 1, 1},
                                                  {1, 1, 1, 2, 2},
                                                  {1, 1, 3, 1, 3},
                                                  {2, 6, 4},
                                                  {3, 3, 9, 1},
                                                  {5, 3, 2},
                                                  {3, 1, 2, 2},
                                                  {2, 1, 7},
                                                  {3, 3, 2},
                                                  {2, 4},
                                                  {2, 1, 2},
                                                  {2, 2, 1},
                                                  {2, 2},
                                                  {1},
                                                  {1}};

    std::vector<std::vector<uint8_t>> expected = {{1,1,1,0},
                                                  {0,0,1,1},
                                                  {1,0,1,0},
                                                  {0,1,1,0},
                                                  {1,1,1,0},
                                                  {1,0,1,0}};
    nono_test(rows_c, columns_c, expected);
}

TEST_F(standart_nono_test, test2)
{
    std::vector<std::vector<size_t>> rows_c = {{3},
                                               {5},
                                               {3, 1},
                                               {2, 1},
                                               {3, 3, 4},
                                               {2, 2, 7},
                                               {6, 1, 1},
                                               {4, 2, 2},
                                               {1, 1},
                                               {3, 1},
                                               {6},
                                               {2, 7},
                                               {6, 3, 1},
                                               {1, 2, 2, 1, 1},
                                               {4, 1, 1, 3},
                                               {4, 2, 2},
                                               {3, 3, 1},
                                               {3, 3},
                                               {3},
                                               {2, 1}};

    std::vector<std::vector<size_t>> columns_c = {{2},
                                                  {1, 2},
                                                  {2, 3},
                                                  {2, 3},
                                                  {3, 1, 1},
                                                  {2, 1, 1},
                                                  {1, 1, 1, 2, 2},
                                                  {1, 1, 3, 1, 3},
                                                  {2, 6, 4},
                                                  {3, 3, 9, 1},
                                                  {5, 3, 2},
                                                  {3, 1, 2, 2},
                                                  {2, 1, 7},
                                                  {3, 3, 2},
                                                  {2, 4},
                                                  {2, 1, 2},
                                                  {2, 2, 1},
                                                  {2, 2},
                                                  {1},
                                                  {1}};

    std::vector<std::vector<uint8_t>> expected = {{1,1,1,0},
                                                  {0,0,1,1},
                                                  {1,0,1,0},
                                                  {0,1,1,0},
                                                  {1,1,1,0},
                                                  {1,0,1,0}};
    nono_test(rows_c, columns_c, expected);
}

TEST_F(standart_nono_test, test3)
{
    std::vector<std::vector<size_t>> rows_c = {{7,2},
                                               {13},
                                               {13, 2},
                                               {6, 4},
                                               {8, 3},
                                               {5,3},
                                               {5,3},
                                               {11,1},
                                               {2,1,2,3},
                                               {2,2,7},
                                               {1,2,9},
                                               {1,8},
                                               {7, 1},
                                               {8, 1},
                                               {11,2},
                                               {10, 2},
                                               {1,7,2},
                                               {4,3, 3},
                                               {7},
                                               {5}};

    std::vector<std::vector<size_t>> columns_c = {{1},
                                                  {3,1},
                                                  {7, 3},
                                                  {5,1,2,1},
                                                  {7,3, 1},
                                                  {6,3, 1},
                                                  {5,3,3,1},
                                                  {4,4,6},
                                                  {5,1,1,7},
                                                  {3, 1,1,8},
                                                  {3, 1,1,6,2},
                                                  {3, 1, 6,1,1},
                                                  {3, 1, 5,1,1},
                                                  {3,2,6,1},
                                                  {3,2,5,1},
                                                  {2, 2,5,2},
                                                  {4,4,2},
                                                  {2, 2, 8},
                                                  {4, 2},
                                                  {2,2}};

    std::vector<std::vector<uint8_t>> expected = {{1,1,1,0},
                                                  {0,0,1,1},
                                                  {1,0,1,0},
                                                  {0,1,1,0},
                                                  {1,1,1,0},
                                                  {1,0,1,0}};
    nono_test(rows_c, columns_c, expected);
}



