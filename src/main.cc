#include <drogon/drogon.h>
#include "index.h"

int main() {
  drogon::app().setLogPath("./")
    .addListener("0.0.0.0", 8888)
    .setThreadNum(12)
    .run();
}
