load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "cpr",
    remote = "https://github.com/libcpr/cpr.git",
    branch = "master",
    build_file = "//third_party:cpr.BUILD",
)

git_repository(
    name = "rules_foreign_cc",
    remote = "https://github.com/bazelbuild/rules_foreign_cc.git",
    branch = "main",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()

# Hedron's Compile Commands Extractor for Bazel
# https://github.com/hedronvision/bazel-compile-commands-extractor
git_repository(
    name = "hedron_compile_commands",
    remote = "https://github.com/hedronvision/bazel-compile-commands-extractor.git",
    branch = "main",
)

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")

hedron_compile_commands_setup()

load("@hedron_compile_commands//:workspace_setup_transitive.bzl", "hedron_compile_commands_setup_transitive")

hedron_compile_commands_setup_transitive()

load("@hedron_compile_commands//:workspace_setup_transitive_transitive.bzl", "hedron_compile_commands_setup_transitive_transitive")

hedron_compile_commands_setup_transitive_transitive()

load("@hedron_compile_commands//:workspace_setup_transitive_transitive_transitive.bzl", "hedron_compile_commands_setup_transitive_transitive_transitive")

hedron_compile_commands_setup_transitive_transitive_transitive()
