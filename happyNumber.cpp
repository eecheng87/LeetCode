using namespace std;
class Solution
{
  public:
    bool isHappy(int n)
    {

        vector<int> repeat;

        return check(n, repeat);
    }

    bool check(int n, vector<int> repeat)
    {

        int sum = 0;

        if (n == 1)
            return true;
        for (int i = 0; i < repeat.size(); i++)
        {
            //cout<<repeat[i]<<endl;;
            if (repeat[i] == n)
                return false;
        }

        repeat.push_back(n);
        while (n / 10 != 0)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        sum = sum + n * n;
        return check(sum, repeat);
    }
};