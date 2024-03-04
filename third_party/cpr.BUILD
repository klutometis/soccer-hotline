load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

package(default_visibility = ["//visibility:public"])

filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
)

# TODO(danenberg): Can we download dependencies so that we don't have
# to use --spawn_strategy=standalone?
#
# See e.g. https://github.com/bazelbuild/rules_foreign_cc/issues/312.
cmake(
    name = "cpr",
    lib_source = ":all_srcs",
    lib_name = "libcpr",
    cache_entries = {
        "BUILD_SHARED_LIBS": "OFF",
        "BUILD_STATIC_LIBS": "ON",
    },
    linkopts = ["-lcurl"],
    tags = ["requires-network"],
    out_include_dir = "libcpr/include",
)
