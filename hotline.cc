#include "cpr/cpr.h"
#include <iostream>

int main(int argc, char **argv) {
  std::cout << "test" << std::endl;

  cpr::Response r = cpr::Get(
      cpr::Url{"https://api.github.com/repos/whoshuu/cpr/contributors"},
      cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC},
      cpr::Parameters{{"anon", "true"}, {"key", "value"}});
  r.status_code;                    // 200
  r.header["content-type"];         // application/json; charset=utf-8
  std::cout << r.text << std::endl; // JSON text string
  return 0;
}
