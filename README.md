# HiJoke
A web server writen by cpp

## dependent 
Cppcms  
Cppdb;

## compile and run
compile the projection: run the command "./start.sh compile"  
run the projection: run the command "./start.sh run"

## documentation
uri            | method |                         params                      |            summary
---------------|--------|-----------------------------------------------------|-------------------------------
/register      |  post  | username:string<br/>password:string                 |
/login         |  post  | username:string<br/>password:string                 |
/logout        |  post  |                                                     |
/jokes         |  get   | first_index:int<br/>length:int                      |
/write-joke    |  post  | title:string<br/>content:string                     | user write joke, need login
/get-comment   |  get   | joke_id:int                                         |
/write-comment |  post  | joke_id:int<br/>usercode:string<br/>comment:string  | user write comment, need login

