cmake_minimum_required(VERSION 3.14)

project(distinct-words LANGUAGES CXX)

add_executable(distinct_words
    src/main.cc
    src/reader.cc
    src/words_counter.cc
    src/thread_safe_string_queue.cc
)

target_include_directories(distinct_words
    PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(distinct_words PRIVATE cxx_std_17)
target_compile_options(distinct_words PRIVATE -Wall -Wextra)