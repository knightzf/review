struct Airport
{
    typedef map<string, std::pair<Airport*, bool> > AirportMap;
    
    Airport(const std::string& name) : _name(name)
    {
    }
    
    void addDestination(Airport* airport)
    {
        _map[airport->_name] = std::make_pair(airport, true);
    }
    
    string _name;
    AirportMap _map;
};

class Solution {
public:
    typedef map<string, Airport*> SkyMap;
    
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        SkyMap skyMap;
        
        for(size_t i = 0, sz = tickets.size(); i < sz; ++i)
        {
            SkyMap::iterator iter = skyMap.find(tickets[i].first);
            if(iter == skyMap.end())
            {
                skyMap.insert(std::make_pair(tickets[i].first, new Airport(tickets[i].first)));
                iter = skyMap.find(tickets[i].first);
            }
            
            SkyMap::iterator destIter = skyMap.find(tickets[i].second);
            if(destIter == skyMap.end())
            {
                skyMap.insert(std::make_pair(tickets[i].second, new Airport(tickets[i].second)));
                destIter = skyMap.find(tickets[i].second);
            }
            
            iter->second->addDestination(destIter->second);
        }
        
        Airport* start = skyMap["JFK"];
        list<string> temp;
        temp.push_back(start->_name);
        
        findPath(skyMap, start, temp, tickets.size());
        
        vector<string> result;
        while (!temp.empty())
        {
            result.push_back(temp.front());
            temp.pop_front();
        }
        
        return result;
    }
    
    void findPath(SkyMap& skyMap, Airport* airport, list<string>& result, size_t hops)
    {
        if(hops == 0)
            return;
        
        size_t beginSize = result.size();
        
        Airport::AirportMap& destination = airport->_map;
        for(Airport::AirportMap::iterator iter = destination.begin(), end = destination.end();
            iter != end; ++iter)
        {
            if(iter->second.second)
            {
                result.push_back(iter->second.first->_name);
                Airport* next = iter->second.first;
                iter->second.second = false;
                
                findPath(skyMap, next, result, hops - 1);
                
                if(result.size() - beginSize == hops)
                {
                    return;
                }
                else
                {
                    result.pop_back();
                    iter->second.second = true;
                }
            }
        }
    }
};