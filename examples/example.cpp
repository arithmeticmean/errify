#include "../errify.hpp"
#include <expected>
#include <iostream>

// custom error by extending Errify::BaseError
class ErrorDivisionByZero : public Errify::BaseError {
public:
  ErrorDivisionByZero(const std::string &msg) : Errify::BaseError(msg) {}
};

// alias
using Error = Errify::Error;

// failable function
std::expected<int, Error> divide(int a, int b) {
  if (!b) {
    return std::unexpected(Error(ErrorDivisionByZero("can't divide by zero.")));
  }
  return a / b;
}

int main() {
  int a1 = 10;
  int b1 = 2;

  auto result1 = divide(a1, b1);

  if (!result1.has_value()) {
    std::cerr << "[Error]: " << result1.error().getErrorMessage() << '\n';
    return 1;
  }

  int abyb = result1.value();
  std::cout << a1 << '/' << b1 << " = " << abyb << '\n';

  auto result2 = divide(a1, 0);
  if (!result2.has_value()) {
    std::cerr << "[Error]: " << result2.error().getErrorMessage() << '\n';
    return 1;
  }

  return 0;
}
