add_executable(example main.cc)
target_link_libraries(example rapidcheck)

add_executable(rapidcheck_gtest_example rapidcheck_gtest_example.cc)
target_link_libraries(rapidcheck_gtest_example rapidcheck_gtest rapidcheck gtest gtest_main pthread)

add_executable(gtest_example gtest_example.cc)
target_link_libraries(gtest_example pthread gtest gtest_main)

add_executable(gmock_example gmock_example.cc)
target_link_libraries(gmock_example pthread gtest gmock gmock_main)
