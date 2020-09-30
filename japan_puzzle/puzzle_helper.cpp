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

#include "puzzle_helper.h"

using namespace std;

class sum_possibilities
{
public:
    vector<vector<int>> generate(int n, int s)
    {
        if(n==1 && s==1)
        {
            return {{1}};
        }
        num_term = n;
        sum=s;
        vector<vector<int>>  res;

        vector<int> vec(n);
        vec[0]=1;
        int pos=0;
        while(next(vec,pos))
        {
            res.push_back(vec);
        }

        return res;
    }

    bool check(vector<int>& vec, int pos)
    {
        size_t temp_sum = 0;
        for(int i=0;i<=pos;i++)
        {
            temp_sum+=vec[i];
        }
        if(pos==num_term-1 && sum>=temp_sum)
        {
            vec[pos]+=sum-temp_sum;
            return true;
        }
        return sum>=temp_sum+num_term-pos-1;
    }

    bool next(vector<int>& vec, int& pos)
    {
        if(pos==num_term-1)
        {
            increment(vec,pos);
        }

        return full_continuation(vec,pos);
    }

    bool full_continuation(vector<int>& vec, int& pos)
    {
        while(pos<num_term-1 && pos>=0)
        {
            if(!step_continuation(vec,pos))
            {
                increment(vec,pos);
            }
        }
        if(pos<0)
            return false;
        return true;
    }

    bool step_continuation(vector<int>& vec, int& pos)
    {
        pos++;
        vec[pos]=0;
        while(vec[pos]<num_term-1)
        {
            vec[pos]++;
            if(check(vec,pos))
                return true;
        }
        pos--;
        return false;
    }

    void increment(vector<int>& vec, int& pos)
    {
        while(pos>=0)
        {
            while(vec[pos]<=sum)
            {
                vec[pos]++;
                if(check(vec,pos))
                    return;
            }
            pos--;
        }
    }

private:
    int num_term;
    int sum;
};

std::vector<std::vector<int> > puzzle_helper::possible_sums(int sum, int num_term)
{
    sum_possibilities generator;
    return generator.generate(num_term, sum);
}
