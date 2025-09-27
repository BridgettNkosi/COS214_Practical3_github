CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude

SRC = src/ChatRoom.cpp src/User.cpp src/Command.cpp src/Iterator.cpp src/TestingMain.cpp
OBJS = $(SRC:.cpp=.o)
TARGET = testing_main
DEMO = demo_main

all: run

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

run: $(TARGET)
	./$(TARGET)

demo: src/ChatRoom.o src/User.o src/Command.o src/Iterator.o src/DemoMain.o
	$(CXX) $(CXXFLAGS) -o $(DEMO) src/ChatRoom.o src/User.o src/Command.o src/Iterator.o src/DemoMain.o
	./$(DEMO)

clean:
	rm -f src/*.o $(TARGET) $(DEMO) *.gcda *.gcno *.gcov

coverage: CXXFLAGS += -fprofile-arcs -ftest-coverage
coverage: clean $(TARGET)
	./$(TARGET) || true
	gcov -b -c src/TestingMain.cpp || true
