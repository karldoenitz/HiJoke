/**
 * Created by lizhihao on 10/16/15.
 */

$(document).ready(
    function()
    {
        $("#Submit").click(
            function()
            {
                $.post(
                    "/admin-login",
                    {
                        username: $("#id_email").val(),
                        password: $("#id_password").val()
                    },
                    function(data, status)
                    {
                        if(status == 'success')
                        {
                            if(data["result"]!="login success")
                            {
                                alert(data["result"]);
                            }
                            else
                            {
                                //发起请求，页面跳转
                                window.location.href="/admin-index";
                            }
                        }
                    }
                );
            }
        );
        $("#admin-logout").click(
            function()
            {
                $.post(
                    "/logout",
                    {
                    },
                    function(data, status)
                    {
                        if(status == 'success')
                        {
                            if(data["result"]!="logout success")
                            {
                                alert(data["result"]);
                            }
                            else
                            {
                                //发起请求，页面跳转
                                window.location.href="/admin-login-view";
                            }
                        }
                    }
                );
            }
        );
    }
);
