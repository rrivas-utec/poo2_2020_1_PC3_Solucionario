cmake_minimum_required(VERSION 3.16)
project(poo2_2020_1_PC3_Solucionario)

set(CMAKE_CXX_STANDARD 17)

add_executable(poo2_2020_1_PC3
        main.cpp
        P1.cpp P1.h
        P2.cpp P2.h
        P3.cpp P3.h
        P4.cpp P4.h "heap.h")