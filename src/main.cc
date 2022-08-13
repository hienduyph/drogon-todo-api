#include <drogon/drogon.h>
#include <spdlog/spdlog.h>

int main() {
  auto port = 8888;
  spdlog::info("Listening at {}", port);
  drogon::app().setLogPath("./")
    .addListener("0.0.0.0", port)
    .setThreadNum(12)
    .run();
}
