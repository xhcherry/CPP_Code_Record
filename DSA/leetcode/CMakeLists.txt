cmake_minimum_required(VERSION 3.25)
project(leetcode)

set(CMAKE_CXX_STANDARD 17)

file (GLOB_RECURSE files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ ${file}\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()