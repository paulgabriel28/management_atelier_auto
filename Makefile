CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

TARGET = main
SOURCES = main.cpp src/Angajati/Angajat.cpp src/Angajati/Asistent.cpp src/Angajati/Director.cpp src/Angajati/Mecanic.cpp src/utile/functions.cpp src/utile/utileAngajati.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all run