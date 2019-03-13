class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        double median;
        int i;
        //handle empty situation
        if (nums1.empty())
        {
            if (n % 2 == 1)
            { //odd
                return nums2.at((n - 1) / 2);
            }
            else
            { //even
                return (double)(nums2.at((n / 2)) + nums2.at((n / 2) - 1)) / 2;
            }
        }
        if (nums2.empty())
        {
            if (m % 2 == 1)
            { //odd
                return nums1.at((m - 1) / 2);
            }
            else
            { //even
                return (double)(nums1.at((m / 2)) + nums1.at((m / 2) - 1)) / 2;
            }
        }

        if ((m + n) % 2 == 1)
        { //odd
            int med_index = (m + n - 1) / 2;
            for (i = 0; i <= med_index; i++)
            {
                if (i == med_index)
                {
                    median = nums1.front() > nums2.front() ? nums2.front() : nums1.front();
                }
                if (nums1.empty())
                {
                    return nums2.at(med_index - i);
                }
                if (nums2.empty())
                {
                    return nums1.at(med_index - i);
                }

                if (nums1.front() > nums2.front())
                {
                    nums2.erase(nums2.begin());
                }
                else if (nums1.front() < nums2.front())
                {
                    nums1.erase(nums1.begin());
                }
                else
                { //equal
                    if (nums1.size() > nums2.size())
                    {
                        nums1.erase(nums1.begin());
                    }
                    else
                    {
                        nums2.erase(nums2.begin());
                    }
                }
            }
        }
        else
        {
            int med_index_one = (m + n) / 2 - 1;
            int med_index_two = (m + n) / 2;
            for (i = 0; i < med_index_two; i++)
            {
                if (i == med_index_one)
                {
                    median = nums1.front() > nums2.front() ? nums2.front() : nums1.front();
                }
                if (nums1.empty())
                {
                    return (double)(nums2.at(med_index_one - i) + nums2.at(med_index_two - i)) / 2;
                }
                if (nums2.empty())
                {
                    return (double)(nums1.at(med_index_one - i) + nums1.at(med_index_two - i)) / 2;
                }
                if (nums1.front() > nums2.front())
                {
                    nums2.erase(nums2.begin());
                }
                else if (nums1.front() < nums2.front())
                {
                    nums1.erase(nums1.begin());
                }
                else
                { //equal
                    if (nums1.size() > nums2.size())
                    {
                        nums1.erase(nums1.begin());
                    }
                    else
                    {
                        nums2.erase(nums2.begin());
                    }
                }
            }

            if (nums1.empty())
            {
                median = (median + (double)nums2.front()) / 2;
            }
            else if (nums2.empty())
            {
                median = (median + (double)nums1.front()) / 2;
            }
            else if (nums1.front() > nums2.front())
            {
                median = (median + (double)nums2.front()) / 2;
            }
            else if (nums1.front() <= nums2.front())
            {
                median = (median + (double)nums1.front()) / 2;
            }
        }

        return median;
    }
};