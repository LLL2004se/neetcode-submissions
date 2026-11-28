class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkInData;
    unordered_map<string, pair<long long, int>> travelData;

public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        checkInData[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = checkInData[id];

        string route = startStation + "_" + stationName;
        int duration = t - startTime;

        travelData[route].first += duration;
        travelData[route].second++;

        checkInData.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "_" + endStation;

        return (double)travelData[route].first /
               travelData[route].second;
    }
};