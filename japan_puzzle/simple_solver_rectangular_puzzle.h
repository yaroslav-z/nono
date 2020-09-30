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

#ifndef SIMPLE_SOLVER_RECTANGULAR_PUZZLE_H
#define SIMPLE_SOLVER_RECTANGULAR_PUZZLE_H

#include "simple_row_column_logic_solver_rectangular.h"
#include "simple_solution_generator.h"

class simple_solver_rectangular_puzzle
    : public simple_row_column_logic_solver_rectangular,
      public simple_solution_generator<std::vector<std::vector<uint8_t>>> {
protected:
  bool
  generate_next_solution(std::vector<std::vector<uint8_t>> &solution) override;
};

#endif // SIMPLE_SOLVER_RECTANGULAR_PUZZLE_H
