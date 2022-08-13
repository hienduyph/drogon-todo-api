#include <drogon/HttpController.h>
#include <drogon/HttpResponse.h>
#include <drogon/HttpTypes.h>
#include <drogon/utils/FunctionTraits.h>
#include <json/value.h>
#include <spdlog/spdlog.h>

struct Todo {
  long id = 0;
  std::string title;
  bool completed;

  Json::Value to_json() const {
    Json::Value out;
    out["id"] = id;
    out["title"] = title;
    out["completed"] = completed;
    return out;
  }

  void from_json(const Json::Value &j) {
    if (!j["title"].empty()) {
      title = j["title"].asString();
    }
    if (!j["completed"].empty()) {
      completed = j["completed"].asBool();
    }
    if (!j["id"].empty()) {
      id = j["id"].asInt64();
    }
  }
};

class TodoController : public drogon::HttpController<TodoController> {
public:
  METHOD_LIST_BEGIN
  ADD_METHOD_TO(TodoController::lists, "/todos", drogon::Get);
  ADD_METHOD_TO(TodoController::create, "/todos", drogon::Post);
  ADD_METHOD_TO(TodoController::detail, "/todos/{id}", drogon::Get);
  ADD_METHOD_TO(TodoController::update, "/todos/{id}", drogon::Put);
  ADD_METHOD_TO(TodoController::del, "/todos/{id}", drogon::Delete);
  METHOD_LIST_END

  void lists(const drogon::HttpRequestPtr &req,
             std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
    Json::Value res, items(Json::arrayValue);
    std::vector<Todo> is = {
        {1, "hello", false},
        {2, "hello 2", false},
    };
    for (const Todo &item : is) {
      items.append(item.to_json());
    }
    res["items"] = items;
    callback(drogon::HttpResponse::newHttpJsonResponse(std::move(res)));
  }

  void create(const drogon::HttpRequestPtr &req,
              std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
    auto json = req->getJsonObject();
    Todo item;
    item.from_json(*json);
    auto resp = drogon::HttpResponse::newHttpJsonResponse(item.to_json());
    resp->setStatusCode(drogon::HttpStatusCode::k201Created);
    callback(resp);
  }

  void del(const drogon::HttpRequestPtr &req,
           std::function<void(const drogon::HttpResponsePtr &)> &&callback,
           long itemId) {
    spdlog::info("Deleted {}", itemId);
    auto resp = drogon::HttpResponse::newHttpResponse();
    resp->setStatusCode(drogon::HttpStatusCode::k204NoContent);
    callback(resp);
  }

  void detail(const drogon::HttpRequestPtr &req,
              std::function<void(const drogon::HttpResponsePtr &)> &&callback,
              long itemId) {
    Todo item;
    item.id = itemId;
    item.title = "Hello world";
    item.completed = false;
    callback(drogon::HttpResponse::newHttpJsonResponse(item.to_json()));
  }

  void update(const drogon::HttpRequestPtr &req,
              std::function<void(const drogon::HttpResponsePtr &)> &&callback,
              long itemId) {
    // update items and return the update
    auto body = req->getJsonObject();
    Todo payload;
    payload.from_json(*body);

    Todo item;
    item.id = itemId;
    item.title = payload.title;
    item.completed = payload.completed;
    callback(drogon::HttpResponse::newHttpJsonResponse(item.to_json()));
  }
};
