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
#include "image_utils.h"

void test(const std::vector<std::vector<size_t>> &rows_c,
          const std::vector<std::vector<size_t>> &columns_c) {
    standart_japan_puzzle puzzle(rows_c, columns_c);
    puzzle.start_row_column_logic();
    auto sol = puzzle.get_result();
    image_utils::save_to_bmp_black_white_puzzle(
        sol, "C:/repoBitB/japan_puzzle/japan_puzzle/img.bmp");
}

void test1() {
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
  test(rows_c, columns_c);
}

void test2() {
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
  test(rows_c, columns_c);
}

int main() {
  test2();

  return 0;
}
