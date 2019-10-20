class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int x = coordinates[0][0];
        int y = coordinates[0][1];
        float m = (coordinates[1][0] - x) == 0 ? FLT_MAX : (coordinates[1][1] - y) / (coordinates[1][0] - x);
        int flag = 1;
        //cout<<coordinates[3][0]<<endl;
        for (int i = 2; i < coordinates.size(); ++i)
        {
            if (coordinates[i][0] - x == 0)
            {
                if (m == FLT_MAX)
                    continue;
                else
                    return false;
            }
            else if (m != (float)(coordinates[i][1] - y) / (coordinates[i][0] - x))
            {
                return false;
            }
        }

        return true;
    }
};