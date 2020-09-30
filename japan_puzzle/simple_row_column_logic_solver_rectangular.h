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

/***
 * We suppose use this class for solve next puzzles:
 * standart japan puzzle (Nonogrids)
 * standart japan puzzle with unknown values
 * standart japan puzzle with blocks
 * "inverted"
***/


#ifndef SIMPLE_ROW_COLUMN_LOGIC_SOLVER_RECTANGULAR_H
#define SIMPLE_ROW_COLUMN_LOGIC_SOLVER_RECTANGULAR_H

#include "simple_row_column_logic_solver.h"

#include <queue>

class simple_row_column_logic_solver_rectangular : public simple_row_column_logic_solver_convex
{
public:
    void init_by_conditions(const puzzle_conditions& conditions) override;
    bool start_row_column_logic() override;
    bool run_row_column_logic() override;
    std::vector<std::vector<uint8_t> > get_result() const;

protected:
    typedef std::function<bool()> task;

    bool update_by_row(line_length row);
    bool update_by_column(line_length column);

protected:
    std::vector<std::vector<uint8_t> > m_field;
    std::queue<task> m_task_queue;
};

#endif // SIMPLE_ROW_COLUMN_LOGIC_SOLVER_RECTANGULAR_H
