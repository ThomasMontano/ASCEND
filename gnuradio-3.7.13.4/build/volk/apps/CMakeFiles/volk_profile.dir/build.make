# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/udooer/Downloads/gnuradio-3.7.13.4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/udooer/Downloads/gnuradio-3.7.13.4/build

# Include any dependencies generated for this target.
include volk/apps/CMakeFiles/volk_profile.dir/depend.make

# Include the progress variables for this target.
include volk/apps/CMakeFiles/volk_profile.dir/progress.make

# Include the compile flags for this target's objects.
include volk/apps/CMakeFiles/volk_profile.dir/flags.make

volk/apps/CMakeFiles/volk_profile.dir/volk_profile.cc.o: volk/apps/CMakeFiles/volk_profile.dir/flags.make
volk/apps/CMakeFiles/volk_profile.dir/volk_profile.cc.o: ../volk/apps/volk_profile.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/udooer/Downloads/gnuradio-3.7.13.4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object volk/apps/CMakeFiles/volk_profile.dir/volk_profile.cc.o"
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/volk/apps && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/volk_profile.dir/volk_profile.cc.o -c /home/udooer/Downloads/gnuradio-3.7.13.4/volk/apps/volk_profile.cc

volk/apps/CMakeFiles/volk_profile.dir/volk_profile.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/volk_profile.dir/volk_profile.cc.i"
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/volk/apps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/udooer/Downloads/gnuradio-3.7.13.4/volk/apps/volk_profile.cc > CMakeFiles/volk_profile.dir/volk_profile.cc.i

volk/apps/CMakeFiles/volk_profile.dir/volk_profile.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/volk_profile.dir/volk_profile.cc.s"
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/volk/apps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/udooer/Downloads/gnuradio-3.7.13.4/volk/apps/volk_profile.cc -o CMakeFiles/volk_profile.dir/volk_profile.cc.s

volk/apps/CMakeFiles/volk_profile.dir/__/lib/qa_utils.cc.o: volk/apps/CMakeFiles/volk_profile.dir/flags.make
volk/apps/CMakeFiles/volk_profile.dir/__/lib/qa_utils.cc.o: ../volk/lib/qa_utils.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/udooer/Downloads/gnuradio-3.7.13.4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object volk/apps/CMakeFiles/volk_profile.dir/__/lib/qa_utils.cc.o"
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/volk/apps && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/volk_profile.dir/__/lib/qa_utils.cc.o -c /home/udooer/Downloads/gnuradio-3.7.13.4/volk/lib/qa_utils.cc

volk/apps/CMakeFiles/volk_profile.dir/__/lib/qa_utils.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/volk_profile.dir/__/lib/qa_utils.cc.i"
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/volk/apps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/udooer/Downloads/gnuradio-3.7.13.4/volk/lib/qa_utils.cc > CMakeFiles/volk_profile.dir/__/lib/qa_utils.cc.i

volk/apps/CMakeFiles/volk_profile.dir/__/lib/qa_utils.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/volk_profile.dir/__/lib/qa_utils.cc.s"
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/volk/apps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/udooer/Downloads/gnuradio-3.7.13.4/volk/lib/qa_utils.cc -o CMakeFiles/volk_profile.dir/__/lib/qa_utils.cc.s

volk/apps/CMakeFiles/volk_profile.dir/volk_option_helpers.cc.o: volk/apps/CMakeFiles/volk_profile.dir/flags.make
volk/apps/CMakeFiles/volk_profile.dir/volk_option_helpers.cc.o: ../volk/apps/volk_option_helpers.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/udooer/Downloads/gnuradio-3.7.13.4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object volk/apps/CMakeFiles/volk_profile.dir/volk_option_helpers.cc.o"
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/volk/apps && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/volk_profile.dir/volk_option_helpers.cc.o -c /home/udooer/Downloads/gnuradio-3.7.13.4/volk/apps/volk_option_helpers.cc

volk/apps/CMakeFiles/volk_profile.dir/volk_option_helpers.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/volk_profile.dir/volk_option_helpers.cc.i"
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/volk/apps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/udooer/Downloads/gnuradio-3.7.13.4/volk/apps/volk_option_helpers.cc > CMakeFiles/volk_profile.dir/volk_option_helpers.cc.i

volk/apps/CMakeFiles/volk_profile.dir/volk_option_helpers.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/volk_profile.dir/volk_option_helpers.cc.s"
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/volk/apps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/udooer/Downloads/gnuradio-3.7.13.4/volk/apps/volk_option_helpers.cc -o CMakeFiles/volk_profile.dir/volk_option_helpers.cc.s

# Object files for target volk_profile
volk_profile_OBJECTS = \
"CMakeFiles/volk_profile.dir/volk_profile.cc.o" \
"CMakeFiles/volk_profile.dir/__/lib/qa_utils.cc.o" \
"CMakeFiles/volk_profile.dir/volk_option_helpers.cc.o"

# External object files for target volk_profile
volk_profile_EXTERNAL_OBJECTS =

volk/apps/volk_profile: volk/apps/CMakeFiles/volk_profile.dir/volk_profile.cc.o
volk/apps/volk_profile: volk/apps/CMakeFiles/volk_profile.dir/__/lib/qa_utils.cc.o
volk/apps/volk_profile: volk/apps/CMakeFiles/volk_profile.dir/volk_option_helpers.cc.o
volk/apps/volk_profile: volk/apps/CMakeFiles/volk_profile.dir/build.make
volk/apps/volk_profile: volk/lib/libvolk.so.1.4
volk/apps/volk_profile: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
volk/apps/volk_profile: /usr/lib/arm-linux-gnueabihf/libboost_system.so
volk/apps/volk_profile: volk/apps/CMakeFiles/volk_profile.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/udooer/Downloads/gnuradio-3.7.13.4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable volk_profile"
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/volk/apps && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/volk_profile.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
volk/apps/CMakeFiles/volk_profile.dir/build: volk/apps/volk_profile

.PHONY : volk/apps/CMakeFiles/volk_profile.dir/build

volk/apps/CMakeFiles/volk_profile.dir/clean:
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/volk/apps && $(CMAKE_COMMAND) -P CMakeFiles/volk_profile.dir/cmake_clean.cmake
.PHONY : volk/apps/CMakeFiles/volk_profile.dir/clean

volk/apps/CMakeFiles/volk_profile.dir/depend:
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/udooer/Downloads/gnuradio-3.7.13.4 /home/udooer/Downloads/gnuradio-3.7.13.4/volk/apps /home/udooer/Downloads/gnuradio-3.7.13.4/build /home/udooer/Downloads/gnuradio-3.7.13.4/build/volk/apps /home/udooer/Downloads/gnuradio-3.7.13.4/build/volk/apps/CMakeFiles/volk_profile.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : volk/apps/CMakeFiles/volk_profile.dir/depend

