#include <iostream>
#include "lib.hpp"
using namespace ggl;

void PrintHead() {
  std::cout << "ggl - google search, version 0.3.1" << std::endl;
}

int main(int argc, char *argv[]) {
  PrintHead();
  std::string arguments = SplitAllArguments(argc, argv);
  arguments = EncodeRequest(arguments);
  std::string browser = ggl::GetBrowser(argc, argv);
  std::string searching = "https://www.google.com/search?q=" + arguments;
  std::string command = "open -a \"" + browser + "\" -u '" + searching + "'";
  system(command.c_str());
  return 0;
}
