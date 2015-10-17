#include <iostream>
#include "Application/register/RegisterHandler.h"
#include "Application/login/LoginHandler.h"
#include "Application/logout/LogoutHandler.h"
#include "Application/joke/JokeHandler.h"
#include "Application/comment/CommentHandler.h"

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
        app.applications_pool().mount(
                cppcms::applications_factory<CommentHandler>(),
                cppcms::mount_point("/get-comment")
        );
        app.applications_pool().mount(
                cppcms::applications_factory<WriteCommentHandler>(),
                cppcms::mount_point("/write-comment")
        );
        app.applications_pool().mount(
                cppcms::applications_factory<AdminLoginHandler>(),
                cppcms::mount_point("/admin-login")
        );
        app.applications_pool().mount(
                cppcms::applications_factory<AdminLoginView>(),
                cppcms::mount_point("/admin-login-view")
        );
        app.applications_pool().mount(
                cppcms::applications_factory<AdminView>(),
                cppcms::mount_point("/admin-index")
        );
        app.run();
    }
    catch (std::exception const &e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}