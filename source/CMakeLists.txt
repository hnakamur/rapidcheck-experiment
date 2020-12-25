#add_executable(example main.cc)
#target_link_libraries(example RapidCheck::rapidcheck)

add_executable(gtest_example gtest_example.cc)
target_link_libraries(gtest_example pthread gtest gtest_main)
