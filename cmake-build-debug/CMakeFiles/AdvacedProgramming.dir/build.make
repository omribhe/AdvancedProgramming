# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /snap/clion/178/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/178/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/omri/CLionProjects/Advanced Programming"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/omri/CLionProjects/Advanced Programming/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/AdvacedProgramming.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/AdvacedProgramming.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/AdvacedProgramming.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AdvacedProgramming.dir/flags.make

CMakeFiles/AdvacedProgramming.dir/anomaly_detection_util.cpp.o: CMakeFiles/AdvacedProgramming.dir/flags.make
CMakeFiles/AdvacedProgramming.dir/anomaly_detection_util.cpp.o: ../anomaly_detection_util.cpp
CMakeFiles/AdvacedProgramming.dir/anomaly_detection_util.cpp.o: CMakeFiles/AdvacedProgramming.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/omri/CLionProjects/Advanced Programming/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AdvacedProgramming.dir/anomaly_detection_util.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AdvacedProgramming.dir/anomaly_detection_util.cpp.o -MF CMakeFiles/AdvacedProgramming.dir/anomaly_detection_util.cpp.o.d -o CMakeFiles/AdvacedProgramming.dir/anomaly_detection_util.cpp.o -c "/home/omri/CLionProjects/Advanced Programming/anomaly_detection_util.cpp"

CMakeFiles/AdvacedProgramming.dir/anomaly_detection_util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AdvacedProgramming.dir/anomaly_detection_util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/omri/CLionProjects/Advanced Programming/anomaly_detection_util.cpp" > CMakeFiles/AdvacedProgramming.dir/anomaly_detection_util.cpp.i

CMakeFiles/AdvacedProgramming.dir/anomaly_detection_util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AdvacedProgramming.dir/anomaly_detection_util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/omri/CLionProjects/Advanced Programming/anomaly_detection_util.cpp" -o CMakeFiles/AdvacedProgramming.dir/anomaly_detection_util.cpp.s

CMakeFiles/AdvacedProgramming.dir/timeseries.cpp.o: CMakeFiles/AdvacedProgramming.dir/flags.make
CMakeFiles/AdvacedProgramming.dir/timeseries.cpp.o: ../timeseries.cpp
CMakeFiles/AdvacedProgramming.dir/timeseries.cpp.o: CMakeFiles/AdvacedProgramming.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/omri/CLionProjects/Advanced Programming/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AdvacedProgramming.dir/timeseries.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AdvacedProgramming.dir/timeseries.cpp.o -MF CMakeFiles/AdvacedProgramming.dir/timeseries.cpp.o.d -o CMakeFiles/AdvacedProgramming.dir/timeseries.cpp.o -c "/home/omri/CLionProjects/Advanced Programming/timeseries.cpp"

CMakeFiles/AdvacedProgramming.dir/timeseries.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AdvacedProgramming.dir/timeseries.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/omri/CLionProjects/Advanced Programming/timeseries.cpp" > CMakeFiles/AdvacedProgramming.dir/timeseries.cpp.i

CMakeFiles/AdvacedProgramming.dir/timeseries.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AdvacedProgramming.dir/timeseries.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/omri/CLionProjects/Advanced Programming/timeseries.cpp" -o CMakeFiles/AdvacedProgramming.dir/timeseries.cpp.s

CMakeFiles/AdvacedProgramming.dir/SimpleAnomalyDetector.cpp.o: CMakeFiles/AdvacedProgramming.dir/flags.make
CMakeFiles/AdvacedProgramming.dir/SimpleAnomalyDetector.cpp.o: ../SimpleAnomalyDetector.cpp
CMakeFiles/AdvacedProgramming.dir/SimpleAnomalyDetector.cpp.o: CMakeFiles/AdvacedProgramming.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/omri/CLionProjects/Advanced Programming/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AdvacedProgramming.dir/SimpleAnomalyDetector.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AdvacedProgramming.dir/SimpleAnomalyDetector.cpp.o -MF CMakeFiles/AdvacedProgramming.dir/SimpleAnomalyDetector.cpp.o.d -o CMakeFiles/AdvacedProgramming.dir/SimpleAnomalyDetector.cpp.o -c "/home/omri/CLionProjects/Advanced Programming/SimpleAnomalyDetector.cpp"

CMakeFiles/AdvacedProgramming.dir/SimpleAnomalyDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AdvacedProgramming.dir/SimpleAnomalyDetector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/omri/CLionProjects/Advanced Programming/SimpleAnomalyDetector.cpp" > CMakeFiles/AdvacedProgramming.dir/SimpleAnomalyDetector.cpp.i

CMakeFiles/AdvacedProgramming.dir/SimpleAnomalyDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AdvacedProgramming.dir/SimpleAnomalyDetector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/omri/CLionProjects/Advanced Programming/SimpleAnomalyDetector.cpp" -o CMakeFiles/AdvacedProgramming.dir/SimpleAnomalyDetector.cpp.s

CMakeFiles/AdvacedProgramming.dir/minCircle.cpp.o: CMakeFiles/AdvacedProgramming.dir/flags.make
CMakeFiles/AdvacedProgramming.dir/minCircle.cpp.o: ../minCircle.cpp
CMakeFiles/AdvacedProgramming.dir/minCircle.cpp.o: CMakeFiles/AdvacedProgramming.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/omri/CLionProjects/Advanced Programming/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AdvacedProgramming.dir/minCircle.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AdvacedProgramming.dir/minCircle.cpp.o -MF CMakeFiles/AdvacedProgramming.dir/minCircle.cpp.o.d -o CMakeFiles/AdvacedProgramming.dir/minCircle.cpp.o -c "/home/omri/CLionProjects/Advanced Programming/minCircle.cpp"

CMakeFiles/AdvacedProgramming.dir/minCircle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AdvacedProgramming.dir/minCircle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/omri/CLionProjects/Advanced Programming/minCircle.cpp" > CMakeFiles/AdvacedProgramming.dir/minCircle.cpp.i

CMakeFiles/AdvacedProgramming.dir/minCircle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AdvacedProgramming.dir/minCircle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/omri/CLionProjects/Advanced Programming/minCircle.cpp" -o CMakeFiles/AdvacedProgramming.dir/minCircle.cpp.s

CMakeFiles/AdvacedProgramming.dir/HybridAnomalyDetector.cpp.o: CMakeFiles/AdvacedProgramming.dir/flags.make
CMakeFiles/AdvacedProgramming.dir/HybridAnomalyDetector.cpp.o: ../HybridAnomalyDetector.cpp
CMakeFiles/AdvacedProgramming.dir/HybridAnomalyDetector.cpp.o: CMakeFiles/AdvacedProgramming.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/omri/CLionProjects/Advanced Programming/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/AdvacedProgramming.dir/HybridAnomalyDetector.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AdvacedProgramming.dir/HybridAnomalyDetector.cpp.o -MF CMakeFiles/AdvacedProgramming.dir/HybridAnomalyDetector.cpp.o.d -o CMakeFiles/AdvacedProgramming.dir/HybridAnomalyDetector.cpp.o -c "/home/omri/CLionProjects/Advanced Programming/HybridAnomalyDetector.cpp"

CMakeFiles/AdvacedProgramming.dir/HybridAnomalyDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AdvacedProgramming.dir/HybridAnomalyDetector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/omri/CLionProjects/Advanced Programming/HybridAnomalyDetector.cpp" > CMakeFiles/AdvacedProgramming.dir/HybridAnomalyDetector.cpp.i

CMakeFiles/AdvacedProgramming.dir/HybridAnomalyDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AdvacedProgramming.dir/HybridAnomalyDetector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/omri/CLionProjects/Advanced Programming/HybridAnomalyDetector.cpp" -o CMakeFiles/AdvacedProgramming.dir/HybridAnomalyDetector.cpp.s

CMakeFiles/AdvacedProgramming.dir/CLI.cpp.o: CMakeFiles/AdvacedProgramming.dir/flags.make
CMakeFiles/AdvacedProgramming.dir/CLI.cpp.o: ../CLI.cpp
CMakeFiles/AdvacedProgramming.dir/CLI.cpp.o: CMakeFiles/AdvacedProgramming.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/omri/CLionProjects/Advanced Programming/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/AdvacedProgramming.dir/CLI.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AdvacedProgramming.dir/CLI.cpp.o -MF CMakeFiles/AdvacedProgramming.dir/CLI.cpp.o.d -o CMakeFiles/AdvacedProgramming.dir/CLI.cpp.o -c "/home/omri/CLionProjects/Advanced Programming/CLI.cpp"

CMakeFiles/AdvacedProgramming.dir/CLI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AdvacedProgramming.dir/CLI.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/omri/CLionProjects/Advanced Programming/CLI.cpp" > CMakeFiles/AdvacedProgramming.dir/CLI.cpp.i

CMakeFiles/AdvacedProgramming.dir/CLI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AdvacedProgramming.dir/CLI.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/omri/CLionProjects/Advanced Programming/CLI.cpp" -o CMakeFiles/AdvacedProgramming.dir/CLI.cpp.s

CMakeFiles/AdvacedProgramming.dir/MainTrain.cpp.o: CMakeFiles/AdvacedProgramming.dir/flags.make
CMakeFiles/AdvacedProgramming.dir/MainTrain.cpp.o: ../MainTrain.cpp
CMakeFiles/AdvacedProgramming.dir/MainTrain.cpp.o: CMakeFiles/AdvacedProgramming.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/omri/CLionProjects/Advanced Programming/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/AdvacedProgramming.dir/MainTrain.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AdvacedProgramming.dir/MainTrain.cpp.o -MF CMakeFiles/AdvacedProgramming.dir/MainTrain.cpp.o.d -o CMakeFiles/AdvacedProgramming.dir/MainTrain.cpp.o -c "/home/omri/CLionProjects/Advanced Programming/MainTrain.cpp"

CMakeFiles/AdvacedProgramming.dir/MainTrain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AdvacedProgramming.dir/MainTrain.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/omri/CLionProjects/Advanced Programming/MainTrain.cpp" > CMakeFiles/AdvacedProgramming.dir/MainTrain.cpp.i

CMakeFiles/AdvacedProgramming.dir/MainTrain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AdvacedProgramming.dir/MainTrain.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/omri/CLionProjects/Advanced Programming/MainTrain.cpp" -o CMakeFiles/AdvacedProgramming.dir/MainTrain.cpp.s

CMakeFiles/AdvacedProgramming.dir/Server.cpp.o: CMakeFiles/AdvacedProgramming.dir/flags.make
CMakeFiles/AdvacedProgramming.dir/Server.cpp.o: ../Server.cpp
CMakeFiles/AdvacedProgramming.dir/Server.cpp.o: CMakeFiles/AdvacedProgramming.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/omri/CLionProjects/Advanced Programming/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/AdvacedProgramming.dir/Server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AdvacedProgramming.dir/Server.cpp.o -MF CMakeFiles/AdvacedProgramming.dir/Server.cpp.o.d -o CMakeFiles/AdvacedProgramming.dir/Server.cpp.o -c "/home/omri/CLionProjects/Advanced Programming/Server.cpp"

CMakeFiles/AdvacedProgramming.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AdvacedProgramming.dir/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/omri/CLionProjects/Advanced Programming/Server.cpp" > CMakeFiles/AdvacedProgramming.dir/Server.cpp.i

CMakeFiles/AdvacedProgramming.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AdvacedProgramming.dir/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/omri/CLionProjects/Advanced Programming/Server.cpp" -o CMakeFiles/AdvacedProgramming.dir/Server.cpp.s

# Object files for target AdvacedProgramming
AdvacedProgramming_OBJECTS = \
"CMakeFiles/AdvacedProgramming.dir/anomaly_detection_util.cpp.o" \
"CMakeFiles/AdvacedProgramming.dir/timeseries.cpp.o" \
"CMakeFiles/AdvacedProgramming.dir/SimpleAnomalyDetector.cpp.o" \
"CMakeFiles/AdvacedProgramming.dir/minCircle.cpp.o" \
"CMakeFiles/AdvacedProgramming.dir/HybridAnomalyDetector.cpp.o" \
"CMakeFiles/AdvacedProgramming.dir/CLI.cpp.o" \
"CMakeFiles/AdvacedProgramming.dir/MainTrain.cpp.o" \
"CMakeFiles/AdvacedProgramming.dir/Server.cpp.o"

# External object files for target AdvacedProgramming
AdvacedProgramming_EXTERNAL_OBJECTS =

AdvacedProgramming: CMakeFiles/AdvacedProgramming.dir/anomaly_detection_util.cpp.o
AdvacedProgramming: CMakeFiles/AdvacedProgramming.dir/timeseries.cpp.o
AdvacedProgramming: CMakeFiles/AdvacedProgramming.dir/SimpleAnomalyDetector.cpp.o
AdvacedProgramming: CMakeFiles/AdvacedProgramming.dir/minCircle.cpp.o
AdvacedProgramming: CMakeFiles/AdvacedProgramming.dir/HybridAnomalyDetector.cpp.o
AdvacedProgramming: CMakeFiles/AdvacedProgramming.dir/CLI.cpp.o
AdvacedProgramming: CMakeFiles/AdvacedProgramming.dir/MainTrain.cpp.o
AdvacedProgramming: CMakeFiles/AdvacedProgramming.dir/Server.cpp.o
AdvacedProgramming: CMakeFiles/AdvacedProgramming.dir/build.make
AdvacedProgramming: CMakeFiles/AdvacedProgramming.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/omri/CLionProjects/Advanced Programming/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable AdvacedProgramming"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AdvacedProgramming.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AdvacedProgramming.dir/build: AdvacedProgramming
.PHONY : CMakeFiles/AdvacedProgramming.dir/build

CMakeFiles/AdvacedProgramming.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AdvacedProgramming.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AdvacedProgramming.dir/clean

CMakeFiles/AdvacedProgramming.dir/depend:
	cd "/home/omri/CLionProjects/Advanced Programming/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/omri/CLionProjects/Advanced Programming" "/home/omri/CLionProjects/Advanced Programming" "/home/omri/CLionProjects/Advanced Programming/cmake-build-debug" "/home/omri/CLionProjects/Advanced Programming/cmake-build-debug" "/home/omri/CLionProjects/Advanced Programming/cmake-build-debug/CMakeFiles/AdvacedProgramming.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/AdvacedProgramming.dir/depend

