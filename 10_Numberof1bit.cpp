class Solution {
public:
    int NumberOf1(int n)
    {
        // Number of 1-bit in integer.

        int count = 0;

        while (n)
        {
            count++;
            n = n & (n - 1);  // set rightmost 1-bit and bits righter to be 0
        }

        return count;
    }
};