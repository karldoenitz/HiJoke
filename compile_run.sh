#!/bin/sh

echo "---start compile---"
c++ main.cpp Utils/Utils.cpp DatabaseManager/DatabaseOperator.cpp DatabaseManager/joke/bean/Joke.cpp DatabaseManager/joke/manager/JokeManager.cpp DatabaseManager/user/bean/User.cpp DatabaseManager/comment/bean/Comment.cpp DatabaseManager/comment/manager/CommentManager.cpp DatabaseManager/user/manager/UserManager.cpp Application/login/LoginHandler.cpp Application/logout/LogoutHandler.cpp Application/register/RegisterHandler.cpp Application/joke/JokeHandler.cpp Application/comment/CommentHandler.cpp -o main.o -lcppcms -lcppdb -std=c++11
echo "---compile success---"
echo "---run server---"
./main.o -c config.js
