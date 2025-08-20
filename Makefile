# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -std=c++17 -g

# Source files
SRCS = AccessPoint.cpp main.cpp User.cpp Wifi4Simulator.cpp Wifi5Simulator.cpp Wifi6Simulator.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)
# Executable name
TARGET = wifi_simulation

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the simulation
run: all
	./$(TARGET)

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean run