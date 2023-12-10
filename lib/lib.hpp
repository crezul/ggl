#pragma once

#include <cstring>
#include <iostream>
#include "constants.hpp"

namespace ggl {

static void Log(const std::string &message) {
  std::cout << message << std::endl;
}

std::string EncodeRequest(std::string &str) {
  std::string new_str = "";
  char c;
  int ic;
  const char *chars = str.c_str();
  char bufHex[10];
  int len = strlen(chars);

  for (int i = 0; i < len; i++) {
    c = chars[i];
    ic = c;
    // uncomment this if you want to encode spaces with +
    /*if (c==' ') new_str += '+';
    else */
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~')
      new_str += c;
    else {
      sprintf(bufHex, "%X", c);
      if (ic < 16)
        new_str += "%0";
      else
        new_str += "%";
      new_str += bufHex;
    }
  }
  return new_str;
}

// split all arguments to one string
std::string SplitAllArguments(int argc, char *argv[]) {
  std::string arguments = "";
  for (int i = 1; i < argc; i++) {

    if(i == 1 && std::string(argv[i]) == "-a"){
      if(i+2 >= argc)
      {
        Log("Error parameters");
        return "";
      }
      i += 1;
      continue;
    }
    Log(" --- this argument: " + std::string(argv[i]) + "  i: " + std::to_string(i));
    arguments += " ";
    arguments += argv[i];
  }
  Log("  arguments: " + arguments);
  return arguments;
}

std::string GetBrowser(int argc, char *argv[]) {

  if (argc < 2) {
    Log("<2");
    return ggl::SAFARI_BROWSER;
  }

  if (!std::strcmp(argv[1], "-a")) {
    if (!std::strcmp(argv[2], "chrome") || !std::strcmp(argv[2], "c")) {
      return ggl::CHROME_BROWSER;
    }

    if (!std::strcmp(argv[2], "safari") || !std::strcmp(argv[2], "s")) {
      return ggl::SAFARI_BROWSER;
    }

    if (!std::strcmp(argv[2], "firefox") || !std::strcmp(argv[2], "f")) {
      return ggl::FIREFOX_BROWSER;
    }
  }
  return ggl::SAFARI_BROWSER;
}

} // namespace ggl
