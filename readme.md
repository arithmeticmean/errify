# Errify - A Header-Only Error Handling Library for C++  

**Errify** is a lightweight, **header-only** error-handling library for C++. It provides a simple and efficient way to manage errors without exceptions, focusing on **type safety**, **performance**, and **readability**.  


---

## 🚀 Features  

✅ **Header-only**: Just include and use—no linking required.  
✅ **No exceptions**: Designed for environments where exceptions are not preferred.  
✅ **Lightweight**: Minimal overhead for high-performance applications.  
✅ **Type-safe error handling**: Uses `std::expected` or custom error types.  
✅ **Compatible**: Works with C++23 and later.  

---

## 📦 Installation  

Simply **copy** the `errify.hpp` file into your project and include it:  

```cpp
#include "errify.hpp"
```


## 🔧 API Overview
```cpp

BaseError           // A interface class to define custom error

Error               // Stores any type which extends BaseError
.hasError           // check if error is valid returns bool
.getErrorMessage    // returns error message as const char*

```

## 🛠 Requirements
C++23 or later 

A standard-compliant C++ compiler (GCC, Clang, MSVC).

## 📜 License
This project is licensed under the MIT License—feel free to use, modify, and distribute it!

## 🤝 Contributing
Contributions are welcome! Feel free to submit pull requests, report issues, or suggest improvements.
