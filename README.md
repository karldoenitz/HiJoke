# HiJoke
A web server writen by cpp

## dependent 
Cppcms  
Cppdb  
boost

## compile and run
compile the projection: run the command "./start.sh compile"  
run the projection: run the command "./start.sh run"

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

