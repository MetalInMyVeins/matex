if(CMAKE_BUILD_TYPE STREQUAL "Release")
  set(LIB_TYPE STATIC)
else()
  set(LIB_TYPE SHARED)
endif()

add_library(libmatex ${LIB_TYPE}
  dummy.cxx
)

set_target_properties(libmatex PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
  LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
  OUTPUT_NAME matex
  POSITION_INDEPENDENT_CODE ON
)

target_include_directories(libmatex PUBLIC
  ${CMAKE_SOURCE_DIR}/include
)

target_compile_options(libmatex PRIVATE
  -Wall
  -Wextra
  -pedantic
  -Wpedantic
  -Werror
  -Wshadow
  -Wconversion
  -Wsign-conversion
  -Wformat=2
  -Wundef
)

target_compile_options(libmatex PRIVATE
  $<$<CONFIG:Release>:
    -O3
    -fvisibility=hidden
    -fomit-frame-pointer
    -fcf-protection=full
    -fstack-clash-protection
    -D_FORTIFY_SOURCE=2
    -DNDEBUG
  >
)

target_link_options(libmatex INTERFACE
  $<$<CONFIG:Release>:
    -flto
    -static-pie
    -Wl,-z,relro,-z,now
  >
)

add_executable(matex main.cxx)

set_target_properties(matex PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

target_link_libraries(matex PRIVATE libmatex)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
  add_custom_command(
    TARGET matex POST_BUILD
    COMMAND /usr/bin/strip "$<TARGET_FILE:matex>"
    COMMENT "Stripping symbols..."
  )
  add_custom_command(
    TARGET matex POST_BUILD
    COMMAND /usr/bin/upx --best "$<TARGET_FILE:matex>"
    COMMENT "Compressing binary..."
  )
endif()

