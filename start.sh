#!/bin/sh

if [ -z "$1" ]; then
    echo "---start compile views---"
    cd Templates
    cppcms_tmpl_cc *.tmpl -o views.cpp
    cd ..
    echo "---compile success---"
    echo "---start compile---"
    c++ main.cpp settings.cpp \
    Utils/Utils.cpp \
    Utils/HttpClient.cpp \
    DatabaseManager/DatabaseOperator.cpp \
    DatabaseManager/joke/bean/Joke.cpp \
    DatabaseManager/joke/manager/JokeManager.cpp \
    DatabaseManager/user/bean/User.cpp \
    DatabaseManager/comment/bean/Comment.cpp \
    DatabaseManager/comment/manager/CommentManager.cpp \
    DatabaseManager/user/manager/UserManager.cpp \
    Application/BaseHandler.cpp \
    Application/login/LoginHandler.cpp \
    Application/logout/LogoutHandler.cpp \
    Application/register/RegisterHandler.cpp \
    Application/joke/JokeHandler.cpp \
    Application/comment/CommentHandler.cpp \
    Application/staticserver/StaticServer.cpp \
    Templates/views.cpp \
    -o main.o -lcppcms -lcppdb -lbooster -lcurl -std=c++11
    echo "---compile success---"
    echo "---run server---"
    ./main.o -c config.json
elif [ $1 = "compile" ]; then
    echo "---start compile---"
    c++ main.cpp settings.cpp \
    Utils/Utils.cpp \
    Utils/HttpClient.cpp \
    DatabaseManager/DatabaseOperator.cpp \
    DatabaseManager/joke/bean/Joke.cpp \
    DatabaseManager/joke/manager/JokeManager.cpp \
    DatabaseManager/user/bean/User.cpp \
    DatabaseManager/comment/bean/Comment.cpp \
    DatabaseManager/comment/manager/CommentManager.cpp \
    DatabaseManager/user/manager/UserManager.cpp \
    Application/BaseHandler.cpp \
    Application/login/LoginHandler.cpp \
    Application/logout/LogoutHandler.cpp \
    Application/register/RegisterHandler.cpp \
    Application/joke/JokeHandler.cpp \
    Application/comment/CommentHandler.cpp \
    Application/staticserver/StaticServer.cpp \
    Templates/views.cpp \
    -o main.o -lcppcms -lcppdb -lbooster -lcurl -std=c++11
    echo "---compile success---"
elif [ $1 = "views" ]; then
    echo "---start compile views---"
    cd Templates
    cppcms_tmpl_cc *.tmpl -o views.cpp
    cd ..
    echo "---compile success---"
elif [ $1 = "run" ]; then
    echo "---run server---"
    ./main.o -c config.json
fi
