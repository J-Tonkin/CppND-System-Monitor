#include <string>
#include <cmath>

#include "format.h"

using std::string;

string Format::ElapsedTime(long seconds) {
int hours = seconds/3600;
int minutes = (seconds%3600)/60;
seconds = seconds%60;
string hoursStr = std::to_string(hours);
string minutesStr = std::to_string(minutes);
string secondsStr = std::to_string(seconds);
minutesStr.insert(0, 2 - minutesStr.length(),'0');         //inserts an extra zero if the string is less than 2 digits 
secondsStr.insert(0, 2 - secondsStr.length(),'0');         //second term (2 - str.length()) determines how many characters to add i.e if 2 add none, if 1 add one
return hoursStr + ":" + minutesStr + ":" + secondsStr;
}