#include <string>
#include <cmath>

#include "format.h"

using std::string;

string Format::ElapsedTime(long seconds) {
int hours = seconds/3600;
int minutes = (seconds%3600)/60;
seconds = seconds%60;
return std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds);
}