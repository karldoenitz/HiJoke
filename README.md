# HiJoke
A web server writen by cpp

## dependent 
Cppcms  
Cppdb  
libcurl  
boost

## compile and run
compile the views: run the command "./start.sh views"  
compile the projection: run the command "./start.sh compile"  
run the projection: run the command "./start.sh run"

### build and debug in docker
Use `steeze/cppcms:latest` to build this project.  
First, run `docker pull steeze/cppcms:latest` to download the image.  
Then run `docker run -itd --name {container-name} -v {host path}:{container path} -p 20022:22 -p 28888:8888  -d steeze/cppcms:latest` to create a container.  
Use `Clion Remote Debug` to build and debug this project in docker.  


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

