# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.11.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.11.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/keita_suzuki/Library/Mobile Documents/com~apple~CloudDocs/Desktop/programs/C/compiler/lexer"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/keita_suzuki/Library/Mobile Documents/com~apple~CloudDocs/Desktop/programs/C/compiler/lexer"

# Include any dependencies generated for this target.
include CMakeFiles/float_rec.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/float_rec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/float_rec.dir/flags.make

CMakeFiles/float_rec.dir/float_rec.c.o: CMakeFiles/float_rec.dir/flags.make
CMakeFiles/float_rec.dir/float_rec.c.o: float_rec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/keita_suzuki/Library/Mobile Documents/com~apple~CloudDocs/Desktop/programs/C/compiler/lexer/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/float_rec.dir/float_rec.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/float_rec.dir/float_rec.c.o   -c "/Users/keita_suzuki/Library/Mobile Documents/com~apple~CloudDocs/Desktop/programs/C/compiler/lexer/float_rec.c"

CMakeFiles/float_rec.dir/float_rec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/float_rec.dir/float_rec.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/keita_suzuki/Library/Mobile Documents/com~apple~CloudDocs/Desktop/programs/C/compiler/lexer/float_rec.c" > CMakeFiles/float_rec.dir/float_rec.c.i

CMakeFiles/float_rec.dir/float_rec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/float_rec.dir/float_rec.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/keita_suzuki/Library/Mobile Documents/com~apple~CloudDocs/Desktop/programs/C/compiler/lexer/float_rec.c" -o CMakeFiles/float_rec.dir/float_rec.c.s

CMakeFiles/float_rec.dir/machine_lib.c.o: CMakeFiles/float_rec.dir/flags.make
CMakeFiles/float_rec.dir/machine_lib.c.o: machine_lib.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/keita_suzuki/Library/Mobile Documents/com~apple~CloudDocs/Desktop/programs/C/compiler/lexer/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/float_rec.dir/machine_lib.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/float_rec.dir/machine_lib.c.o   -c "/Users/keita_suzuki/Library/Mobile Documents/com~apple~CloudDocs/Desktop/programs/C/compiler/lexer/machine_lib.c"

CMakeFiles/float_rec.dir/machine_lib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/float_rec.dir/machine_lib.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/keita_suzuki/Library/Mobile Documents/com~apple~CloudDocs/Desktop/programs/C/compiler/lexer/machine_lib.c" > CMakeFiles/float_rec.dir/machine_lib.c.i

CMakeFiles/float_rec.dir/machine_lib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/float_rec.dir/machine_lib.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/keita_suzuki/Library/Mobile Documents/com~apple~CloudDocs/Desktop/programs/C/compiler/lexer/machine_lib.c" -o CMakeFiles/float_rec.dir/machine_lib.c.s

# Object files for target float_rec
float_rec_OBJECTS = \
"CMakeFiles/float_rec.dir/float_rec.c.o" \
"CMakeFiles/float_rec.dir/machine_lib.c.o"

# External object files for target float_rec
float_rec_EXTERNAL_OBJECTS =

float_rec: CMakeFiles/float_rec.dir/float_rec.c.o
float_rec: CMakeFiles/float_rec.dir/machine_lib.c.o
float_rec: CMakeFiles/float_rec.dir/build.make
float_rec: CMakeFiles/float_rec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/keita_suzuki/Library/Mobile Documents/com~apple~CloudDocs/Desktop/programs/C/compiler/lexer/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable float_rec"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/float_rec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/float_rec.dir/build: float_rec

.PHONY : CMakeFiles/float_rec.dir/build

CMakeFiles/float_rec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/float_rec.dir/cmake_clean.cmake
.PHONY : CMakeFiles/float_rec.dir/clean

CMakeFiles/float_rec.dir/depend:
	cd "/Users/keita_suzuki/Library/Mobile Documents/com~apple~CloudDocs/Desktop/programs/C/compiler/lexer" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/keita_suzuki/Library/Mobile Documents/com~apple~CloudDocs/Desktop/programs/C/compiler/lexer" "/Users/keita_suzuki/Library/Mobile Documents/com~apple~CloudDocs/Desktop/programs/C/compiler/lexer" "/Users/keita_suzuki/Library/Mobile Documents/com~apple~CloudDocs/Desktop/programs/C/compiler/lexer" "/Users/keita_suzuki/Library/Mobile Documents/com~apple~CloudDocs/Desktop/programs/C/compiler/lexer" "/Users/keita_suzuki/Library/Mobile Documents/com~apple~CloudDocs/Desktop/programs/C/compiler/lexer/CMakeFiles/float_rec.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/float_rec.dir/depend
