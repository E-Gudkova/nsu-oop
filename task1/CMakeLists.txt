include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(
        task1
        Trie.cpp
        main.cpp
)

add_executable(task1_tests
        test_trie.cpp
        Trie.cpp
)

target_link_libraries(task1_tests
        PRIVATE
        GTest::gtest_main
)