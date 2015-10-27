/**
 * Created by lizhihao on 10/17/15.
 */

default_page_size = 10;

status_mapping = {
    1: 0,
    0: 1
};

joke_status_mapping = {
    1: 2,
    2: 1
};

operate_mapping = {
    1: "驳回",
    0: "通过"
};

joke_operate_mapping = {
    1: "驳回",
    2: "通过"
};

function get_jokes(first_index, length, status)
{
    $.get(
        "/jokes",
        {
            start_index: first_index,
            length: length,
            status: status
        },
        function(data, status)
        {
            console.log(first_index);
            console.log(length);
            console.log(status);
            console.log(data);
            if(status == 'success')
            {
                draw_joke_result(data);
            }
        }
    );
}

function draw_joke_result(data)
{
    var status = data["status"];
    var current_page = data["current_page"];
    var last_start_index = (Math.ceil(data["joke_counts"]/default_page_size)-1)*default_page_size;
    var current_joke_counts = data["current_joke_counts"];
    var joke_counts = data["joke_counts"];
    //绘制分页
    var first_page = "<li id='first_page'><a href=\"#\" class=\"active\" onclick='get_jokes(0, default_page_size, " + status + ")'>第一页</a></li>";
    var pre = "";
    if(current_page == 1){
        pre = "<li id=\"pre_page\" class=\"disabled\"><a href=\"#\">上一页</a></li>";
    }else{
        pre = "<li id=\"pre_page\"><a href=\"#\" onclick='get_jokes( " + (current_page-2)*default_page_size + ", " + default_page_size + ", " + status + ")'>上一页</a></li>";
    }
    var current = "<li id=\"current_page\"><a href=\"#\">第" + current_page + "页</a></li>";
    var next = "";
    if((current_page-1)*default_page_size+current_joke_counts==joke_counts){
        next = "<li id=\"next_page\" class=\"disabled\"><a href=\"#\">下一页</a></li>";
    }else{
        next = "<li id=\"next_page\"><a href=\"#\" onclick='get_jokes( " + current_page*default_page_size + ", " + default_page_size + ", " + status + ")'>下一页</a></li>";
    }
    var last_page = "<li id='last_page'><a href=\"#\" class=\"active\" onclick='get_jokes(" + last_start_index + ", " + default_page_size + ", " + status + ")'>最后一页</a></li>";
    var page = first_page + pre + current + next + last_page;
    document.getElementById('pagination').innerHTML = page;
    //绘制表格
      //绘制表头
    var table_header = "<tr><th>id</th><th>标题</th><th>内容</th><th>操作</th></tr>";
    document.getElementById('result_head').innerHTML = table_header;
    var table_body = "";
    for (var i=0; i<data["jokes"].length; i++){
        table_body += "<tr><td>"+data["jokes"][i]["id"]+"</td><td><a href='#' onclick='show_comment("+data["jokes"][i]["id"]+")'>"+data["jokes"][i]["title"]+"</a></td><td>"+data["jokes"][i]["content"]+"</td><td><a href='#' onclick='set_joke_status("+data["jokes"][i]["id"]+","+joke_status_mapping[status]+","+current_page+")'>"+joke_operate_mapping[status]+"</a></td></tr>";
    }
    document.getElementById('result_body').innerHTML = table_body;
    document.getElementById('page-title').innerHTML = status==1?"<span class=\"pull-right\">审核通过</span>笑话管理":"<span class=\"pull-right\">审核拒绝</span>笑话管理";
    //绘制表身
}

function show_comment(id){
    $.get(
        "/get-comment",
        {
            joke_id: id
        },
        function(data, status)
        {
            console.log("asdf");
            draw_comment_result(data);
        }
    );
}

function draw_comment_result(data){
    document.getElementById('page-title').innerHTML = "<span class=\"pull-right\">查看评论</span>笑话管理";
    var table_header = "<tr><th>id</th><th>用户名</th><th>评论内容</th></tr>";
    document.getElementById('result_head').innerHTML = table_header;
    var table_body = "";
    if("comments" in data){
        for(var i=0; i<data["comments"].length; i++){
            table_body += "<tr><td>"+data["comments"][i]["id"]+"</td><td>"+data["comments"][i]["username"]+"</td><td>"+data["comments"][i]["comment"]+"</td></tr>";
        }
    }
    document.getElementById('pagination').innerHTML = "";
    document.getElementById('result_body').innerHTML = table_body;
}

function get_users(first_index, length, status)
{
    $.get(
        "/get-users",
        {
            start_index: first_index,
            length: length,
            status: status
        },
        function(data, status)
        {
            if(status == 'success')
            {
                draw_user_result(data);
            }
        }
    );
}

function draw_user_result(data)
{
    var status = data["status"];
    var current_page = data["current_page"];
    var last_start_index = (Math.ceil(data["users_counts"]/default_page_size)-1)*default_page_size;
    var current_joke_counts = data["current_users_counts"];
    var joke_counts = data["users_counts"];
    //绘制分页
    var first_page = "<li id='first_page'><a href=\"#\" class=\"active\" onclick='get_users(0, default_page_size, " + status + ")'>第一页</a></li>";
    var pre = "";
    if(current_page == 1){
        pre = "<li id=\"pre_page\" class=\"disabled\"><a href=\"#\">上一页</a></li>";
    }else{
        pre = "<li id=\"pre_page\"><a href=\"#\" onclick='get_users( " + (current_page-2)*default_page_size + ", " + default_page_size + ", " + status + ")'>上一页</a></li>";
    }
    var current = "<li id=\"current_page\"><a href=\"#\">第" + current_page + "页</a></li>";
    var next = "";
    if((current_page-1)*default_page_size+current_joke_counts==joke_counts){
        next = "<li id=\"next_page\" class=\"disabled\"><a href=\"#\">下一页</a></li>";
    }else{
        next = "<li id=\"next_page\"><a href=\"#\" onclick='get_users( " + current_page*default_page_size + ", " + default_page_size + ", " + status + ")'>下一页</a></li>";
    }
    var last_page = "<li id='last_page'><a href=\"#\" class=\"active\" onclick='get_users(" + last_start_index + ", " + default_page_size + ", " + status + ")'>最后一页</a></li>";
    var page = first_page + pre + current + next + last_page;
    document.getElementById('pagination').innerHTML = page;
    //绘制表格
    var table_header = "<tr><th>用户名</th><th>用户唯一识别码</th><th>操作</th></tr>";
    document.getElementById('result_head').innerHTML = table_header;
    var table_body = "";
    for (var i=0; i<data["users"].length; i++){
        table_body += "<tr><td>"+data["users"][i]["username"]+"</td><td>"+data["users"][i]["usercode"]+"</td><td><a href='#' onclick=\"set_user_status( '"+data["users"][i]["usercode"]+"',"+status_mapping[status]+","+current_page+")\">"+operate_mapping[status]+"</a></td></tr>";
    }
    document.getElementById('result_body').innerHTML = table_body;
    document.getElementById('page-title').innerHTML = status==1?"<span class=\"pull-right\">审核通过</span>用户管理":"<span class=\"pull-right\">审核拒绝</span>用户管理";

}

function set_user_status(user_id, user_status, current_page)
{
    $.get(
        "/set-user-status",
        {
            usercode: user_id,
            status: user_status
        },
        function(data, status)
        {
            if(status == 'success')
            {
                if(data["result"])
                {
                    get_users((current_page-1)*default_page_size, default_page_size, status_mapping[user_status]);
                }
            }
        }
    );
}

function set_joke_status(joke_id, joke_status, current_page)
{
    $.get(
        "/set-joke-status",
        {
            id: joke_id,
            status: joke_status
        },
        function(data, status)
        {
            if(status == 'success')
            {
                if(data["result"])
                {
                    get_jokes((current_page-1)*default_page_size, default_page_size, joke_status_mapping[joke_status]);
                }
            }
        }
    );
}

$(document).ready(function(){
    get_jokes(0, default_page_size, 1);
});
