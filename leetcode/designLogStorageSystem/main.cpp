#include "header.h"

struct Datetime
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;

    bool operator<(const Datetime& rhs) const
    {
        return tie(year, month, day, hour, minute, second) <
            tie(rhs.year, rhs.month, rhs.day, rhs.hour, rhs.minute, rhs.second);
    }

    void setdefault(const string& gra, bool start)
    {
        if(start)
        {
            if(gra == "Second") return;
            second = 0;
            if(gra == "Minute") return;
            minute = 0;
            if(gra == "Hour") return;
            hour = 0;
            if(gra == "Day") return;
            day = 0;
            if(gra == "Month") return;
            month = 0;
        }
        else
        {
            if(gra == "Second") return;
            second = 59;
            if(gra == "Minute") return;
            minute = 59;
            if(gra == "Hour") return;
            hour = 23;
            if(gra == "Day") return;
            day = 31;
            if(gra == "Month") return;
            month = 12;
        }
    }
};

class LogSystem {
    map<Datetime, int> m;
public:
    LogSystem() {

    }

    Datetime parse(const string& ts)
    {
        stringstream s(ts);
        int year, month, day, hour, minute, second;
        char dummy;
        s >> year >> dummy >> month >> dummy >> day >> dummy >> hour >> dummy >> minute >> dummy >> second;
        return Datetime{year, month, day, hour, minute, second};
    }

    void put(int id, string timestamp) {

        m.emplace(parse(timestamp), id);
    }

    vector<int> retrieve(string s, string e, string gra) {
        Datetime start = parse(s);
        Datetime end = parse(e);
        start.setdefault(gra, true);
        end.setdefault(gra, false);
        auto iter = m.lower_bound(start);
        auto jter = m.upper_bound(end);
        vector<int> res;
        for(auto i = iter; i != jter; ++i)
            res.push_back(i->second);
        return res;
    }
};




int main() {
    //Solution s;

}
