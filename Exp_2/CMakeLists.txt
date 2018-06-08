cmake_minimum_required(VERSION 3.5)

project(Exp_2)

set(SOURCE_FILES 
	ProcessDispatch.cpp
	Dispatch.h
	ProcessInfo.cpp
	ProcessInfo.h
	main.cpp
        )

add_executable(program ${SOURCE_FILES})
