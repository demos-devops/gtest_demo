cmake_minimum_required(VERSION 3.0)


include(ExternalProject)
# 下载、构建和安装 Google Test
ExternalProject_Add(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
    PREFIX ${CMAKE_BINARY_DIR}/googletest
    INSTALL_DIR ${CMAKE_BINARY_DIR}/googletest
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>

    #PREFIX ${CMAKE_BINARY_DIR}/googletest
    #GIT_REPOSITORY https://github.com/google/googletest.git
    #GIT_TAG main  # 使用 master 分支的最新代码
    #CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
)
# 将 Google Test 导入到当前 CMake 项目中
ExternalProject_Get_Property(googletest source_dir binary_dir)
include_directories(${source_dir}/googletest/include)
include_directories(${source_dir}/googlemock/include)
link_directories(${binary_dir}/lib)


enable_testing()
add_executable(tests test.cpp)
target_link_libraries(tests gtest gtest_main gmock gmock_main pthread )
include(GoogleTest)
gtest_discover_tests(tests)
