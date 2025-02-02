 #!/bin/bash

# Set the source file and output binary
SOURCE="example.cpp"
OUTPUT="example"

# Compilation flags
CXXFLAGS="-std=c++2b -Wall -Wextra -O2"

# Compile the C++ program
g++ $CXXFLAGS $SOURCE -o $OUTPUT

# Check if compilation succeeded
if [ $? -eq 0 ]; then
    echo "✅ Compilation successful! Run ./$OUTPUT"
else
    echo "❌ Compilation failed!"
    exit 1
fi

