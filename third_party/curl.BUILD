package(default_visibility = ["//visibility:public"])

cc_library(
    name = "curl",
    srcs = glob(["lib/**/*.c"]),
    hdrs = glob(["include/curl/*.h", "lib/**/*.h"]),
    includes = ["include", "lib"],
    defines = ["CURL_STATICLIB"],
)
