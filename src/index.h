#pragma once

#include <drogon/HttpSimpleController.h>
#include <drogon/HttpTypes.h>
#include <drogon/utils/FunctionTraits.h>
#include <functional>

class IndexController: public drogon::HttpSimpleController<IndexController> {
  public:
    void asyncHandleHttpRequest(
      const drogon::HttpRequestPtr& req,
      std::function<void (const drogon::HttpResponsePtr &)> &&callback
    ) override;
    PATH_LIST_BEGIN
      PATH_ADD("/", drogon::Get)
    PATH_LIST_END
};
