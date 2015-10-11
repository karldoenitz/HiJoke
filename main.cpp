#include <iostream>
#include "Application/register/RegisterHandler.h"
#include "Application/login/LoginHandler.h"
#include "Application/logout/LogoutHandler.h"
#include "Application/joke/JokeHandler.h"

using namespace std;

int main(int argc,char ** argv) {
    try {
        cppcms::service app(argc,argv);
        app.applications_pool().mount(
                cppcms::applications_factory<RegisterHandler>(),
                cppcms::mount_point("/register")
        );
        app.applications_pool().mount(
                cppcms::applications_factory<LoginHandler>(),
                cppcms::mount_point("/login")
        );
        app.applications_pool().mount(
                cppcms::applications_factory<LogoutHandler>(),
                cppcms::mount_point("/logout")
        );
        app.applications_pool().mount(
                cppcms::applications_factory<JokeHandler>(),
                cppcms::mount_point("/jokes")
        );
        app.applications_pool().mount(
                cppcms::applications_factory<WriteJokeHandler>(),
                cppcms::mount_point("/write-joke")
        );
        app.run();
    }
    catch (std::exception const &e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}