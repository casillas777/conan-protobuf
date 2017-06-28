project(PackageTest CXX)
cmake_minimum_required(VERSION 2.8.12)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

execute_process(
    COMMAND ${CONAN_BIN_DIRS_PROTOBUF}/protoc -I${CMAKE_CURRENT_SOURCE_DIR}/protobuf ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/test.proto --cpp_out=${CMAKE_CURRENT_SOURCE_DIR}/protobuf
    ERROR_VARIABLE protoc_error
)

if (protoc_error)
    message(FATAL_ERROR ${protoc_error})
endif(protoc_error)

add_executable(example example.cpp ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/test.pb.cc)
target_include_directories(example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/protobuf)
target_link_libraries(example ${CONAN_LIBS})

# CTest is a testing tool that can be used to test your project.
# enable_testing()
# add_test(NAME example
#          WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
#          COMMAND example)
