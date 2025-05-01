#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    std::tm x = {}, y = {};
    std::istringstream s_stream(s), t_stream(t);
    s_stream >> std::get_time(&x, "%H:%M");
    t_stream >> std::get_time(&y, "%H:%M");

    x.tm_hour -= y.tm_hour;
    x.tm_min -= y.tm_min;
    
    if (x.tm_min < 0) {
        x.tm_hour--;
        x.tm_min += 60;
    }

    if (x.tm_hour < 0) {
        x.tm_hour += 24;
    }

    std::cout << std::setfill('0') << std::setw(2) << x.tm_hour << ":" << std::setfill('0') << std::setw(2) << x.tm_min << std::endl;

    return 0;
}

// //End of Code.
