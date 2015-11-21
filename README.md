# HiJoke
A web server writen by cpp

## dependent 
Cppcms  
Cppdb  
boost

## compile and run
compile the views: run the command "./start.sh views"  
compile the projection: run the command "./start.sh compile"  
run the projection: run the command "./start.sh run"

## the iOS client
this projection is a web server, this projection is an iOS client.  
<a href="https://github.com/karldoenitz/HiJokeIOSClient">iOS client</a>

## documentation
uri            | method |                         params                     | response |            summary             |
---------------|--------|----------------------------------------------------|----------|--------------------------------|
/register      |  post  | username:string<br/>password:string                |   json   |                                |
/login         |  post  | username:string<br/>password:string                |   json   |                                |
/logout        |  post  |                                                    |   json   |                                |
/jokes         |  get   | first_index:int<br/>length:int                     |   json   |                                |
/write-joke    |  post  | title:string<br/>content:string                    |   json   | user write joke, need login    |
/get-comment   |  get   | joke_id:int                                        |   json   |                                |
/write-comment |  post  | joke_id:int<br/>usercode:string<br/>comment:string |   json   | user write comment, need login |

