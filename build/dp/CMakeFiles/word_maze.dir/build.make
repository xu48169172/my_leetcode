# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/star/work/leetcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/star/work/leetcode/build

# Include any dependencies generated for this target.
include dp/CMakeFiles/word_maze.dir/depend.make

# Include the progress variables for this target.
include dp/CMakeFiles/word_maze.dir/progress.make

# Include the compile flags for this target's objects.
include dp/CMakeFiles/word_maze.dir/flags.make

dp/CMakeFiles/word_maze.dir/word_maze.o: dp/CMakeFiles/word_maze.dir/flags.make
dp/CMakeFiles/word_maze.dir/word_maze.o: ../dp/word_maze.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/star/work/leetcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object dp/CMakeFiles/word_maze.dir/word_maze.o"
	cd /home/star/work/leetcode/build/dp && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/word_maze.dir/word_maze.o   -c /home/star/work/leetcode/dp/word_maze.c

dp/CMakeFiles/word_maze.dir/word_maze.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/word_maze.dir/word_maze.i"
	cd /home/star/work/leetcode/build/dp && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/star/work/leetcode/dp/word_maze.c > CMakeFiles/word_maze.dir/word_maze.i

dp/CMakeFiles/word_maze.dir/word_maze.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/word_maze.dir/word_maze.s"
	cd /home/star/work/leetcode/build/dp && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/star/work/leetcode/dp/word_maze.c -o CMakeFiles/word_maze.dir/word_maze.s

dp/CMakeFiles/word_maze.dir/word_maze.o.requires:

.PHONY : dp/CMakeFiles/word_maze.dir/word_maze.o.requires

dp/CMakeFiles/word_maze.dir/word_maze.o.provides: dp/CMakeFiles/word_maze.dir/word_maze.o.requires
	$(MAKE) -f dp/CMakeFiles/word_maze.dir/build.make dp/CMakeFiles/word_maze.dir/word_maze.o.provides.build
.PHONY : dp/CMakeFiles/word_maze.dir/word_maze.o.provides

dp/CMakeFiles/word_maze.dir/word_maze.o.provides.build: dp/CMakeFiles/word_maze.dir/word_maze.o


# Object files for target word_maze
word_maze_OBJECTS = \
"CMakeFiles/word_maze.dir/word_maze.o"

# External object files for target word_maze
word_maze_EXTERNAL_OBJECTS =

dp/word_maze: dp/CMakeFiles/word_maze.dir/word_maze.o
dp/word_maze: dp/CMakeFiles/word_maze.dir/build.make
dp/word_maze: dp/CMakeFiles/word_maze.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/star/work/leetcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable word_maze"
	cd /home/star/work/leetcode/build/dp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/word_maze.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dp/CMakeFiles/word_maze.dir/build: dp/word_maze

.PHONY : dp/CMakeFiles/word_maze.dir/build

dp/CMakeFiles/word_maze.dir/requires: dp/CMakeFiles/word_maze.dir/word_maze.o.requires

.PHONY : dp/CMakeFiles/word_maze.dir/requires

dp/CMakeFiles/word_maze.dir/clean:
	cd /home/star/work/leetcode/build/dp && $(CMAKE_COMMAND) -P CMakeFiles/word_maze.dir/cmake_clean.cmake
.PHONY : dp/CMakeFiles/word_maze.dir/clean

dp/CMakeFiles/word_maze.dir/depend:
	cd /home/star/work/leetcode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/star/work/leetcode /home/star/work/leetcode/dp /home/star/work/leetcode/build /home/star/work/leetcode/build/dp /home/star/work/leetcode/build/dp/CMakeFiles/word_maze.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : dp/CMakeFiles/word_maze.dir/depend
