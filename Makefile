CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -Iinclude

SRC = src/Kendaraan.cpp src/Motor.cpp src/Mobil.cpp src/Truk.cpp \
      src/Exception.cpp src/SlotParkir.cpp src/Tiket.cpp src/Struk.cpp \
      src/TanpaDiskon.cpp src/DiskonMember.cpp src/HitungDurasi.cpp \
      src/GedungParkir.cpp

.PHONY: all clean run test_bagian1 test_bagian2 test_bagian3

all: parkir_pintar

parkir_pintar: $(SRC) main.cpp
	$(CXX) $(CXXFLAGS) $(SRC) main.cpp -o parkir_pintar

run: parkir_pintar
	./parkir_pintar

test_bagian1:
	$(CXX) $(CXXFLAGS) src/Kendaraan.cpp src/Motor.cpp src/Mobil.cpp src/Truk.cpp \
		src/Exception.cpp test_bagian1.cpp -o test_bagian1
	./test_bagian1

test_bagian2:
	$(CXX) $(CXXFLAGS) src/Kendaraan.cpp src/Motor.cpp src/Mobil.cpp src/Truk.cpp \
		src/SlotParkir.cpp src/Tiket.cpp src/Struk.cpp test_bagian2.cpp -o test_bagian2
	./test_bagian2

test_bagian3:
	$(CXX) $(CXXFLAGS) src/Kendaraan.cpp src/Motor.cpp src/Mobil.cpp src/Truk.cpp \
		src/TanpaDiskon.cpp src/DiskonMember.cpp src/HitungDurasi.cpp test_bagian3.cpp -o test_bagian3
	./test_bagian3

clean:
	rm -f parkir_pintar parkir_pintar.exe test_bagian1 test_bagian1.exe test_bagian2 test_bagian2.exe test_bagian3 test_bagian3.exe
