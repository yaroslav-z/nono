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
#include "standart_japan_puzzle_line_condition.h"

standart_japan_puzzle::standart_japan_puzzle(const std::vector<std::vector<size_t> > &row_cond, const std::vector<std::vector<size_t> > &column_cond)
{
    puzzle_conditions conditions;
    size_t rows = row_cond.size();
    size_t columns = column_cond.size();
    for(size_t i=0;i<rows;i++)
    {
        conditions.row_conditions.push_back(std::make_shared<standart_japan_puzzle_line_condition>( standart_japan_puzzle_line_condition(row_cond[i], columns)));
    }

    for(size_t i=0;i<columns;i++)
    {
        conditions.column_conditions.push_back(std::make_shared<standart_japan_puzzle_line_condition>(column_cond[i], rows));
    }
    init_by_conditions(conditions);
}
