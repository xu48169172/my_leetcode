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
include dp/CMakeFiles/longest_sum_in_array.dir/depend.make

# Include the progress variables for this target.
include dp/CMakeFiles/longest_sum_in_array.dir/progress.make

# Include the compile flags for this target's objects.
include dp/CMakeFiles/longest_sum_in_array.dir/flags.make

dp/CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.o: dp/CMakeFiles/longest_sum_in_array.dir/flags.make
dp/CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.o: ../dp/longest_sum_in_array.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/star/work/leetcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object dp/CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.o"
	cd /home/star/work/leetcode/build/dp && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.o   -c /home/star/work/leetcode/dp/longest_sum_in_array.c

dp/CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.i"
	cd /home/star/work/leetcode/build/dp && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/star/work/leetcode/dp/longest_sum_in_array.c > CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.i

dp/CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.s"
	cd /home/star/work/leetcode/build/dp && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/star/work/leetcode/dp/longest_sum_in_array.c -o CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.s

dp/CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.o.requires:

.PHONY : dp/CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.o.requires

dp/CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.o.provides: dp/CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.o.requires
	$(MAKE) -f dp/CMakeFiles/longest_sum_in_array.dir/build.make dp/CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.o.provides.build
.PHONY : dp/CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.o.provides

dp/CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.o.provides.build: dp/CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.o


# Object files for target longest_sum_in_array
longest_sum_in_array_OBJECTS = \
"CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.o"

# External object files for target longest_sum_in_array
longest_sum_in_array_EXTERNAL_OBJECTS =

dp/longest_sum_in_array: dp/CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.o
dp/longest_sum_in_array: dp/CMakeFiles/longest_sum_in_array.dir/build.make
dp/longest_sum_in_array: dp/CMakeFiles/longest_sum_in_array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/star/work/leetcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable longest_sum_in_array"
	cd /home/star/work/leetcode/build/dp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/longest_sum_in_array.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dp/CMakeFiles/longest_sum_in_array.dir/build: dp/longest_sum_in_array

.PHONY : dp/CMakeFiles/longest_sum_in_array.dir/build

dp/CMakeFiles/longest_sum_in_array.dir/requires: dp/CMakeFiles/longest_sum_in_array.dir/longest_sum_in_array.o.requires

.PHONY : dp/CMakeFiles/longest_sum_in_array.dir/requires

dp/CMakeFiles/longest_sum_in_array.dir/clean:
	cd /home/star/work/leetcode/build/dp && $(CMAKE_COMMAND) -P CMakeFiles/longest_sum_in_array.dir/cmake_clean.cmake
.PHONY : dp/CMakeFiles/longest_sum_in_array.dir/clean

dp/CMakeFiles/longest_sum_in_array.dir/depend:
	cd /home/star/work/leetcode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/star/work/leetcode /home/star/work/leetcode/dp /home/star/work/leetcode/build /home/star/work/leetcode/build/dp /home/star/work/leetcode/build/dp/CMakeFiles/longest_sum_in_array.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : dp/CMakeFiles/longest_sum_in_array.dir/depend
