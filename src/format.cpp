#include <iomanip>
#include <sstream>
#include <string>
#include <time.h>
#include "format.h"

using namespace std;

string Format::ElapsedTime(long seconds) {
    try {
        time_t tSeconds(seconds);
        tm* time = gmtime(&tSeconds);
        if (time == nullptr) {
            return "0:0:0";
        }
        stringstream ss;
        ss << setfill('0') << setw(2) << time->tm_hour << ":" << setfill('0') << ::setw(2) << time->tm_min << ":" << setfill('0') << setw(2) << time->tm_sec;
        return ss.str();
    }
    catch (...) {
        return "0:0:0";
    }
}