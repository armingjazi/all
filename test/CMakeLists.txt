add_executable(run_tests main.cpp)

target_link_libraries(run_tests all_core)

target_include_directories(run_tests PUBLIC .)
