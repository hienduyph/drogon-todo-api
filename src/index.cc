#include <drogon/HttpResponse.h>
#include <drogon/drogon.h>
#include <functional>

class IndexController: public drogon::HttpController<IndexController> {
  public:
    METHOD_LIST_BEGIN
      ADD_METHOD_TO(IndexController::get, "/", drogon::Get);
    METHOD_LIST_END

    void get(
      const drogon::HttpRequestPtr& req,
      std::function<void (const drogon::HttpResponsePtr &)> &&callback
    ) {
      Json::Value res;
      res["message"] = std::string("Hello World");
      callback(drogon::HttpResponse::newHttpJsonResponse(std::move(res)));
    }
};
