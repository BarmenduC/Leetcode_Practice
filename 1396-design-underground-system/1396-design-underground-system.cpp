class UndergroundSystem {
    unordered_map<int, pair<string, int>> checkedIn;
    unordered_map<string, vector<int>> totalTime;
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkedIn[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        const auto route = checkedIn[id].first + " " + stationName;
        totalTime [route].push_back(t-checkedIn[id].second);
        checkedIn[id].first = "";
        checkedIn[id].second = 0;
    }
    
    double getAverageTime(string startStation, string endStation) {
        const auto totTime =  totalTime[startStation+" "+endStation];
        int res = 0;
        for (const auto& tripTime : totTime) {
            res += tripTime;
        }
        return res/(totTime.size()*1.0);
    }
};