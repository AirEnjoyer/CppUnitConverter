#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

long double PI = acosl(-1.0L);

void standardize(int *convertingFrom, long double *base, long double *input) {
  switch (*convertingFrom) {
  case 1:
    *base = *input / 1000;
    break;
  case 2:
    *base = *input / 100;
    break;
  case 3:
    *base = *input;
    break;
  case 4:
    *base = *input * 0.3048;
    break;
  case 5:
    *base = *input * 0.9144;
    break;
  case 6:
    *base = *input * 1000;
    break;
  case 7:
    *base = *input * 1609.34;
    break;
  case 8:
    *base = *input * 0.453592;
    break;
  case 9:
    *base = *input;
    break;
  case 10:
    *base = std::cbrt((4.0 / 3.0) * PI * (*input * *input * *input));
    break;
  case 11:
    *base = *input;
    break;
  case 12:
    *base = std::sqrt(*input / PI);
    break;
  case 13:
    *base = std::sqrt(*input / (PI * 4));
    break;
  }
}

void getConvertTo(int *convertingFrom, std::string *options,
                  int *convertingTo) {
  int skip = *convertingFrom;
  int startAt = *convertingFrom <= 7 ? 0 : *convertingFrom <= 9 ? 7 : 9;
  int endAt = *convertingFrom <= 7 ? 6 : *convertingFrom <= 9 ? 9 : 13;
  for (int i = startAt; i < endAt; ++i) {
    if (i == skip - 1) {
      continue;
    }
    std::cout << i - startAt << ". " << options[i] << std::endl;
  }
  std::cin >> *convertingTo;
  (*convertingTo) += startAt + 1;
}

void convert(long double *base, const int *convertingTo, long double *result) {
  switch (convertingTo) {}
}

int main() {

  std::string options[13] = {"Millimetres", "Centimetres", "Metres", "Feet",
                             "Yards",       "Kilometers",  "Miles",  "Pounds",
                             "Kilograms",   "Volume",      "Radius", "Area",
                             "Surface Area"};
  long double input, base, result;
  int convertingTo, convertingFrom;

  std::cout << "Enter what you are converting from" << std::endl;

  for (int i = 0; i < (sizeof(options) / sizeof(options[0])); ++i) {
    std::cout << i + 1 << ". " << options[i] << std::endl;
  }
  std::cin >> convertingFrom;

  std::cout << "Enter what to convert to: " << std::endl;
  getConvertTo(&convertingFrom, options, &convertingTo);

  standardize(&convertingFrom, &base, &input);

  convert(&base, &convertingTo, &result);

  return 0;
}
