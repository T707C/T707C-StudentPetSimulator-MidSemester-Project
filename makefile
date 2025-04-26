CXX = g++
CXXFLAGS = -std=c++17 -lstdc++fs
SOURCES = main.cpp DataManager.cpp Pet.cpp Task.cpp TaskManager.cpp
TARGET = taskpet

all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)