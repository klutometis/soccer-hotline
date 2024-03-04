load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

package(default_visibility = ["//visibility:public"])

filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
)

cmake(
    name = "cpr",
    lib_source = ":all_srcs",
    lib_name = "libcpr",
    cache_entries = {
        "BUILD_SHARED_LIBS": "OFF",
        "BUILD_STATIC_LIBS": "ON",
    },
    linkopts = ["-lcurl"],
)
