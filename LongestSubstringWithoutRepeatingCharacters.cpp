using namespace std;
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        vector<char> Vector;
        vector<char>::iterator head;
        int front = 0;
        int rear = 0;
        int ans = 0;
        int size = s.size();
        while (rear < size)
        {
            if (find(Vector.begin(), Vector.end(), s.at(rear)) != Vector.end())
            { //if next element already exist in vector
                Vector.erase(Vector.begin());
                front++;
            }
            else
            { //next element not exist in current vector
                Vector.push_back(s.at(rear));
                rear++;
                ans = ans > rear - front ? ans : rear - front; // minus rear data(cause it is same data as front's)
            }
        }
        return ans;
    }
};