# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/seunggyun-jeong/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/seunggyun-jeong/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/seunggyun-jeong/Desktop/System-Programming/11Assignment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/seunggyun-jeong/Desktop/System-Programming/11Assignment/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/11Assignment.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/11Assignment.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/11Assignment.dir/flags.make

CMakeFiles/11Assignment.dir/main.c.o: CMakeFiles/11Assignment.dir/flags.make
CMakeFiles/11Assignment.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seunggyun-jeong/Desktop/System-Programming/11Assignment/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/11Assignment.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/11Assignment.dir/main.c.o -c /Users/seunggyun-jeong/Desktop/System-Programming/11Assignment/main.c

CMakeFiles/11Assignment.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/11Assignment.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/seunggyun-jeong/Desktop/System-Programming/11Assignment/main.c > CMakeFiles/11Assignment.dir/main.c.i

CMakeFiles/11Assignment.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/11Assignment.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/seunggyun-jeong/Desktop/System-Programming/11Assignment/main.c -o CMakeFiles/11Assignment.dir/main.c.s

# Object files for target 11Assignment
11Assignment_OBJECTS = \
"CMakeFiles/11Assignment.dir/main.c.o"

# External object files for target 11Assignment
11Assignment_EXTERNAL_OBJECTS =

11Assignment: CMakeFiles/11Assignment.dir/main.c.o
11Assignment: CMakeFiles/11Assignment.dir/build.make
11Assignment: CMakeFiles/11Assignment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/seunggyun-jeong/Desktop/System-Programming/11Assignment/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 11Assignment"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/11Assignment.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/11Assignment.dir/build: 11Assignment
.PHONY : CMakeFiles/11Assignment.dir/build

CMakeFiles/11Assignment.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/11Assignment.dir/cmake_clean.cmake
.PHONY : CMakeFiles/11Assignment.dir/clean

CMakeFiles/11Assignment.dir/depend:
	cd /Users/seunggyun-jeong/Desktop/System-Programming/11Assignment/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/seunggyun-jeong/Desktop/System-Programming/11Assignment /Users/seunggyun-jeong/Desktop/System-Programming/11Assignment /Users/seunggyun-jeong/Desktop/System-Programming/11Assignment/cmake-build-debug /Users/seunggyun-jeong/Desktop/System-Programming/11Assignment/cmake-build-debug /Users/seunggyun-jeong/Desktop/System-Programming/11Assignment/cmake-build-debug/CMakeFiles/11Assignment.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/11Assignment.dir/depend

