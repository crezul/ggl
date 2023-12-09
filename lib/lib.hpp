#pragma once

#include <iostream>


namespace ggl {
  static void Log(const std::string &message){
    std::cout << message << std::endl;
  }
}
