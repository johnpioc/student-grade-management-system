cmake_minimum_required(VERSION 3.16)
project(StudentGradeManager)

set(CMAKE_CXX_STANDARD 17)

# Add include directory
include_directories(include)

# Add source files
add_executable(StudentGradeManager
        src/main.cpp
        src/Student.cpp
        src/StudentManager.cpp
        src/Student.cpp
        include/Student.h
        src/StudentManager.cpp
        include/StudentManager.h
)
