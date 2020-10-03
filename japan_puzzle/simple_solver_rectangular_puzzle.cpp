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

#include "simple_solver_rectangular_puzzle.h"
#include "image_utils.h"

bool simple_solver_rectangular_puzzle::generate_next_solution(
    std::vector<std::vector<uint8_t>> &solution) {
  if (!inited) {
    size_t row;
    size_t column;
    if (!find_unknown_cell(row,column)) {
      solution = m_field;
      finished = true;
      return true;
    }

    for (size_t color = 0; color <= num_colors; color++) {
      auto generator_new =
          std::make_shared<simple_solver_rectangular_puzzle>(*this);
      generator_new->m_field[row][column] = color;
      generator_new->m_row_possibilities[row].update_value_on_pos(column,
                                                                  color);
      auto ctask_row =
          [generator_new, row]() { return generator_new->update_by_row(row); };
      generator_new->m_task_queue.push(ctask_row);
      generator_new->m_column_possibilities[column].update_value_on_pos(row,
                                                                        color);
      auto ctask_column = [generator_new, column]() {
        return generator_new->update_by_column(column);
      };
      generator_new->m_task_queue.push(ctask_column);
      if (generator_new->run_row_column_logic()) {
        generators.push(generator_new);
        if (!tracing_path.empty()) {
          generator_new->tracing_path = tracing_path + std::to_string(row) +
                                        "_" + std::to_string(column) + "_" +
                                        std::to_string(color);
          image_utils::save_to_bmp_black_white_puzzle(
              generator_new->m_field, generator_new->tracing_path + ".bmp");
        }
      }
    }
    inited = true;
  }
  while (!generators.empty()) {
    if (generators.top()->generate_next_solution(solution)) {
      if (generators.top()->finished) {
        generators.pop();
      }
      if (!tracing_path.empty()) {
      image_utils::save_to_bmp_black_white_puzzle(
          solution, tracing_path + ".bmp");
      }
      return true;
    } else {
      generators.pop();
    }
  }
  return false;
}
