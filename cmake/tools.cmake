
if(${PROJECT_NAME}_ENABLE_CLANG_TIDY)
find_program(CLANGTIDY clang-tidy)
if(CLANGTIDY)
  set(CMAKE_CXX_CLANG_TIDY ${CLANGTIDY} -extra-arg=-Wno-unknown-warning-option)
  message("Clang-Tidy finished setting up.")
else()
  message(SEND_ERROR "Clang-Tidy requested but executable not found.")
endif()
endif()

if(${PROJECT_NAME}_ENABLE_CLANG_FORMAT)
file(GLOB_RECURSE ALL_SOURCE_FILES
  ${PROJECT_SOURCE_DIR}/fib/rpc/src/*.hpp
  ${PROJECT_SOURCE_DIR}/fib/rpc/src/*.cpp
  ${PROJECT_SOURCE_DIR}/fib/client/src/*.hpp
  ${PROJECT_SOURCE_DIR}/fib/client/src/*.cpp
  ${PROJECT_SOURCE_DIR}/fib/server/src/*.hpp
  ${PROJECT_SOURCE_DIR}/fib/server/src/*.cpp
  ${PROJECT_SOURCE_DIR}/fib-client/*.hpp
  ${PROJECT_SOURCE_DIR}/fib-client/*.cpp
  ${PROJECT_SOURCE_DIR}/fib-server/*.hpp
  ${PROJECT_SOURCE_DIR}/fib-server/*.cpp
)

find_program(${PROJECT_NAME}_CLANG_FORMAT_BINARY clang-format)

add_custom_target(
  clang-format
  COMMAND ${${PROJECT_NAME}_CLANG_FORMAT_BINARY}
  -i ${ALL_SOURCE_FILES}
)
endif()