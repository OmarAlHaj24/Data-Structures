# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\AmrMahmoud\CLionProjects\recSort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\AmrMahmoud\CLionProjects\recSort\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/recSort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/recSort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/recSort.dir/flags.make

CMakeFiles/recSort.dir/main.cpp.obj: CMakeFiles/recSort.dir/flags.make
CMakeFiles/recSort.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\AmrMahmoud\CLionProjects\recSort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/recSort.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\recSort.dir\main.cpp.obj -c C:\Users\AmrMahmoud\CLionProjects\recSort\main.cpp

CMakeFiles/recSort.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/recSort.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\AmrMahmoud\CLionProjects\recSort\main.cpp > CMakeFiles\recSort.dir\main.cpp.i

CMakeFiles/recSort.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/recSort.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\AmrMahmoud\CLionProjects\recSort\main.cpp -o CMakeFiles\recSort.dir\main.cpp.s

# Object files for target recSort
recSort_OBJECTS = \
"CMakeFiles/recSort.dir/main.cpp.obj"

# External object files for target recSort
recSort_EXTERNAL_OBJECTS =

recSort.exe: CMakeFiles/recSort.dir/main.cpp.obj
recSort.exe: CMakeFiles/recSort.dir/build.make
recSort.exe: CMakeFiles/recSort.dir/linklibs.rsp
recSort.exe: CMakeFiles/recSort.dir/objects1.rsp
recSort.exe: CMakeFiles/recSort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\AmrMahmoud\CLionProjects\recSort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable recSort.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\recSort.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/recSort.dir/build: recSort.exe

.PHONY : CMakeFiles/recSort.dir/build

CMakeFiles/recSort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\recSort.dir\cmake_clean.cmake
.PHONY : CMakeFiles/recSort.dir/clean

CMakeFiles/recSort.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\AmrMahmoud\CLionProjects\recSort C:\Users\AmrMahmoud\CLionProjects\recSort C:\Users\AmrMahmoud\CLionProjects\recSort\cmake-build-debug C:\Users\AmrMahmoud\CLionProjects\recSort\cmake-build-debug C:\Users\AmrMahmoud\CLionProjects\recSort\cmake-build-debug\CMakeFiles\recSort.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/recSort.dir/depend
