class Solution
{
public:
    int kConcatenationMaxSum(vector<int> &arr, int k)
    {
        long long sum = 0;
        long long mod = 1000000007;
        for (int i = 0; i < arr.size(); ++i)
        {
            sum += arr[i];
        }
        cout << sum << endl;
        if (sum > 0)
        {
            long long left = leftM(arr);
            long long right = rightM(arr);
            cout << left << endl;
            cout << right << endl;
            cout << sum * (k - 2) + left + right << endl;
            if (k > 2)
                return sum * k > sum * (k - 2) + left + right ? sum * k % mod : (sum * (k - 2) + left + right) % mod;
            else if (k == 2)
                return left + right;
            else
                return sum;
        }

        vector<int> a(arr.begin(), arr.end());
        a.insert(a.end(), arr.begin(), arr.end());
        int max1 = subMax(arr);
        int max2 = subMax(a);
        if (max1 < 0 && max2 < 0)
            return 0;
        return max1 > max2 ? max1 : max2;
    }
    int subMax(vector<int> v)
    {
        long long sum = v[0];
        int max = v[0];
        for (int i = 1; i < v.size(); ++i)
        {
            sum = sum + v[i] > v[i] ? sum + v[i] : v[i];
            max = sum > max ? sum : max;
        }
        return max;
    }
    int leftM(vector<int> arr)
    {
        int max = arr[0];
        long long sum = arr[0];
        for (int i = 1; i < arr.size(); ++i)
        {
            sum += arr[i];
            max = max > sum ? max : sum;
        }
        return max;
    }
    int rightM(vector<int> arr)
    {
        int max = arr.back();
        long long sum = arr.back();
        for (int i = arr.size() - 2; i >= 0; --i)
        {
            sum += arr[i];
            max = max > sum ? max : sum;
        }
        return max;
    }
};