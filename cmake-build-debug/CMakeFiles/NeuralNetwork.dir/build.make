# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/sebastianlettner/Google Drive/MaschineLearning/NeuralNetworkLib/NeuralNetworkLib"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/sebastianlettner/Google Drive/MaschineLearning/NeuralNetworkLib/NeuralNetworkLib/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/NeuralNetwork.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NeuralNetwork.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NeuralNetwork.dir/flags.make

CMakeFiles/NeuralNetwork.dir/main.c.o: CMakeFiles/NeuralNetwork.dir/flags.make
CMakeFiles/NeuralNetwork.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/sebastianlettner/Google Drive/MaschineLearning/NeuralNetworkLib/NeuralNetworkLib/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/NeuralNetwork.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NeuralNetwork.dir/main.c.o   -c "/Users/sebastianlettner/Google Drive/MaschineLearning/NeuralNetworkLib/NeuralNetworkLib/main.c"

CMakeFiles/NeuralNetwork.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NeuralNetwork.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/sebastianlettner/Google Drive/MaschineLearning/NeuralNetworkLib/NeuralNetworkLib/main.c" > CMakeFiles/NeuralNetwork.dir/main.c.i

CMakeFiles/NeuralNetwork.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NeuralNetwork.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/sebastianlettner/Google Drive/MaschineLearning/NeuralNetworkLib/NeuralNetworkLib/main.c" -o CMakeFiles/NeuralNetwork.dir/main.c.s

CMakeFiles/NeuralNetwork.dir/main.c.o.requires:

.PHONY : CMakeFiles/NeuralNetwork.dir/main.c.o.requires

CMakeFiles/NeuralNetwork.dir/main.c.o.provides: CMakeFiles/NeuralNetwork.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/NeuralNetwork.dir/build.make CMakeFiles/NeuralNetwork.dir/main.c.o.provides.build
.PHONY : CMakeFiles/NeuralNetwork.dir/main.c.o.provides

CMakeFiles/NeuralNetwork.dir/main.c.o.provides.build: CMakeFiles/NeuralNetwork.dir/main.c.o


# Object files for target NeuralNetwork
NeuralNetwork_OBJECTS = \
"CMakeFiles/NeuralNetwork.dir/main.c.o"

# External object files for target NeuralNetwork
NeuralNetwork_EXTERNAL_OBJECTS =

NeuralNetwork: CMakeFiles/NeuralNetwork.dir/main.c.o
NeuralNetwork: CMakeFiles/NeuralNetwork.dir/build.make
NeuralNetwork: CMakeFiles/NeuralNetwork.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/sebastianlettner/Google Drive/MaschineLearning/NeuralNetworkLib/NeuralNetworkLib/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable NeuralNetwork"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NeuralNetwork.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NeuralNetwork.dir/build: NeuralNetwork

.PHONY : CMakeFiles/NeuralNetwork.dir/build

CMakeFiles/NeuralNetwork.dir/requires: CMakeFiles/NeuralNetwork.dir/main.c.o.requires

.PHONY : CMakeFiles/NeuralNetwork.dir/requires

CMakeFiles/NeuralNetwork.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NeuralNetwork.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NeuralNetwork.dir/clean

CMakeFiles/NeuralNetwork.dir/depend:
	cd "/Users/sebastianlettner/Google Drive/MaschineLearning/NeuralNetworkLib/NeuralNetworkLib/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/sebastianlettner/Google Drive/MaschineLearning/NeuralNetworkLib/NeuralNetworkLib" "/Users/sebastianlettner/Google Drive/MaschineLearning/NeuralNetworkLib/NeuralNetworkLib" "/Users/sebastianlettner/Google Drive/MaschineLearning/NeuralNetworkLib/NeuralNetworkLib/cmake-build-debug" "/Users/sebastianlettner/Google Drive/MaschineLearning/NeuralNetworkLib/NeuralNetworkLib/cmake-build-debug" "/Users/sebastianlettner/Google Drive/MaschineLearning/NeuralNetworkLib/NeuralNetworkLib/cmake-build-debug/CMakeFiles/NeuralNetwork.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/NeuralNetwork.dir/depend

