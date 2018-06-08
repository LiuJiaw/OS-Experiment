cmake_minimum_required(VERSION 3.5)
project(Exp_5)

set(SOURCE_FILES main.cpp
        Algorithm.cpp
	Algorithm.h
	File.cpp
	File.h
        )
add_executable(program ${SOURCE_FILES})
