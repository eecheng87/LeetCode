class Solution
{
public:
    int addDigits(int num)
    {
        return help(num);
    }
    int help(int num)
    {
        int tmp = 0;
        if (num < 10)
            return num;
        else
        {
            while (num >= 10)
            {
                tmp += num % 10;
                num /= 10;
            }
            tmp += num;
            return help(tmp);
        }
    }
};