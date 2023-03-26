#include "Constants.h"

std::string const &Constants::getWhiteSpaces() {
  static const std::string whiteSpaces = " \n\t\v\b\r\f\a";
  return whiteSpaces;
}

std::string const &Constants::getDigits() {
  static const std::string digits = "0123456789-";

  return digits;
}
