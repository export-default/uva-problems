cmake_minimum_required(VERSION 2.8.4)
project(uva_problems)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

enable_testing()

set(PROBLEMS 1585 12545 1586 946)

file(COPY test.sh DESTINATION ./)
foreach(PROBLEM ${PROBLEMS})
    add_executable(${PROBLEM} src/${PROBLEM}.cpp)
    file(COPY test/${PROBLEM}.in test/${PROBLEM}.out DESTINATION ./)
    add_test(${PROBLEM}.test bash test.sh ${PROBLEM})
endforeach()