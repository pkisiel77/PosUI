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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/pksm1/CLionProjects/PosUI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/pksm1/CLionProjects/PosUI/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PosUI.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/PosUI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PosUI.dir/flags.make

CMakeFiles/PosUI.dir/main.cpp.o: CMakeFiles/PosUI.dir/flags.make
CMakeFiles/PosUI.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pksm1/CLionProjects/PosUI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PosUI.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PosUI.dir/main.cpp.o -c /Users/pksm1/CLionProjects/PosUI/main.cpp

CMakeFiles/PosUI.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PosUI.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pksm1/CLionProjects/PosUI/main.cpp > CMakeFiles/PosUI.dir/main.cpp.i

CMakeFiles/PosUI.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PosUI.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pksm1/CLionProjects/PosUI/main.cpp -o CMakeFiles/PosUI.dir/main.cpp.s

CMakeFiles/PosUI.dir/TUI/tui.cpp.o: CMakeFiles/PosUI.dir/flags.make
CMakeFiles/PosUI.dir/TUI/tui.cpp.o: ../TUI/tui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pksm1/CLionProjects/PosUI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PosUI.dir/TUI/tui.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PosUI.dir/TUI/tui.cpp.o -c /Users/pksm1/CLionProjects/PosUI/TUI/tui.cpp

CMakeFiles/PosUI.dir/TUI/tui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PosUI.dir/TUI/tui.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pksm1/CLionProjects/PosUI/TUI/tui.cpp > CMakeFiles/PosUI.dir/TUI/tui.cpp.i

CMakeFiles/PosUI.dir/TUI/tui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PosUI.dir/TUI/tui.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pksm1/CLionProjects/PosUI/TUI/tui.cpp -o CMakeFiles/PosUI.dir/TUI/tui.cpp.s

# Object files for target PosUI
PosUI_OBJECTS = \
"CMakeFiles/PosUI.dir/main.cpp.o" \
"CMakeFiles/PosUI.dir/TUI/tui.cpp.o"

# External object files for target PosUI
PosUI_EXTERNAL_OBJECTS =

PosUI: CMakeFiles/PosUI.dir/main.cpp.o
PosUI: CMakeFiles/PosUI.dir/TUI/tui.cpp.o
PosUI: CMakeFiles/PosUI.dir/build.make
PosUI: CMakeFiles/PosUI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/pksm1/CLionProjects/PosUI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable PosUI"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PosUI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PosUI.dir/build: PosUI
.PHONY : CMakeFiles/PosUI.dir/build

CMakeFiles/PosUI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PosUI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PosUI.dir/clean

CMakeFiles/PosUI.dir/depend:
	cd /Users/pksm1/CLionProjects/PosUI/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/pksm1/CLionProjects/PosUI /Users/pksm1/CLionProjects/PosUI /Users/pksm1/CLionProjects/PosUI/cmake-build-debug /Users/pksm1/CLionProjects/PosUI/cmake-build-debug /Users/pksm1/CLionProjects/PosUI/cmake-build-debug/CMakeFiles/PosUI.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PosUI.dir/depend

