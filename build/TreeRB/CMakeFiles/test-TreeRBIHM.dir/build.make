# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_SOURCE_DIR = /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TEA/src/TreeRB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TEA/build/TreeRB

# Include any dependencies generated for this target.
include CMakeFiles/test-TreeRBIHM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test-TreeRBIHM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test-TreeRBIHM.dir/flags.make

CMakeFiles/test-TreeRBIHM.dir/test-TreeRBIHM.c.o: CMakeFiles/test-TreeRBIHM.dir/flags.make
CMakeFiles/test-TreeRBIHM.dir/test-TreeRBIHM.c.o: /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TEA/src/TreeRB/test-TreeRBIHM.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TEA/build/TreeRB/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test-TreeRBIHM.dir/test-TreeRBIHM.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-TreeRBIHM.dir/test-TreeRBIHM.c.o   -c /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TEA/src/TreeRB/test-TreeRBIHM.c

CMakeFiles/test-TreeRBIHM.dir/test-TreeRBIHM.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-TreeRBIHM.dir/test-TreeRBIHM.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TEA/src/TreeRB/test-TreeRBIHM.c > CMakeFiles/test-TreeRBIHM.dir/test-TreeRBIHM.c.i

CMakeFiles/test-TreeRBIHM.dir/test-TreeRBIHM.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-TreeRBIHM.dir/test-TreeRBIHM.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TEA/src/TreeRB/test-TreeRBIHM.c -o CMakeFiles/test-TreeRBIHM.dir/test-TreeRBIHM.c.s

# Object files for target test-TreeRBIHM
test__TreeRBIHM_OBJECTS = \
"CMakeFiles/test-TreeRBIHM.dir/test-TreeRBIHM.c.o"

# External object files for target test-TreeRBIHM
test__TreeRBIHM_EXTERNAL_OBJECTS =

test-TreeRBIHM: CMakeFiles/test-TreeRBIHM.dir/test-TreeRBIHM.c.o
test-TreeRBIHM: CMakeFiles/test-TreeRBIHM.dir/build.make
test-TreeRBIHM: libTreeRB.so.0.0.1
test-TreeRBIHM: /usr/lib/x86_64-linux-gnu/libGL.so
test-TreeRBIHM: /usr/lib/x86_64-linux-gnu/libGLU.so
test-TreeRBIHM: /usr/lib/x86_64-linux-gnu/libglut.so
test-TreeRBIHM: CMakeFiles/test-TreeRBIHM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TEA/build/TreeRB/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test-TreeRBIHM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-TreeRBIHM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test-TreeRBIHM.dir/build: test-TreeRBIHM

.PHONY : CMakeFiles/test-TreeRBIHM.dir/build

CMakeFiles/test-TreeRBIHM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test-TreeRBIHM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test-TreeRBIHM.dir/clean

CMakeFiles/test-TreeRBIHM.dir/depend:
	cd /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TEA/build/TreeRB && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TEA/src/TreeRB /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TEA/src/TreeRB /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TEA/build/TreeRB /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TEA/build/TreeRB /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TEA/build/TreeRB/CMakeFiles/test-TreeRBIHM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test-TreeRBIHM.dir/depend

