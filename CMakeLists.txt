cmake_minimum_required(VERSION 3.3)
project(HiJoke)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DatabaseManager TestCase Utils TestCase/test.cpp DatabaseManager/joke/bean/Joke.cpp DatabaseManager/joke/bean/Joke.h DatabaseManager/comment/bean/Comment.cpp DatabaseManager/comment/bean/Comment.h DatabaseManager/joke/manager/JokeManager.cpp DatabaseManager/joke/manager/JokeManager.h DatabaseManager/comment/manager/CommentManager.cpp DatabaseManager/comment/manager/CommentManager.h)
add_executable(HiJoke ${SOURCE_FILES})