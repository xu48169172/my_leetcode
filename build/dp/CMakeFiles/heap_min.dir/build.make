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
include dp/CMakeFiles/heap_min.dir/depend.make

# Include the progress variables for this target.
include dp/CMakeFiles/heap_min.dir/progress.make

# Include the compile flags for this target's objects.
include dp/CMakeFiles/heap_min.dir/flags.make

dp/CMakeFiles/heap_min.dir/heap_min.o: dp/CMakeFiles/heap_min.dir/flags.make
dp/CMakeFiles/heap_min.dir/heap_min.o: ../dp/heap_min.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/star/work/leetcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object dp/CMakeFiles/heap_min.dir/heap_min.o"
	cd /home/star/work/leetcode/build/dp && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/heap_min.dir/heap_min.o   -c /home/star/work/leetcode/dp/heap_min.c

dp/CMakeFiles/heap_min.dir/heap_min.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/heap_min.dir/heap_min.i"
	cd /home/star/work/leetcode/build/dp && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/star/work/leetcode/dp/heap_min.c > CMakeFiles/heap_min.dir/heap_min.i

dp/CMakeFiles/heap_min.dir/heap_min.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/heap_min.dir/heap_min.s"
	cd /home/star/work/leetcode/build/dp && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/star/work/leetcode/dp/heap_min.c -o CMakeFiles/heap_min.dir/heap_min.s

dp/CMakeFiles/heap_min.dir/heap_min.o.requires:

.PHONY : dp/CMakeFiles/heap_min.dir/heap_min.o.requires

dp/CMakeFiles/heap_min.dir/heap_min.o.provides: dp/CMakeFiles/heap_min.dir/heap_min.o.requires
	$(MAKE) -f dp/CMakeFiles/heap_min.dir/build.make dp/CMakeFiles/heap_min.dir/heap_min.o.provides.build
.PHONY : dp/CMakeFiles/heap_min.dir/heap_min.o.provides

dp/CMakeFiles/heap_min.dir/heap_min.o.provides.build: dp/CMakeFiles/heap_min.dir/heap_min.o


# Object files for target heap_min
heap_min_OBJECTS = \
"CMakeFiles/heap_min.dir/heap_min.o"

# External object files for target heap_min
heap_min_EXTERNAL_OBJECTS =

dp/heap_min: dp/CMakeFiles/heap_min.dir/heap_min.o
dp/heap_min: dp/CMakeFiles/heap_min.dir/build.make
dp/heap_min: dp/CMakeFiles/heap_min.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/star/work/leetcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable heap_min"
	cd /home/star/work/leetcode/build/dp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/heap_min.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dp/CMakeFiles/heap_min.dir/build: dp/heap_min

.PHONY : dp/CMakeFiles/heap_min.dir/build

dp/CMakeFiles/heap_min.dir/requires: dp/CMakeFiles/heap_min.dir/heap_min.o.requires

.PHONY : dp/CMakeFiles/heap_min.dir/requires

dp/CMakeFiles/heap_min.dir/clean:
	cd /home/star/work/leetcode/build/dp && $(CMAKE_COMMAND) -P CMakeFiles/heap_min.dir/cmake_clean.cmake
.PHONY : dp/CMakeFiles/heap_min.dir/clean

dp/CMakeFiles/heap_min.dir/depend:
	cd /home/star/work/leetcode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/star/work/leetcode /home/star/work/leetcode/dp /home/star/work/leetcode/build /home/star/work/leetcode/build/dp /home/star/work/leetcode/build/dp/CMakeFiles/heap_min.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : dp/CMakeFiles/heap_min.dir/depend

