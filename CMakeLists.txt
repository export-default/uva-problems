cmake_minimum_required(VERSION 2.8.4)
project(uva_problems)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

enable_testing()

set(PROBLEMS 1585 12545 1586 946 12662 10942 10055 10071 272 458 102 11172 494 113 108 146 111 10405 674 10066
10192 10003 116 10038)
set(NO_INPUT_PROBLEMS 136)

file(COPY test.sh DESTINATION ./)
foreach(PROBLEM ${PROBLEMS})
    add_executable(${PROBLEM} src/${PROBLEM}.cpp)
    file(COPY test/${PROBLEM}.in test/${PROBLEM}.out DESTINATION ./)
    add_test(${PROBLEM}.test bash test.sh ${PROBLEM})
endforeach()

foreach(PROBLEM ${NO_INPUT_PROBLEMS})
    add_executable(${PROBLEM} src/${PROBLEM}.cpp)
endforeach()
