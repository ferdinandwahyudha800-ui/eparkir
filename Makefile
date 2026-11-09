# Makefile untuk Bagian 1 - Kelas Kendaraan

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Object files
OBJS = Kendaraan.o Motor.o Mobil.o Truk.o Exception.o

# Target utama
all: test_bagian1

# Compile test program
test_bagian1: $(OBJS) test_bagian1.o
	$(CXX) $(CXXFLAGS) -o test_bagian1 $(OBJS) test_bagian1.o

# Compile object files
Kendaraan.o: Kendaraan.cpp Kendaraan.h
	$(CXX) $(CXXFLAGS) -c Kendaraan.cpp

Motor.o: Motor.cpp Motor.h Kendaraan.h
	$(CXX) $(CXXFLAGS) -c Motor.cpp

Mobil.o: Mobil.cpp Mobil.h Kendaraan.h
	$(CXX) $(CXXFLAGS) -c Mobil.cpp

Truk.o: Truk.cpp Truk.h Kendaraan.h
	$(CXX) $(CXXFLAGS) -c Truk.cpp

Exception.o: Exception.cpp Exception.h
	$(CXX) $(CXXFLAGS) -c Exception.cpp

test_bagian1.o: test_bagian1.cpp Motor.h Mobil.h Truk.h Exception.h
	$(CXX) $(CXXFLAGS) -c test_bagian1.cpp

# Clean
clean:
	rm -f *.o test_bagian1 test_bagian1.exe

# Run test
test: test_bagian1
	./test_bagian1
