# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/dwarf/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.6911.21/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/dwarf/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.6911.21/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dwarf/Документы/OS_TASKS/fourth_task/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dwarf/Документы/OS_TASKS/fourth_task/src/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/exaple_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/exaple_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exaple_2.dir/flags.make

CMakeFiles/exaple_2.dir/example_2.c.o: CMakeFiles/exaple_2.dir/flags.make
CMakeFiles/exaple_2.dir/example_2.c.o: ../example_2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dwarf/Документы/OS_TASKS/fourth_task/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/exaple_2.dir/example_2.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/exaple_2.dir/example_2.c.o   -c /home/dwarf/Документы/OS_TASKS/fourth_task/src/example_2.c

CMakeFiles/exaple_2.dir/example_2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/exaple_2.dir/example_2.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dwarf/Документы/OS_TASKS/fourth_task/src/example_2.c > CMakeFiles/exaple_2.dir/example_2.c.i

CMakeFiles/exaple_2.dir/example_2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/exaple_2.dir/example_2.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dwarf/Документы/OS_TASKS/fourth_task/src/example_2.c -o CMakeFiles/exaple_2.dir/example_2.c.s

# Object files for target exaple_2
exaple_2_OBJECTS = \
"CMakeFiles/exaple_2.dir/example_2.c.o"

# External object files for target exaple_2
exaple_2_EXTERNAL_OBJECTS =

exaple_2: CMakeFiles/exaple_2.dir/example_2.c.o
exaple_2: CMakeFiles/exaple_2.dir/build.make
exaple_2: CMakeFiles/exaple_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dwarf/Документы/OS_TASKS/fourth_task/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable exaple_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exaple_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exaple_2.dir/build: exaple_2

.PHONY : CMakeFiles/exaple_2.dir/build

CMakeFiles/exaple_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exaple_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exaple_2.dir/clean

CMakeFiles/exaple_2.dir/depend:
	cd /home/dwarf/Документы/OS_TASKS/fourth_task/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dwarf/Документы/OS_TASKS/fourth_task/src /home/dwarf/Документы/OS_TASKS/fourth_task/src /home/dwarf/Документы/OS_TASKS/fourth_task/src/cmake-build-debug /home/dwarf/Документы/OS_TASKS/fourth_task/src/cmake-build-debug /home/dwarf/Документы/OS_TASKS/fourth_task/src/cmake-build-debug/CMakeFiles/exaple_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exaple_2.dir/depend
