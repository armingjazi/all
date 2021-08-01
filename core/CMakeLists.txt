add_library(all_core source/SumGene.cpp)

target_include_directories(all_core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)