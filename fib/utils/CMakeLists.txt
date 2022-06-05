set(sources
    src/program_options.cpp)

set(headers
    src/program_options.hpp
    src/logger.hpp)

add_library(utils ${headers} ${sources})
add_library(${PROJECT_NAME}::utils ALIAS utils)

find_package(Boost REQUIRED)
find_package(spdlog REQUIRED)

target_link_libraries(utils PUBLIC Boost::program_options spdlog::spdlog)
target_compile_features(utils PUBLIC cxx_std_17)
target_include_directories(utils INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)