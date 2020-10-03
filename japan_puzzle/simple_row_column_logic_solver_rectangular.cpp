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

#include "simple_row_column_logic_solver_rectangular.h"

void simple_row_column_logic_solver_rectangular::init_by_conditions(
    const puzzle_conditions &conditions) {
  simple_row_column_logic_solver_convex::init_by_conditions(conditions);
  std::vector<uint8_t> vec(m_num_columns, unknown_color);
  m_field.resize(m_num_rows, vec);
}

bool simple_row_column_logic_solver_rectangular::start_row_column_logic() {
  for (size_t row = 0; row < m_num_rows; row++) {
    std::vector<uint8_t> vec;
    if (!m_row_possibilities[row].generate_possible_line(vec)) {
      return false;
    }

    for (size_t pos = 0; pos < vec.size(); pos++) {
      if (vec[pos] != unknown_color && vec[pos] != m_field[row][pos]) {
        if (m_field[row][pos] == unknown_color) {
          m_field[row][pos] = vec[pos];
          m_column_possibilities[pos].update_value_on_pos(row, vec[pos]);
        } else {
          return false;
        }
      }
    }
  }

  for (size_t column = 0; column < m_num_columns; column++) {
    std::vector<uint8_t> vec;
    if (!m_column_possibilities[column].generate_possible_line(vec)) {
      return false;
    }

    for (size_t pos = 0; pos < vec.size(); pos++) {
      if (vec[pos] != unknown_color && vec[pos] != m_field[pos][column]) {
        if (m_field[pos][column] == unknown_color) {
          m_field[pos][column] = vec[pos];
          m_row_possibilities[pos].update_value_on_pos(column, vec[pos]);
          auto ctask = [this, pos]() { return this->update_by_row(pos); };
          m_task_queue.push(ctask);
        } else {
          return false;
        }
      }
    }
  }
  return run_row_column_logic();
}

bool simple_row_column_logic_solver_rectangular::run_row_column_logic() {
  while (!m_task_queue.empty()) {
    auto task = m_task_queue.front();
    if (!task()) {
      return false;
    }
    m_task_queue.pop();
  }
  return true;
}

std::vector<std::vector<uint8_t> > simple_row_column_logic_solver_rectangular::get_result() const
{
    return m_field;
}

bool
simple_row_column_logic_solver_rectangular::update_by_row(line_length row) {
    std::vector<uint8_t> vec;
    if (!m_row_possibilities[row].generate_possible_line(vec)) {
      return false;
    }

    for (size_t pos = 0; pos < vec.size(); pos++) {
      if (vec[pos] != unknown_color && vec[pos] != m_field[row][pos]) {
        if (m_field[row][pos] == unknown_color) {
          m_field[row][pos] = vec[pos];
          m_column_possibilities[pos].update_value_on_pos(row, vec[pos]);
          auto ctask = [this, pos]() { return this->update_by_column(pos); };
          m_task_queue.push(ctask);
        } else {
          return false;
        }
      }
    }
  return true;
}

bool
simple_row_column_logic_solver_rectangular::update_by_column(line_length column) {
    std::vector<uint8_t> vec;
    if (!m_column_possibilities[column].generate_possible_line(vec)) {
      return false;
    }

    for (size_t pos = 0; pos < vec.size(); pos++) {
      if (vec[pos] != unknown_color && vec[pos] != m_field[pos][column]) {
        if (m_field[pos][column] == unknown_color) {
          m_field[pos][column] = vec[pos];
          m_row_possibilities[pos].update_value_on_pos(column, vec[pos]);
          auto ctask = [this, pos]() { return this->update_by_row(pos); };
          m_task_queue.push(ctask);
        } else {
          return false;
        }
      }
    }
    return true;
}

bool simple_row_column_logic_solver_rectangular::find_unknown_cell(size_t &row, size_t &column)
{
    for (size_t r = 0; r < m_field.size(); r++) {
      for (size_t c = 0; c < m_field[0].size(); c++) {
        if (m_field[r][c] == unknown_color) {
          row = r;
          column = c;
          return true;
        }
      }
    }
    return false;
}
