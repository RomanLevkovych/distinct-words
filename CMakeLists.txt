cmake_minimum_required(VERSION 3.14)

project(distinct-words LANGUAGES CXX)

add_executable(distinct_words
    main.cc
    reader.cc
    words_counter.cc
)

target_compile_features(distinct_words PRIVATE cxx_std_17)