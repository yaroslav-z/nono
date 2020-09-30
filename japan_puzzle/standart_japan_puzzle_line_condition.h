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

#ifndef STANDART_JAPAN_PUZZLE_CONDITION_LINE_CONDITION_H
#define STANDART_JAPAN_PUZZLE_CONDITION_LINE_CONDITION_H

#include <puzzle_conditions.h>

class standart_japan_puzzle_line_condition : public line_conditions {
public:
  standart_japan_puzzle_line_condition(
      const std::vector<size_t> &values_sublines, size_t line_length);

  std::list<std::vector<uint8_t> > generate_possibilities() const override;

private:
  std::vector<size_t> m_values_sublines;
  size_t m_line_length;
};

#endif // STANDART_JAPAN_PUZZLE_CONDITION_LINE_CONDITION_H
