# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/build

# Include any dependencies generated for this target.
include CMakeFiles/getTouch.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/getTouch.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/getTouch.dir/flags.make

CMakeFiles/getTouch.dir/src/processTouch.cpp.o: CMakeFiles/getTouch.dir/flags.make
CMakeFiles/getTouch.dir/src/processTouch.cpp.o: ../src/processTouch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/getTouch.dir/src/processTouch.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/getTouch.dir/src/processTouch.cpp.o -c /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/src/processTouch.cpp

CMakeFiles/getTouch.dir/src/processTouch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/getTouch.dir/src/processTouch.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/src/processTouch.cpp > CMakeFiles/getTouch.dir/src/processTouch.cpp.i

CMakeFiles/getTouch.dir/src/processTouch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/getTouch.dir/src/processTouch.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/src/processTouch.cpp -o CMakeFiles/getTouch.dir/src/processTouch.cpp.s

CMakeFiles/getTouch.dir/src/processTouch.cpp.o.requires:

.PHONY : CMakeFiles/getTouch.dir/src/processTouch.cpp.o.requires

CMakeFiles/getTouch.dir/src/processTouch.cpp.o.provides: CMakeFiles/getTouch.dir/src/processTouch.cpp.o.requires
	$(MAKE) -f CMakeFiles/getTouch.dir/build.make CMakeFiles/getTouch.dir/src/processTouch.cpp.o.provides.build
.PHONY : CMakeFiles/getTouch.dir/src/processTouch.cpp.o.provides

CMakeFiles/getTouch.dir/src/processTouch.cpp.o.provides.build: CMakeFiles/getTouch.dir/src/processTouch.cpp.o


CMakeFiles/getTouch.dir/src/getTouch.cpp.o: CMakeFiles/getTouch.dir/flags.make
CMakeFiles/getTouch.dir/src/getTouch.cpp.o: ../src/getTouch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/getTouch.dir/src/getTouch.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/getTouch.dir/src/getTouch.cpp.o -c /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/src/getTouch.cpp

CMakeFiles/getTouch.dir/src/getTouch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/getTouch.dir/src/getTouch.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/src/getTouch.cpp > CMakeFiles/getTouch.dir/src/getTouch.cpp.i

CMakeFiles/getTouch.dir/src/getTouch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/getTouch.dir/src/getTouch.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/src/getTouch.cpp -o CMakeFiles/getTouch.dir/src/getTouch.cpp.s

CMakeFiles/getTouch.dir/src/getTouch.cpp.o.requires:

.PHONY : CMakeFiles/getTouch.dir/src/getTouch.cpp.o.requires

CMakeFiles/getTouch.dir/src/getTouch.cpp.o.provides: CMakeFiles/getTouch.dir/src/getTouch.cpp.o.requires
	$(MAKE) -f CMakeFiles/getTouch.dir/build.make CMakeFiles/getTouch.dir/src/getTouch.cpp.o.provides.build
.PHONY : CMakeFiles/getTouch.dir/src/getTouch.cpp.o.provides

CMakeFiles/getTouch.dir/src/getTouch.cpp.o.provides.build: CMakeFiles/getTouch.dir/src/getTouch.cpp.o


CMakeFiles/getTouch.dir/src/main.cpp.o: CMakeFiles/getTouch.dir/flags.make
CMakeFiles/getTouch.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/getTouch.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/getTouch.dir/src/main.cpp.o -c /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/src/main.cpp

CMakeFiles/getTouch.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/getTouch.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/src/main.cpp > CMakeFiles/getTouch.dir/src/main.cpp.i

CMakeFiles/getTouch.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/getTouch.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/src/main.cpp -o CMakeFiles/getTouch.dir/src/main.cpp.s

CMakeFiles/getTouch.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/getTouch.dir/src/main.cpp.o.requires

CMakeFiles/getTouch.dir/src/main.cpp.o.provides: CMakeFiles/getTouch.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/getTouch.dir/build.make CMakeFiles/getTouch.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/getTouch.dir/src/main.cpp.o.provides

CMakeFiles/getTouch.dir/src/main.cpp.o.provides.build: CMakeFiles/getTouch.dir/src/main.cpp.o


CMakeFiles/getTouch.dir/src/finger.cpp.o: CMakeFiles/getTouch.dir/flags.make
CMakeFiles/getTouch.dir/src/finger.cpp.o: ../src/finger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/getTouch.dir/src/finger.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/getTouch.dir/src/finger.cpp.o -c /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/src/finger.cpp

CMakeFiles/getTouch.dir/src/finger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/getTouch.dir/src/finger.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/src/finger.cpp > CMakeFiles/getTouch.dir/src/finger.cpp.i

CMakeFiles/getTouch.dir/src/finger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/getTouch.dir/src/finger.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/src/finger.cpp -o CMakeFiles/getTouch.dir/src/finger.cpp.s

CMakeFiles/getTouch.dir/src/finger.cpp.o.requires:

.PHONY : CMakeFiles/getTouch.dir/src/finger.cpp.o.requires

CMakeFiles/getTouch.dir/src/finger.cpp.o.provides: CMakeFiles/getTouch.dir/src/finger.cpp.o.requires
	$(MAKE) -f CMakeFiles/getTouch.dir/build.make CMakeFiles/getTouch.dir/src/finger.cpp.o.provides.build
.PHONY : CMakeFiles/getTouch.dir/src/finger.cpp.o.provides

CMakeFiles/getTouch.dir/src/finger.cpp.o.provides.build: CMakeFiles/getTouch.dir/src/finger.cpp.o


CMakeFiles/getTouch.dir/src/writeFile.cpp.o: CMakeFiles/getTouch.dir/flags.make
CMakeFiles/getTouch.dir/src/writeFile.cpp.o: ../src/writeFile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/getTouch.dir/src/writeFile.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/getTouch.dir/src/writeFile.cpp.o -c /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/src/writeFile.cpp

CMakeFiles/getTouch.dir/src/writeFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/getTouch.dir/src/writeFile.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/src/writeFile.cpp > CMakeFiles/getTouch.dir/src/writeFile.cpp.i

CMakeFiles/getTouch.dir/src/writeFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/getTouch.dir/src/writeFile.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/src/writeFile.cpp -o CMakeFiles/getTouch.dir/src/writeFile.cpp.s

CMakeFiles/getTouch.dir/src/writeFile.cpp.o.requires:

.PHONY : CMakeFiles/getTouch.dir/src/writeFile.cpp.o.requires

CMakeFiles/getTouch.dir/src/writeFile.cpp.o.provides: CMakeFiles/getTouch.dir/src/writeFile.cpp.o.requires
	$(MAKE) -f CMakeFiles/getTouch.dir/build.make CMakeFiles/getTouch.dir/src/writeFile.cpp.o.provides.build
.PHONY : CMakeFiles/getTouch.dir/src/writeFile.cpp.o.provides

CMakeFiles/getTouch.dir/src/writeFile.cpp.o.provides.build: CMakeFiles/getTouch.dir/src/writeFile.cpp.o


# Object files for target getTouch
getTouch_OBJECTS = \
"CMakeFiles/getTouch.dir/src/processTouch.cpp.o" \
"CMakeFiles/getTouch.dir/src/getTouch.cpp.o" \
"CMakeFiles/getTouch.dir/src/main.cpp.o" \
"CMakeFiles/getTouch.dir/src/finger.cpp.o" \
"CMakeFiles/getTouch.dir/src/writeFile.cpp.o"

# External object files for target getTouch
getTouch_EXTERNAL_OBJECTS =

getTouch: CMakeFiles/getTouch.dir/src/processTouch.cpp.o
getTouch: CMakeFiles/getTouch.dir/src/getTouch.cpp.o
getTouch: CMakeFiles/getTouch.dir/src/main.cpp.o
getTouch: CMakeFiles/getTouch.dir/src/finger.cpp.o
getTouch: CMakeFiles/getTouch.dir/src/writeFile.cpp.o
getTouch: CMakeFiles/getTouch.dir/build.make
getTouch: vecmath/libvecmath.a
getTouch: CMakeFiles/getTouch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable getTouch"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/getTouch.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/getTouch.dir/build: getTouch

.PHONY : CMakeFiles/getTouch.dir/build

CMakeFiles/getTouch.dir/requires: CMakeFiles/getTouch.dir/src/processTouch.cpp.o.requires
CMakeFiles/getTouch.dir/requires: CMakeFiles/getTouch.dir/src/getTouch.cpp.o.requires
CMakeFiles/getTouch.dir/requires: CMakeFiles/getTouch.dir/src/main.cpp.o.requires
CMakeFiles/getTouch.dir/requires: CMakeFiles/getTouch.dir/src/finger.cpp.o.requires
CMakeFiles/getTouch.dir/requires: CMakeFiles/getTouch.dir/src/writeFile.cpp.o.requires

.PHONY : CMakeFiles/getTouch.dir/requires

CMakeFiles/getTouch.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/getTouch.dir/cmake_clean.cmake
.PHONY : CMakeFiles/getTouch.dir/clean

CMakeFiles/getTouch.dir/depend:
	cd /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/build /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/build /home/tianye/Documents/6.s063/Final_Project/6.s063_Scanner/build/CMakeFiles/getTouch.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/getTouch.dir/depend

