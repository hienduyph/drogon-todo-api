#include "index.h"

#include <drogon/HttpSimpleController.h>
#include <drogon/HttpTypes.h>
#include <drogon/utils/FunctionTraits.h>
#include <functional>

void IndexController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
  Json::Value json;
  json["result"] = "ok";
  json["message"] = std::string("hello world");
  auto resp = drogon::HttpResponse::newHttpJsonResponse(json);
  callback(resp);
}
