#include "processor.h"
#include "linux_parser.h"

#include <vector>

float Processor::Utilization() {
    float idle;
    float nonidle;
    float total;
    cpuUtil_ = LinuxParser::CpuUtilization();
    idle = std::stof(cpuUtil_[4]) + std::stof(cpuUtil_[5]);
    nonidle = std::stof(cpuUtil_[1]) + std::stof(cpuUtil_[2]) + std::stof(cpuUtil_[3]) + std::stof(cpuUtil_[6]) + std::stof(cpuUtil_[7]) + std::stof(cpuUtil_[8]) + std::stof(cpuUtil_[9]) + std::stof(cpuUtil_[10]);
    total = idle + nonidle;
    return (total - idle)/total;
    }