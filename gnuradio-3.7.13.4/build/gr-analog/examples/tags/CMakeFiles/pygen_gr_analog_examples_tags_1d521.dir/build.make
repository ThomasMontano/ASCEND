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

# Utility rule file for pygen_gr_analog_examples_tags_1d521.

# Include the progress variables for this target.
include gr-analog/examples/tags/CMakeFiles/pygen_gr_analog_examples_tags_1d521.dir/progress.make

gr-analog/examples/tags/CMakeFiles/pygen_gr_analog_examples_tags_1d521: gr-analog/examples/tags/uhd_burst_detector.py.exe


gr-analog/examples/tags/uhd_burst_detector.py.exe: ../gr-analog/examples/tags/uhd_burst_detector.py
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/udooer/Downloads/gnuradio-3.7.13.4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Shebangin uhd_burst_detector.py"
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-analog/examples/tags && /usr/bin/python2 -c "import re; R=re.compile('^#!.*\$$\\n',flags=re.MULTILINE); open('/home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-analog/examples/tags/uhd_burst_detector.py.exe','w').write('#!/usr/bin/python2\\n'+R.sub('',open('/home/udooer/Downloads/gnuradio-3.7.13.4/gr-analog/examples/tags/uhd_burst_detector.py','r').read()))"

pygen_gr_analog_examples_tags_1d521: gr-analog/examples/tags/CMakeFiles/pygen_gr_analog_examples_tags_1d521
pygen_gr_analog_examples_tags_1d521: gr-analog/examples/tags/uhd_burst_detector.py.exe
pygen_gr_analog_examples_tags_1d521: gr-analog/examples/tags/CMakeFiles/pygen_gr_analog_examples_tags_1d521.dir/build.make

.PHONY : pygen_gr_analog_examples_tags_1d521

# Rule to build all files generated by this target.
gr-analog/examples/tags/CMakeFiles/pygen_gr_analog_examples_tags_1d521.dir/build: pygen_gr_analog_examples_tags_1d521

.PHONY : gr-analog/examples/tags/CMakeFiles/pygen_gr_analog_examples_tags_1d521.dir/build

gr-analog/examples/tags/CMakeFiles/pygen_gr_analog_examples_tags_1d521.dir/clean:
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-analog/examples/tags && $(CMAKE_COMMAND) -P CMakeFiles/pygen_gr_analog_examples_tags_1d521.dir/cmake_clean.cmake
.PHONY : gr-analog/examples/tags/CMakeFiles/pygen_gr_analog_examples_tags_1d521.dir/clean

gr-analog/examples/tags/CMakeFiles/pygen_gr_analog_examples_tags_1d521.dir/depend:
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/udooer/Downloads/gnuradio-3.7.13.4 /home/udooer/Downloads/gnuradio-3.7.13.4/gr-analog/examples/tags /home/udooer/Downloads/gnuradio-3.7.13.4/build /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-analog/examples/tags /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-analog/examples/tags/CMakeFiles/pygen_gr_analog_examples_tags_1d521.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : gr-analog/examples/tags/CMakeFiles/pygen_gr_analog_examples_tags_1d521.dir/depend

