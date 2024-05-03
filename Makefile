CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
INCLUDE_DIRS = -I"C:\Uers\Paul\Desktop\management_atelier_auto\lib" -I"lib"

TARGET = main
SOURCES = main.cpp src/Angajati/Angajat.cpp src/Angajati/Asistent.cpp src/Angajati/Director.cpp src/Angajati/Mecanic.cpp src/utile/functions.cpp src/utile/utileAngajati.cpp src/Masini/Masina.cpp src/Masini/Standard.cpp src/Masini/Autobuz.cpp src/Masini/Camion.cpp src/Meniu/Meniu.cpp src/data/files.cpp src/data/pin.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c -o $@ $<

clean:
	del /s *.o $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all run clean
