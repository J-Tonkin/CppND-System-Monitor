#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"

using std::string;
using std::to_string;
using std::vector;

int Process::Pid() { return pid_; }

float Process::CpuUtilization() { 
    cpuUtilization_ = LinuxParser::ProcessCpu(pid_); //Storing Cpu utilization to simplify sorting
    return cpuUtilization_; //cpuUtilization; 
}

string Process::Command() { return LinuxParser::Command(pid_); }

string Process::Ram() { return std::to_string(std::stoi(LinuxParser::Ram(pid_))/1000); }

string Process::User() { return LinuxParser::User(pid_); }

long int Process::UpTime() { return LinuxParser::UpTime(); }

bool Process::operator<(Process const& a) const { 
     return a.cpuUtilization_ < cpuUtilization_;
     }

//Constructor to take a pid and create a process object
Process::Process(int pid):pid_(pid) {Process::CpuUtilization();} //Calling CpuUtilization to prepopulate field for sorting