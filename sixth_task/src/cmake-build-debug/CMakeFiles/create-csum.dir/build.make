# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dwarf/Документы/OS_TASKS/sixth_task/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dwarf/Документы/OS_TASKS/sixth_task/src/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/create-csum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/create-csum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/create-csum.dir/flags.make

CMakeFiles/create-csum.dir/create-csum.c.o: CMakeFiles/create-csum.dir/flags.make
CMakeFiles/create-csum.dir/create-csum.c.o: ../create-csum.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dwarf/Документы/OS_TASKS/sixth_task/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/create-csum.dir/create-csum.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/create-csum.dir/create-csum.c.o   -c /home/dwarf/Документы/OS_TASKS/sixth_task/src/create-csum.c

CMakeFiles/create-csum.dir/create-csum.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/create-csum.dir/create-csum.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dwarf/Документы/OS_TASKS/sixth_task/src/create-csum.c > CMakeFiles/create-csum.dir/create-csum.c.i

CMakeFiles/create-csum.dir/create-csum.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/create-csum.dir/create-csum.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dwarf/Документы/OS_TASKS/sixth_task/src/create-csum.c -o CMakeFiles/create-csum.dir/create-csum.c.s

# Object files for target create-csum
create__csum_OBJECTS = \
"CMakeFiles/create-csum.dir/create-csum.c.o"

# External object files for target create-csum
create__csum_EXTERNAL_OBJECTS =

create-csum: CMakeFiles/create-csum.dir/create-csum.c.o
create-csum: CMakeFiles/create-csum.dir/build.make
create-csum: CMakeFiles/create-csum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dwarf/Документы/OS_TASKS/sixth_task/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable create-csum"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/create-csum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/create-csum.dir/build: create-csum

.PHONY : CMakeFiles/create-csum.dir/build

CMakeFiles/create-csum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/create-csum.dir/cmake_clean.cmake
.PHONY : CMakeFiles/create-csum.dir/clean

CMakeFiles/create-csum.dir/depend:
	cd /home/dwarf/Документы/OS_TASKS/sixth_task/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dwarf/Документы/OS_TASKS/sixth_task/src /home/dwarf/Документы/OS_TASKS/sixth_task/src /home/dwarf/Документы/OS_TASKS/sixth_task/src/cmake-build-debug /home/dwarf/Документы/OS_TASKS/sixth_task/src/cmake-build-debug /home/dwarf/Документы/OS_TASKS/sixth_task/src/cmake-build-debug/CMakeFiles/create-csum.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/create-csum.dir/depend
