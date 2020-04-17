class UndergroundSystem
{
public:
    map<string, vector<int>> mp;
    map<int, pair<string, int>> info;
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        info[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationName, int t)
    {
        if (mp.find(info[id].first + stationName) == mp.end())
        {
            mp[info[id].first + stationName] = vector<int>(2, 0);
        }
        mp[info[id].first + stationName][0] += (t - info[id].second);
        mp[info[id].first + stationName][1]++;
    }

    double getAverageTime(string startStation, string endStation)
    {
        return (double)mp[startStation + endStation][0] / (double)mp[startStation + endStation][1];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */