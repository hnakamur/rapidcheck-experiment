enable_testing()

add_executable(rapidcheck_example rapidcheck_example.cc)
target_link_libraries(rapidcheck_example rapidcheck)
add_test(NAME rapidcheck_example COMMAND rapidcheck_example)

add_executable(rapidcheck_gtest_example rapidcheck_gtest_example.cc)
target_link_libraries(rapidcheck_gtest_example rapidcheck_gtest rapidcheck gtest gtest_main pthread)
add_test(NAME rapidcheck_gtest_example COMMAND rapidcheck_gtest_example)

add_executable(rapidcheck_gmock_example rapidcheck_gmock_example.cc)
target_link_libraries(rapidcheck_gmock_example turtle rapidcheck_gmock rapidcheck gtest gmock gmock_main pthread)
add_test(NAME rapidcheck_gmock_example COMMAND rapidcheck_gmock_example)

add_executable(gtest_example gtest_example.cc)
target_link_libraries(gtest_example pthread gtest gtest_main)
add_test(NAME gtest_example COMMAND gtest_example)

add_executable(gmock_example gmock_example.cc)
target_link_libraries(gmock_example turtle gtest gmock gmock_main pthread)
add_test(NAME gmock_example COMMAND gmock_example)
