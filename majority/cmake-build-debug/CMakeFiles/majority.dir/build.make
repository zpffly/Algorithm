# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\algorithm\majority

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\algorithm\majority\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/majority.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/majority.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/majority.dir/flags.make

CMakeFiles/majority.dir/main.cpp.obj: CMakeFiles/majority.dir/flags.make
CMakeFiles/majority.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\algorithm\majority\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/majority.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\majority.dir\main.cpp.obj -c F:\algorithm\majority\main.cpp

CMakeFiles/majority.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/majority.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\algorithm\majority\main.cpp > CMakeFiles\majority.dir\main.cpp.i

CMakeFiles/majority.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/majority.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\algorithm\majority\main.cpp -o CMakeFiles\majority.dir\main.cpp.s

# Object files for target majority
majority_OBJECTS = \
"CMakeFiles/majority.dir/main.cpp.obj"

# External object files for target majority
majority_EXTERNAL_OBJECTS =

majority.exe: CMakeFiles/majority.dir/main.cpp.obj
majority.exe: CMakeFiles/majority.dir/build.make
majority.exe: CMakeFiles/majority.dir/linklibs.rsp
majority.exe: CMakeFiles/majority.dir/objects1.rsp
majority.exe: CMakeFiles/majority.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\algorithm\majority\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable majority.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\majority.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/majority.dir/build: majority.exe

.PHONY : CMakeFiles/majority.dir/build

CMakeFiles/majority.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\majority.dir\cmake_clean.cmake
.PHONY : CMakeFiles/majority.dir/clean

CMakeFiles/majority.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\algorithm\majority F:\algorithm\majority F:\algorithm\majority\cmake-build-debug F:\algorithm\majority\cmake-build-debug F:\algorithm\majority\cmake-build-debug\CMakeFiles\majority.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/majority.dir/depend

