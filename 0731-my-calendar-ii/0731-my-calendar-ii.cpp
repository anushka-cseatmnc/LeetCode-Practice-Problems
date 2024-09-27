class MyCalendarTwo {
    vector<pair<int, int>> bookings;
    map<int, int> overlappedMap;

public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        auto prevVal = overlappedMap.lower_bound(end);
        if (prevVal != overlappedMap.begin()) {
            --prevVal;
            if (prevVal->first < end && start <= prevVal->second - 1) {
                return false;
            }
        }

        for (auto& booking : bookings) {
            int commStart = max(booking.first, start);
            int commEnd = min(booking.second, end);
            if (commStart < commEnd) {
                overlappedMap[commStart] = commEnd;
            }
        }

        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */