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
CMAKE_SOURCE_DIR = /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP02/src/ntree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP02/build/ntree

# Include any dependencies generated for this target.
include CMakeFiles/ntreeStatic.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ntreeStatic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ntreeStatic.dir/flags.make

CMakeFiles/ntreeStatic.dir/ntree.c.o: CMakeFiles/ntreeStatic.dir/flags.make
CMakeFiles/ntreeStatic.dir/ntree.c.o: /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP02/src/ntree/ntree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP02/build/ntree/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ntreeStatic.dir/ntree.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ntreeStatic.dir/ntree.c.o   -c /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP02/src/ntree/ntree.c

CMakeFiles/ntreeStatic.dir/ntree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ntreeStatic.dir/ntree.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP02/src/ntree/ntree.c > CMakeFiles/ntreeStatic.dir/ntree.c.i

CMakeFiles/ntreeStatic.dir/ntree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ntreeStatic.dir/ntree.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP02/src/ntree/ntree.c -o CMakeFiles/ntreeStatic.dir/ntree.c.s

# Object files for target ntreeStatic
ntreeStatic_OBJECTS = \
"CMakeFiles/ntreeStatic.dir/ntree.c.o"

# External object files for target ntreeStatic
ntreeStatic_EXTERNAL_OBJECTS =

libntree.a: CMakeFiles/ntreeStatic.dir/ntree.c.o
libntree.a: CMakeFiles/ntreeStatic.dir/build.make
libntree.a: CMakeFiles/ntreeStatic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP02/build/ntree/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libntree.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ntreeStatic.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ntreeStatic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ntreeStatic.dir/build: libntree.a

.PHONY : CMakeFiles/ntreeStatic.dir/build

CMakeFiles/ntreeStatic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ntreeStatic.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ntreeStatic.dir/clean

CMakeFiles/ntreeStatic.dir/depend:
	cd /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP02/build/ntree && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP02/src/ntree /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP02/src/ntree /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP02/build/ntree /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP02/build/ntree /media/Windows/Users/minhh/OneDrive/UnivLR/L3/S5/ProgC/TP02/build/ntree/CMakeFiles/ntreeStatic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ntreeStatic.dir/depend
