#include <map>

class MyCalendar {
    std::map<int, int> calendar;

public:
    MyCalendar() {}

    bool book(int start, int end) {
        auto it = calendar.lower_bound(end);

        if (it != calendar.begin()) {
            auto prev = std::prev(it);
            if (prev->second > start) {
                return false;
            }
        }

        calendar[start] = end;
        return true;
    }
};
