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
#include "puzzle_helper.h"

standart_japan_puzzle_line_condition::
    standart_japan_puzzle_line_condition(
        const std::vector<size_t> &values_sublines, size_t line_length)
    : m_values_sublines(values_sublines), m_line_length(line_length) {}

std::list<std::vector<uint8_t>>
standart_japan_puzzle_line_condition::generate_possibilities() const {
  std::list<std::vector<uint8_t>> list;

  auto num_sublines = m_values_sublines.size();
  size_t sum=0;
  for(const auto& sub_line : m_values_sublines)
  {
      sum+=sub_line;
  }

  auto empty_lines_lengths_possibilities =
      puzzle_helper::possible_sums((m_line_length + 2) - sum, num_sublines + 1);
  for (const auto &empty_lines_lengths : empty_lines_lengths_possibilities) {
    std::vector<uint8_t> vec(m_line_length, 0);
    size_t pos = empty_lines_lengths[0]-1;
    for (size_t i = 0; i < num_sublines; i++) {
      for (size_t p = pos; p < pos + m_values_sublines[i]; p++) {
        vec[p] = 1;
      }
      pos += m_values_sublines[i];
      pos += empty_lines_lengths[i+1];
    }
    list.push_back(vec);
  }

  return list;
}
