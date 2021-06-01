#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "linux_parser.h"
#include <vector>

class Processor {
 public:
  float Utilization();

 private:
 std::vector<std::string> cpuUtil_;
};

#endif