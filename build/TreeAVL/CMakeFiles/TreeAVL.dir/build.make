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
CMAKE_SOURCE_DIR = /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP03/src/TreeAVL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP03/build/TreeAVL

# Include any dependencies generated for this target.
include CMakeFiles/TreeAVL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TreeAVL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TreeAVL.dir/flags.make

CMakeFiles/TreeAVL.dir/TreeAVL.c.o: CMakeFiles/TreeAVL.dir/flags.make
CMakeFiles/TreeAVL.dir/TreeAVL.c.o: /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP03/src/TreeAVL/TreeAVL.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP03/build/TreeAVL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TreeAVL.dir/TreeAVL.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TreeAVL.dir/TreeAVL.c.o   -c /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP03/src/TreeAVL/TreeAVL.c

CMakeFiles/TreeAVL.dir/TreeAVL.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TreeAVL.dir/TreeAVL.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP03/src/TreeAVL/TreeAVL.c > CMakeFiles/TreeAVL.dir/TreeAVL.c.i

CMakeFiles/TreeAVL.dir/TreeAVL.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TreeAVL.dir/TreeAVL.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP03/src/TreeAVL/TreeAVL.c -o CMakeFiles/TreeAVL.dir/TreeAVL.c.s

# Object files for target TreeAVL
TreeAVL_OBJECTS = \
"CMakeFiles/TreeAVL.dir/TreeAVL.c.o"

# External object files for target TreeAVL
TreeAVL_EXTERNAL_OBJECTS =

libTreeAVL.so.0.0.1: CMakeFiles/TreeAVL.dir/TreeAVL.c.o
libTreeAVL.so.0.0.1: CMakeFiles/TreeAVL.dir/build.make
libTreeAVL.so.0.0.1: /usr/lib/libefence.a
libTreeAVL.so.0.0.1: CMakeFiles/TreeAVL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP03/build/TreeAVL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libTreeAVL.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TreeAVL.dir/link.txt --verbose=$(VERBOSE)
	$(CMAKE_COMMAND) -E cmake_symlink_library libTreeAVL.so.0.0.1 libTreeAVL.so.0 libTreeAVL.so

libTreeAVL.so.0: libTreeAVL.so.0.0.1
	@$(CMAKE_COMMAND) -E touch_nocreate libTreeAVL.so.0

libTreeAVL.so: libTreeAVL.so.0.0.1
	@$(CMAKE_COMMAND) -E touch_nocreate libTreeAVL.so

# Rule to build all files generated by this target.
CMakeFiles/TreeAVL.dir/build: libTreeAVL.so

.PHONY : CMakeFiles/TreeAVL.dir/build

CMakeFiles/TreeAVL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TreeAVL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TreeAVL.dir/clean

CMakeFiles/TreeAVL.dir/depend:
	cd /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP03/build/TreeAVL && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP03/src/TreeAVL /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP03/src/TreeAVL /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP03/build/TreeAVL /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP03/build/TreeAVL /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP03/build/TreeAVL/CMakeFiles/TreeAVL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TreeAVL.dir/depend

