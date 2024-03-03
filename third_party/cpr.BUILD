package(default_visibility = ["//visibility:public"])

filegroup(
    name = "static_headers",
    srcs = glob(["include/cpr/*.h"]),
    visibility = ["//visibility:private"],
)

filegroup(
    name = "all_headers",
    srcs = [
        ":static_headers",
        ":configure_cpr",  # Assuming this is the name of your genrule
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "cpr",
    srcs = glob(["cpr/*.cpp"]),
    hdrs = [":static_headers", ":configure_cpr"],
    includes = ["include"],
    copts = ["-std=c++17"],
    linkopts = ["-lcurl"],
    deps = [
        # "@curl//:curl"
    ],
)

genrule(
    name = "configure_cpr",
    srcs = glob(["**"]),  # [
    #     "cmake/cprver.h.in",
    #     "CMakeLists.txt",
    #     # Include other necessary files or directories
    # ]
    outs = ["cpr/cprver.h"],
    cmd = """
    touch $@ && \
    cd external/cpr && \
    cmake -E make_directory build && \
    cmake -E chdir build cmake .. && \
    cmake -E copy_if_different build/cpr_generated_includes/cpr/cprver.h $@
    """,
)
