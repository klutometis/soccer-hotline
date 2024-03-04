# TODO

## libpcr requires `--spawn_strategy=standalone`

Because CMake downloads things like zlib, needs network access; which doesn't
work in the build sandbox. Is there a way to avoid using the sandbox by
enumerating the dependencies (zlib, libcurl, etc.)?

See e.g.:

- https://github.com/bazelbuild/rules_foreign_cc/issues?q=spawn_strategy

There used to be something called `cmake_external` and `foreign_cc` used to use
`/tmp` instead of the sandbox. Also, `--spawn_strategy=standalone` seems to be
embedded in the `.blazerc` itself (see
[here](https://github.com/bazelbuild/rules_foreign_cc/blob/5547abc63b12c521113208eea0c5d7f66ba494d4/examples/cmake_crosstool/.bazelrc#L1)).

Oh, `standalone` is
[deprecated](https://bazel.build/docs/user-manual#execution-strategy); use
`local`.

Someone tried using the `requires-network` tag
[here](https://github.com/bazelbuild/rules_foreign_cc/issues/346), but it didn't
seem to work; apparently this is one of the
[common tags](https://bazel.build/reference/be/common-definitions#common.tags)
in Bazel.

Oh, it worked! But building inside the sandbox has all sort of other bizarre
effects (there's a `copy_libcpr` directory with allof our header files with no
way to refer to them).

When not `--spawn_strategy=local`, have to refer to the `copy_` directory,
apparently; see
[this issue](https://github.com/bazelbuild/rules_foreign_cc/issues/320):

> Hi @mattgodbolt, right now you can select the copy_postgres directory with the
> filegroup, specifying the output_group as "gen_dir". (and write a custom
> Starlark rule for selecting the certain files by name/subpath. I quickly
> sketched one: bazelbuild/bazel-skylib#194 - probably I will make it a pull
> request.)

See everything related to
https://github.com/bazelbuild/rules_foreign_cc/issues?q=copy_.

See [this issue](https://github.com/bazelbuild/rules_foreign_cc/issues/1010),
too.
