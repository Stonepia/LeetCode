#include <algorithm>
using std::abs;

class Solution
{
  public:
    int divide(int dividend, int divisor)
    {
        if (divisor == 1)
            return dividend;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == 0)
            return 0;

        bool negative = (dividend < 0) ^ (divisor > 0);
        dividend = abs(dividend);
        divisor = abs(divisor);

        int result = 0;
        while (dividend >= divisor)
        {
            int count = 1;
            int temp_divisor = divisor;
            while (dividend > (temp_divisor << 1))
            {
                count << 1;
                temp_divisor << 1;
            }
            result += count;
            dividend -= temp_divisor;
        }
        return negative ? -result : result;
    }
};