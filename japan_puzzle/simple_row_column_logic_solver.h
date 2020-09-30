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

#ifndef SIMPLE_ROW_COLUMN_LOGIC_SOLVER_H
#define SIMPLE_ROW_COLUMN_LOGIC_SOLVER_H

#include <puzzle_conditions.h>

const uint8_t unknown_color = 255;
typedef size_t line_length;

class line_possibilities {
public:
  line_possibilities(const std::shared_ptr<line_conditions>& conditions) {
    m_possibilities = conditions->generate_possibilities();
  }

  void update_value_on_pos(line_length pos, uint8_t value) {
    m_possibilities.remove_if([pos, value](const std::vector<uint8_t> &vec) {
      return vec[pos] != value;
    });
  }

  bool generate_possible_line(std::vector<uint8_t> &vec) {
    if (m_possibilities.empty()) {
      return false;
    }

    auto length = m_possibilities.front().size();
    std::copy(m_possibilities.front().begin(), m_possibilities.front().end(),
              std::back_inserter(vec));
    for (const auto& possibility : m_possibilities) {
      for (line_length i = 0; i < length; i++) {
        if (possibility[i] != vec[i]) {
          vec[i] = unknown_color;
        }
      }
    }

//    std::vector<uint8_t> temp_vec = m_possibilities.front();
//    auto length = temp_vec.size();
//    for (const auto& possibility : m_possibilities) {
//      for (line_length i = 0; i < length; i++) {
//        if (possibility[i] != vec[i]) {
//          temp_vec[i] = unknown_color;
//        }
//      }
//    }
//    vec = temp_vec;

    return true;
  }

private:
  std::list<std::vector<uint8_t>> m_possibilities;
};

class simple_row_column_logic_solver {
public:
  virtual void init_by_conditions(const puzzle_conditions &conditions) = 0;
  virtual bool start_row_column_logic() = 0;
  virtual bool run_row_column_logic() = 0;
};

class simple_row_column_logic_solver_convex
    : public simple_row_column_logic_solver {
public:
  void init_by_conditions(const puzzle_conditions &conditions) override {
    m_column_possibilities.clear();
    m_num_columns = conditions.column_conditions.size();
    for (const auto &condition : conditions.column_conditions) {
      m_column_possibilities.push_back(line_possibilities(condition));
    }

    m_row_possibilities.clear();
    m_num_rows = conditions.row_conditions.size();
    for (size_t i=0;i<conditions.row_conditions.size();i++) {
      m_row_possibilities.push_back(line_possibilities(conditions.row_conditions[i]));
    }
  }

protected:
  std::vector<line_possibilities> m_column_possibilities;
  std::vector<line_possibilities> m_row_possibilities;
  size_t m_num_columns;
  size_t m_num_rows;
};

#endif // SIMPLE_ROW_COLUMN_LOGIC_SOLVER_H
