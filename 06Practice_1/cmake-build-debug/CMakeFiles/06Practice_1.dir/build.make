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
CMAKE_COMMAND = "/Users/seunggyun-jeong/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5284.51/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/seunggyun-jeong/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5284.51/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/seunggyun-jeong/Desktop/System_Programming/06Practice_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/seunggyun-jeong/Desktop/System_Programming/06Practice_1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/06Practice_1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/06Practice_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/06Practice_1.dir/flags.make

CMakeFiles/06Practice_1.dir/main.c.o: CMakeFiles/06Practice_1.dir/flags.make
CMakeFiles/06Practice_1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seunggyun-jeong/Desktop/System_Programming/06Practice_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/06Practice_1.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/06Practice_1.dir/main.c.o -c /Users/seunggyun-jeong/Desktop/System_Programming/06Practice_1/main.c

CMakeFiles/06Practice_1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/06Practice_1.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/seunggyun-jeong/Desktop/System_Programming/06Practice_1/main.c > CMakeFiles/06Practice_1.dir/main.c.i

CMakeFiles/06Practice_1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/06Practice_1.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/seunggyun-jeong/Desktop/System_Programming/06Practice_1/main.c -o CMakeFiles/06Practice_1.dir/main.c.s

# Object files for target 06Practice_1
06Practice_1_OBJECTS = \
"CMakeFiles/06Practice_1.dir/main.c.o"

# External object files for target 06Practice_1
06Practice_1_EXTERNAL_OBJECTS =

06Practice_1: CMakeFiles/06Practice_1.dir/main.c.o
06Practice_1: CMakeFiles/06Practice_1.dir/build.make
06Practice_1: CMakeFiles/06Practice_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/seunggyun-jeong/Desktop/System_Programming/06Practice_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 06Practice_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/06Practice_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/06Practice_1.dir/build: 06Practice_1
.PHONY : CMakeFiles/06Practice_1.dir/build

CMakeFiles/06Practice_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/06Practice_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/06Practice_1.dir/clean

CMakeFiles/06Practice_1.dir/depend:
	cd /Users/seunggyun-jeong/Desktop/System_Programming/06Practice_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/seunggyun-jeong/Desktop/System_Programming/06Practice_1 /Users/seunggyun-jeong/Desktop/System_Programming/06Practice_1 /Users/seunggyun-jeong/Desktop/System_Programming/06Practice_1/cmake-build-debug /Users/seunggyun-jeong/Desktop/System_Programming/06Practice_1/cmake-build-debug /Users/seunggyun-jeong/Desktop/System_Programming/06Practice_1/cmake-build-debug/CMakeFiles/06Practice_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/06Practice_1.dir/depend

