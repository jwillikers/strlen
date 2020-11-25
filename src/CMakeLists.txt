include(GenerateExportHeader)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS no)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

add_library(strlen)
add_library(strlen::strlen ALIAS strlen)
generate_export_header(strlen EXPORT_FILE_NAME
                       ${STRLEN_GENERATED_INCLUDEDIR}/strlen/export.h)
target_include_directories(
  strlen
  INTERFACE $<BUILD_INTERFACE:${STRLEN_GENERATED_INCLUDEDIR}>
  PRIVATE ${STRLEN_GENERATED_INCLUDEDIR})
target_sources(strlen PRIVATE strlen.c)
target_compile_options(
  strlen
  PRIVATE $<$<CXX_COMPILER_ID:Clang>:-Werror>
          $<$<CXX_COMPILER_ID:Clang>:-Weverything>
          $<$<CXX_COMPILER_ID:GNU>:-Werror>
          $<$<CXX_COMPILER_ID:GNU>:-Wall>
          $<$<CXX_COMPILER_ID:MSVC>:/WX>
          $<$<CXX_COMPILER_ID:MSVC>:/W3>)

if(TEST_STRLEN OR CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
  add_executable(strlen-test)
  target_sources(strlen-test PRIVATE strlen.test.cpp)
  target_link_libraries(strlen-test PRIVATE strlen::strlen boost::ut)
  target_compile_options(
    strlen-test
    INTERFACE $<$<CXX_COMPILER_ID:Clang>:-Werror>
              $<$<CXX_COMPILER_ID:Clang>:-Weverything>
              $<$<CXX_COMPILER_ID:Clang>:-Wno-c++98-compat>
              $<$<CXX_COMPILER_ID:Clang>:-Wno-c++98-compat-pedantic>
              $<$<CXX_COMPILER_ID:Clang>:-Wno-c99-extensions>
              $<$<CXX_COMPILER_ID:Clang>:-Wno-comma>
              $<$<CXX_COMPILER_ID:Clang>:-Wno-newline-eof>
              $<$<CXX_COMPILER_ID:GNU>:-Werror>
              $<$<CXX_COMPILER_ID:GNU>:-Wall>
              $<$<CXX_COMPILER_ID:MSVC>:/WX>
              $<$<CXX_COMPILER_ID:MSVC>:/W3>)
  add_test(NAME strlen-test COMMAND strlen-test)
  set_tests_properties(strlen-test PROPERTIES LABELS "strlen")
endif()
