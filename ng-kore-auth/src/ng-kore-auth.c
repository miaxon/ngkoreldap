#include <kore/kore.h>
#include <kore/http.h>

#include "assets.h"

int page  (struct http_request *);
int login (struct http_request *);
// 

int
page(struct http_request *req)
{
    kore_log(LOG_NOTICE, "root page");
	http_response_header(req, "content-type", "text/html");
	//http_response_header(req, "set-cookie", "session_id=test123");
	http_response(req, 200, asset_page_html, asset_len_page_html);
	return (KORE_RESULT_OK);
}

int
login (struct http_request *req) {
    
    if (req->method == HTTP_METHOD_GET) {
         kore_log(LOG_NOTICE, "login page GET");
          http_response_header(req, "content-type", "text/html");
        //http_response_header(req, "set-cookie", "session_id=test123");
        http_response(req, 200, asset_login_html, asset_len_login_html);

        return (KORE_RESULT_OK);
	}
   
   if (req->method == HTTP_METHOD_POST) {
         kore_log(LOG_NOTICE, "login page POST");   
         //http_response_header(req, "content-type", "text/html");
        //http_response_header(req, "set-cookie", "session_id=test123");
		http_response_header(req, "set-cookie", "nginxauth=YWFhOmFhYQ==;httponly");
        http_response_header(req, "location", "/");
        
        http_response(req, 302, NULL, 0);
        return (KORE_RESULT_OK);
	}
   
   return (KORE_RESULT_ERROR);
}
