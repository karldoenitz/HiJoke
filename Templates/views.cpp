#line 1 "login.tmpl"
#include "content.h" 
#line 2 "login.tmpl"
namespace my_skin {
	#line 3 "login.tmpl"
	struct message :public cppcms::base_view
	#line 3 "login.tmpl"
	{
	#line 3 "login.tmpl"
		content::message &content;
	#line 3 "login.tmpl"
		message(std::ostream &_s,content::message &_content): cppcms::base_view(_s),content(_content)
	#line 3 "login.tmpl"
		{
	#line 3 "login.tmpl"
		}
		#line 4 "login.tmpl"
		virtual void render() {
			#line 10 "login.tmpl"
			out()<<"\n"
				"<!DOCTYPE html>\n"
				"<html lang=\"en\">\n"
				"<head>\n"
				"    <meta charset=\"UTF-8\">\n"
				"    <title>登录－后台管理系统</title>\n"
				"    <link href=\"";
			#line 10 "login.tmpl"
			out()<<cppcms::filters::escape(content.static_host);
			#line 11 "login.tmpl"
			out()<<"static/css/bootstrap.css\" rel=\"stylesheet\"/>\n"
				"    <link href=\"";
			#line 11 "login.tmpl"
			out()<<cppcms::filters::escape(content.static_host);
			#line 12 "login.tmpl"
			out()<<"static/app-css/app-css.css\" rel=\"stylesheet\"/>\n"
				"    <link href=\"";
			#line 12 "login.tmpl"
			out()<<cppcms::filters::escape(content.static_host);
			#line 13 "login.tmpl"
			out()<<"static/css/bootstrap-theme.css\" rel=\"stylesheet\"/>\n"
				"    <script src=\"";
			#line 13 "login.tmpl"
			out()<<cppcms::filters::escape(content.static_host);
			#line 14 "login.tmpl"
			out()<<"static/js/jquery-1.11.3.min.js\" type=\"text/javascript\"></script>\n"
				"    <script src=\"";
			#line 14 "login.tmpl"
			out()<<cppcms::filters::escape(content.static_host);
			#line 15 "login.tmpl"
			out()<<"static/js/bootstrap.js\" type=\"text/javascript\"></script>\n"
				"    <script src=\"";
			#line 15 "login.tmpl"
			out()<<cppcms::filters::escape(content.static_host);
			#line 62 "login.tmpl"
			out()<<"static/app-js/login.js\" type=\"text/javascript\"></script>\n"
				"</head>\n"
				"<body>\n"
				"<div role=\"main\" class=\"main\">\n"
				"    <div class=\"navbar navbar-default\" id=\"top\" role=\"banner\">\n"
				"        <div class=\"container\">\n"
				"            <div class=\"navbar-header\">\n"
				"                <div class=\"navbar-brand\">\n"
				"                    <span class=\"text-left\">HiJoke后台管理系统</span>\n"
				"                </div>\n"
				"            </div>\n"
				"            <div class=\"collapse navbar-collapse\" role=\"navigation\" id=\"id_navbar_menu\">\n"
				"            </div>\n"
				"        </div>\n"
				"    </div>\n"
				"    <div class=\"container\">\n"
				"        <div class=\"login\">\n"
				"            <div class=\"panel panel-default\">\n"
				"                <div class=\"panel-heading center\"><h4 class=\"text-center text-success\">管理员登录</h4></div>\n"
				"                <div class=\"panel-body center\">\n"
				"                    <div role=\"form\" class=\"form-horizontal\" id=\"id_login_form\">\n"
				"                        <div class=\"form-group \">\n"
				"                            <label for=\"id_email\" class=\"col-sm-2 control-label\">邮箱</label>\n"
				"                            <div class=\"col-sm-10\">\n"
				"                                <input class=\"form-control\" id=\"id_email\" maxlength=\"128\" name=\"email\" placeholder=\"邮件地址\" type=\"text\">\n"
				"                            </div>\n"
				"                        </div>\n"
				"                        <div class=\"form-group \">\n"
				"                            <label for=\"id_password\" class=\"col-sm-2 control-label\">密码</label>\n"
				"                            <div class=\"col-sm-10\">\n"
				"                                <input class=\"form-control\" id=\"id_password\" maxlength=\"30\" name=\"password\" placeholder=\"密码\" type=\"password\">\n"
				"                            </div>\n"
				"                        </div>\n"
				"                        <div class=\"form-group\">\n"
				"                            <div class=\"col-sm-12\">\n"
				"                                <input type=\"submit\" class=\"btn btn-primary btn-lg btn-block\" id=\"Submit\" value=\"登录\"/>\n"
				"                            </div>\n"
				"                        </div>\n"
				"                    </div>\n"
				"                </div>\n"
				"                <div class=\"panel-footer center\"><h6 class=\"text-center text-primary\">made by Karl</h6></div>\n"
				"            </div>\n"
				"        </div>\n"
				"    </div>\n"
				"</div>\n"
				"</body>\n"
				"</html>\n"
				"";
		#line 62 "login.tmpl"
		} // end of template render
	#line 63 "login.tmpl"
	}; // end of class message
#line 64 "login.tmpl"
} // end of namespace my_skin
#line 1 "index.tmpl"
#include "content.h" 
#line 2 "index.tmpl"
namespace my_skin {
	#line 3 "index.tmpl"
	struct index :public cppcms::base_view
	#line 3 "index.tmpl"
	{
	#line 3 "index.tmpl"
		content::index &content;
	#line 3 "index.tmpl"
		index(std::ostream &_s,content::index &_content): cppcms::base_view(_s),content(_content)
	#line 3 "index.tmpl"
		{
	#line 3 "index.tmpl"
		}
		#line 4 "index.tmpl"
		virtual void render() {
			#line 10 "index.tmpl"
			out()<<"\n"
				"<!DOCTYPE html>\n"
				"<html lang=\"en\">\n"
				"<head>\n"
				"    <meta charset=\"UTF-8\">\n"
				"    <title>主页－后台管理系统</title>\n"
				"    <link href=\"";
			#line 10 "index.tmpl"
			out()<<cppcms::filters::escape(content.static_host);
			#line 11 "index.tmpl"
			out()<<"static/css/bootstrap.css\" rel=\"stylesheet\"/>\n"
				"    <link href=\"";
			#line 11 "index.tmpl"
			out()<<cppcms::filters::escape(content.static_host);
			#line 12 "index.tmpl"
			out()<<"static/app-css/app-css.css\" rel=\"stylesheet\"/>\n"
				"    <link href=\"";
			#line 12 "index.tmpl"
			out()<<cppcms::filters::escape(content.static_host);
			#line 13 "index.tmpl"
			out()<<"static/css/bootstrap-theme.css\" rel=\"stylesheet\"/>\n"
				"    <script src=\"";
			#line 13 "index.tmpl"
			out()<<cppcms::filters::escape(content.static_host);
			#line 14 "index.tmpl"
			out()<<"static/js/jquery-1.11.3.min.js\" type=\"text/javascript\"></script>\n"
				"    <script src=\"";
			#line 14 "index.tmpl"
			out()<<cppcms::filters::escape(content.static_host);
			#line 15 "index.tmpl"
			out()<<"static/js/bootstrap.js\" type=\"text/javascript\"></script>\n"
				"    <script src=\"";
			#line 15 "index.tmpl"
			out()<<cppcms::filters::escape(content.static_host);
			#line 16 "index.tmpl"
			out()<<"static/app-js/login.js\" type=\"text/javascript\"></script>\n"
				"    <script src=\"";
			#line 16 "index.tmpl"
			out()<<cppcms::filters::escape(content.static_host);
			#line 97 "index.tmpl"
			out()<<"static/app-js/function.js\" type=\"text/javascript\"></script>\n"
				"</head>\n"
				"<body>\n"
				"<div role=\"main\" class=\"main\">\n"
				"    <div class=\"navbar navbar-default\" id=\"top\" role=\"banner\">\n"
				"        <div class=\"container\">\n"
				"            <div class=\"navbar-header\">\n"
				"                <div class=\"navbar-brand\">\n"
				"                    <span class=\"text-left\">HiJoke后台管理系统</span>\n"
				"                </div>\n"
				"            </div>\n"
				"            <div class=\"collapse navbar-collapse\" role=\"navigation\">\n"
				"                <div class=\"collapse navbar-collapse\">\n"
				"                    <ul class=\"nav navbar-nav navbar-left\">\n"
				"                        <li class=\"\">\n"
				"                            <a href=\"#\" class=\"dropdown-toggle\" data-toggle=\"dropdown\" data-hover=\"dropdown\" aria-expanded=\"false\">\n"
				"                                用户管理<span class=\"caret\"></span>\n"
				"                            </a>\n"
				"                            <ul class=\"dropdown-menu\" role=\"menu\">\n"
				"                                <li><a href=\"#\" onclick=\"\">有效用户</a></li>\n"
				"                                <li><a href=\"#\" onclick=\"\">禁用用户</a></li>\n"
				"                            </ul>\n"
				"                        </li>\n"
				"\n"
				"                        <li class=\"\">\n"
				"                            <a href=\"#\" class=\"dropdown-toggle\" data-toggle=\"dropdown\" data-hover=\"dropdown\">\n"
				"                                笑话管理<span class=\"caret\"></span>\n"
				"                            </a>\n"
				"                            <ul class=\"dropdown-menu\" role=\"menu\">\n"
				"                                <li><a href=\"#\" onclick=\"\">已通过审核笑话</a></li>\n"
				"                                <li><a href=\"#\" onclick=\"\">未通过审核笑话</a></li>\n"
				"                            </ul>\n"
				"                        </li>\n"
				"\n"
				"                    </ul>\n"
				"                    <ul class=\"nav navbar-nav navbar-right\">\n"
				"                        <li class=\"dropdown\">\n"
				"                            <a href=\"#\" class=\"dropdown-toggle\" data-toggle=\"dropdown\" data-hover=\"dropdown\" aria-expanded=\"false\">\n"
				"                                admin\n"
				"                            </a>\n"
				"                            <ul class=\"dropdown-menu\" role=\"menu\">\n"
				"                                <li><a href=\"#\" id=\"admin-logout\">退出</a></li>\n"
				"                            </ul>\n"
				"                        </li>\n"
				"                    </ul>\n"
				"                </div>\n"
				"            </div>\n"
				"        </div>\n"
				"    </div>\n"
				"    <div class=\"container\">\n"
				"        <table id=\"show_result\" class=\"table table-striped table-hover\">\n"
				"            <thead id=\"result_head\">\n"
				"            <tr>\n"
				"                <th>1</th>\n"
				"                <th>2</th>\n"
				"                <th>3</th>\n"
				"                <th>4</th>\n"
				"            </tr>\n"
				"            </thead>\n"
				"            <tbody id=\"result_body\">\n"
				"            <tr>\n"
				"                <td>2</td>\n"
				"                <td>3</td>\n"
				"                <td>4</td>\n"
				"                <td>5</td>\n"
				"            </tr>\n"
				"            </tbody>\n"
				"        </table>\n"
				"        <div style=\"margin-left:auto;margin-right:auto;text-align:center;\">\n"
				"            <ul class=\"pagination\">\n"
				"                <li id=\"first_page\"><a href=\"/admin/monitor/system/page1/\" class=\"active\">第一页</a></li>\n"
				"                <li id=\"pre_page\" class=\"disabled\"><a href=\"javascript:void(0);\">上一页</a></li>\n"
				"                <li id=\"current_page\"><a href=\"#\">第1页</a></li>\n"
				"                <li id=\"next_page\"><a href=\"/admin/monitor/system/page2/\">下一页</a></li>\n"
				"                <li id=\"last_page\"><a href=\"/admin/monitor/system/page13/\">最后一页</a></li>\n"
				"            </ul>\n"
				"        </div>\n"
				"    </div>\n"
				"</div>\n"
				"</body>\n"
				"</html>\n"
				"";
		#line 97 "index.tmpl"
		} // end of template render
	#line 98 "index.tmpl"
	}; // end of class index
#line 99 "index.tmpl"
} // end of namespace my_skin
#line 100 "index.tmpl"
namespace {
#line 100 "index.tmpl"
 cppcms::views::generator my_generator; 
#line 100 "index.tmpl"
 struct loader { 
#line 100 "index.tmpl"
  loader() { 
#line 100 "index.tmpl"
   my_generator.name("my_skin");
#line 100 "index.tmpl"
   my_generator.add_view<my_skin::message,content::message>("message",true);
#line 100 "index.tmpl"
   my_generator.add_view<my_skin::index,content::index>("index",true);
#line 100 "index.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 100 "index.tmpl"
 }
#line 100 "index.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 100 "index.tmpl"
} a_loader;
#line 100 "index.tmpl"
} // anon 
