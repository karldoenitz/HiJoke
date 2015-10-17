cmake_minimum_required(VERSION 3.3)
project(HiJoke)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lcppdb -lcppcms -std=c++11")

set(SOURCE_FILES
        main.cpp
        DatabaseManager
        TestCase
        Utils
        TestCase/test.cpp
        DatabaseManager/joke/bean/Joke.cpp
        DatabaseManager/joke/bean/Joke.h
        DatabaseManager/comment/bean/Comment.cpp
        DatabaseManager/comment/bean/Comment.h
        DatabaseManager/joke/manager/JokeManager.cpp
        DatabaseManager/joke/manager/JokeManager.h
        DatabaseManager/comment/manager/CommentManager.cpp
        DatabaseManager/comment/manager/CommentManager.h
        Application
        Application/register/RegisterHandler.cpp
        Application/register/RegisterHandler.h
        Utils/Utils.cpp
        Utils/Utils.h 
        Application/login/LoginHandler.cpp 
        Application/login/LoginHandler.h 
        Application/logout/LogoutHandler.cpp 
        Application/logout/LogoutHandler.h 
        Application/joke/JokeHandler.cpp
        Application/joke/JokeHandler.h
        Application/comment/CommentHandler.cpp
        Application/comment/CommentHandler.h
        Templates/content.h settings.h settings.cpp)
add_executable(HiJoke ${SOURCE_FILES})