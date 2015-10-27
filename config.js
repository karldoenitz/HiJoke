{
    "service" : {
        "ip": "0.0.0.0",
        "api" : "http",
        "port" : 8888,
    },
    "http" : {
        "script_names" : [
            "/register",
            "/login",
            "/logout",
            "/jokes",
            "/write-joke",
            "/get-comment",
            "/write-comment",
            "/admin-login-view",
            "/admin-login",
            "/admin-index",
            "/get-users",
            "/set-user-status",
            "/set-joke-status"
        ]
    },
    "session" : {
        "expire" : "renew",
        "timeout" : 604800,
        "location" : "client",
        "client" : {
            "hmac" : "sha1",
            "hmac_key" : "3891bbf7f845fd4277008a63d72640fc13bb9a31"
        }
    }
}