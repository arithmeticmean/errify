#ifndef ERRIFY_HPP_
#define ERRIFY_HPP_

#include <exception>
#include <memory>
#include <string>

namespace Errify {

// BaseError class extending std::exception from <exception>
class BaseError : public std::exception {
private:
  std::string errorMessage;

public:
  virtual ~BaseError() {};

protected:
  explicit BaseError(const std::string &message) : errorMessage(message) {}
  const char *what() const noexcept override { return errorMessage.c_str(); }

  friend class Error;
};

class Error {
private:
  // using unique_ptr for polymorphism
  std::shared_ptr<BaseError> errorInstance;

public:
  // Constructor to initialize with a derived class of BaseError
  template <typename T>
  explicit Error(T args)
      : errorInstance(std::make_shared<BaseError>(std::move(args))) {
    static_assert(std::is_base_of_v<BaseError, T>,
                  "T must be derived from BaseError");
  }

  // Check if the error is valid
  bool hasError() const { return errorInstance != nullptr; }

  // Get the error message
  std::string getErrorMessage() const {
    return errorInstance ? errorInstance->what() : "Undefined Error";
  }
};
} // namespace Errify

#endif
