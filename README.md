# Arduino from Scratch
## By Florian "FloRide" Reimat

## How to compile
```sh
# Setup Project
cmake -S . -B build/

# Compile Project
cmake --build build/

# Flash
cmake --build build/ -- flash

# Flash + Compile
cmake --build build/ -- all flash
```

## Boards
- [ ] Arduino Uno
- [ ] Arduino Mega

## Links
- [CMake blog for AVR](https://nnarain.github.io/2016/03/29/AVR-CMake-Toolchain.html)
- [CMake github example](https://github.com/nnarain/cmake-avr-toolchain)
- [USART on ATMEGA328P](https://www.xanthium.in/how-to-avr-atmega328p-microcontroller-usart-uart-embedded-programming-avrgcc)
