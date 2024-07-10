# lope
lope across your projects' directories

## usecase
I bet you have a bunch of paths in your system where you `cd` often. Just `lope`.

```shell
# instead of
cd ~/MyProjects/organization/important_project/DatabaseDumps
# just use
lope dump
# or even
lope d
```

You can define aliases for paths in your system and use them in human readable shorter commands without need for autocompletion and visual noise.

```shell
lope microservice1 && rm something && make export && lope microservice2 && make import && watch ls
```

## how it differs from `zsh-z` and similar tools

`lope` is a small `bash` script and configuration file. No database. No complex path parsing or shell integration. No statistics collection. You `lope` only around the paths you've added in configuration file.

`lope` only compares alias prefixes. `myproject` will be matched by `my` but not `project`.

## installation

make `lope` available somewhere in your `$PATH`. `/usr/bin` I guess? `~/.lopefile` should be your configuration file. __Alternatively__, you can add an alias somewhere in your `.bashrc`

```shell
alias lope='LOPE_FILE=/path/to/lopefile/.lopefile lope'
```

## configuration

`.lopefile` is just a `bash` script, you can define variables and call programms or functions. That's dangerous, see [security](#security).

`lope` defines following function for you:

### lope\_default

sets default path to lope when you call `lope` without any arguments

### lope\_alias

sets an aliases for path. You can pass zero or multiple aliases

```shell
lope_alias /home/user/Projects/MySuperProject mysuperproject msp super
```

this will set aliases `mysuperproject`, `msp` and `super` as an aliases for the path. `MySupeProject` will also be added as an alias, no need to duplicate directory name itself. Any prefix matches the alias. `m` or `my` is enough to match `mysuperproject`.

### lope\_dir

makes lope set aliases for all subdirectories in path

```shell
lope_dir /home/user/Projects
```

### example

so, your typical `.lopefile` will be something like

```shell
local PROJ=/home/user/Projects

# by default jump in projects dir
lope_default $PROJ

# add all projects as aliases
lope_dir $PROJ

# also add some special subprojects
lope_dir $PROJ/some_special_group_of_projects

# add some alternative aliases for particular projects
lope_alias $PROJ/MySuperProject msp
lope_alias $PROJ/some_special_group_of_projects special
```

## problems

`bash` doesn't guarantees and order of hash dictionaries, so `lope` may unobviously process aliases with common prefixes. If you have `project1` and `project2` `lope p` will guide you to some of them %)

## security

`lope` and `.lopefile` are `bash` scripts. Consider protecting it against unwanted writing. Any shell code put in may be executed.
