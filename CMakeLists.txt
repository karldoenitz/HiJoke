cmake_minimum_required(VERSION 3.3)
project(HiJoke)

#include_directories(SYSTEM /usr/local/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lcppcms -lcppdb -lbooster -lcurl")

link_directories(/usr/local/lib)

set(SOURCE_FILES
        Application/comment/CommentHandler.cpp
        Application/comment/CommentHandler.h
        Application/joke/JokeHandler.cpp
        Application/joke/JokeHandler.h
        Application/login/LoginHandler.cpp
        Application/login/LoginHandler.h
        Application/logout/LogoutHandler.cpp
        Application/logout/LogoutHandler.h
        Application/register/RegisterHandler.cpp
        Application/register/RegisterHandler.h
        Application/staticserver/StaticServer.cpp
        Application/staticserver/StaticServer.h
        Application/BaseHandler.cpp
        Application/BaseHandler.h
        DatabaseManager/comment/bean/Comment.cpp
        DatabaseManager/comment/bean/Comment.h
        DatabaseManager/comment/manager/CommentManager.cpp
        DatabaseManager/comment/manager/CommentManager.h
        DatabaseManager/joke/bean/Joke.cpp
        DatabaseManager/joke/bean/Joke.h
        DatabaseManager/joke/manager/JokeManager.cpp
        DatabaseManager/joke/manager/JokeManager.h
        DatabaseManager/user/bean/User.cpp
        DatabaseManager/user/bean/User.h
        DatabaseManager/user/manager/UserManager.cpp
        DatabaseManager/user/manager/UserManager.h
        DatabaseManager/DatabaseOperator.cpp
        DatabaseManager/DatabaseOperator.h
        Templates/content.h
        Templates/views.cpp
        #    TestCase/test.cpp
        Utils/Utils.cpp
        Utils/Utils.h
        main.cpp
        settings.cpp
        settings.h
        Utils/HttpClient.cpp
        Utils/HttpClient.h)

add_executable(HiJoke ${SOURCE_FILES})
target_link_libraries(HiJoke curl cppcms cppdb booster)