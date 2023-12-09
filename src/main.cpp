#include <iostream>

// function that will parse the command line and return a string
std::string ParseCommandLine(int argc, char *argv[]);
std::string SplitAllArguments(int argc, char *argv[]);
std::string EncodeRequest(std::string &request);

int main(int argc, char *argv[]) {
  ParseCommandLine(argc, argv);

  std::cout << "ggl - google search, version 0.2" << std::endl;
  //  std::cout << "   version 0.2" << std::endl;
  //  std::cout << "   usage: ggl [search]" << std::endl;
  //  std::cout << "   example: ggl hello world" << std::endl;

  std::string arguments = SplitAllArguments(argc, argv);
  arguments = EncodeRequest(arguments);
  std::string searching = "https://www.google.com/search?q=" + arguments;
  std::string command =
      "open -a /Applications/Firefox.app/Contents/MacOS/firefox -u '" +
      searching + "'";
  system(command.c_str());
  return 0;
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
    std::cout << argv[i] << std::endl;
    arguments += " ";
    arguments += argv[i];
  }
  return arguments;
}

// create function that will parse the command line and return a string
std::string ParseCommandLine(int argc, char *argv[]) {
  for (int i = 0; i < argc; i++) {
  }
  return "";
}
