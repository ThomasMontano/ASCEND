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
include gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/depend.make

# Include the progress variables for this target.
include gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/progress.make

# Include the compile flags for this target's objects.
include gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/flags.make

gr-video-sdl/swig/video_sdl_swigPYTHON_wrap.cxx: gr-video-sdl/swig/video_sdl_swig_gr_video_sdl_swig_512fd
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/udooer/Downloads/gnuradio-3.7.13.4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "dummy command to show video_sdl_swig_gr_video_sdl_swig_512fd dependency of /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-video-sdl/swig/video_sdl_swigPYTHON_wrap.cxx"
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-video-sdl/swig && /usr/local/bin/cmake -E touch_nocreate /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-video-sdl/swig/video_sdl_swigPYTHON_wrap.cxx

gr-video-sdl/swig/video_sdl_swig.py: gr-video-sdl/swig/video_sdl_swig_gr_video_sdl_swig_512fd
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/udooer/Downloads/gnuradio-3.7.13.4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "dummy command to show video_sdl_swig_gr_video_sdl_swig_512fd dependency of /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-video-sdl/swig/video_sdl_swig.py"
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-video-sdl/swig && /usr/local/bin/cmake -E touch_nocreate /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-video-sdl/swig/video_sdl_swig.py

gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/video_sdl_swigPYTHON_wrap.cxx.o: gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/flags.make
gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/video_sdl_swigPYTHON_wrap.cxx.o: gr-video-sdl/swig/video_sdl_swigPYTHON_wrap.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/udooer/Downloads/gnuradio-3.7.13.4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/video_sdl_swigPYTHON_wrap.cxx.o"
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-video-sdl/swig && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-unused-but-set-variable -o CMakeFiles/_video_sdl_swig.dir/video_sdl_swigPYTHON_wrap.cxx.o -c /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-video-sdl/swig/video_sdl_swigPYTHON_wrap.cxx

gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/video_sdl_swigPYTHON_wrap.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_video_sdl_swig.dir/video_sdl_swigPYTHON_wrap.cxx.i"
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-video-sdl/swig && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-unused-but-set-variable -E /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-video-sdl/swig/video_sdl_swigPYTHON_wrap.cxx > CMakeFiles/_video_sdl_swig.dir/video_sdl_swigPYTHON_wrap.cxx.i

gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/video_sdl_swigPYTHON_wrap.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_video_sdl_swig.dir/video_sdl_swigPYTHON_wrap.cxx.s"
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-video-sdl/swig && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-unused-but-set-variable -S /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-video-sdl/swig/video_sdl_swigPYTHON_wrap.cxx -o CMakeFiles/_video_sdl_swig.dir/video_sdl_swigPYTHON_wrap.cxx.s

# Object files for target _video_sdl_swig
_video_sdl_swig_OBJECTS = \
"CMakeFiles/_video_sdl_swig.dir/video_sdl_swigPYTHON_wrap.cxx.o"

# External object files for target _video_sdl_swig
_video_sdl_swig_EXTERNAL_OBJECTS =

gr-video-sdl/swig/_video_sdl_swig.so: gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/video_sdl_swigPYTHON_wrap.cxx.o
gr-video-sdl/swig/_video_sdl_swig.so: gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/build.make
gr-video-sdl/swig/_video_sdl_swig.so: /usr/lib/arm-linux-gnueabihf/libpython2.7.so
gr-video-sdl/swig/_video_sdl_swig.so: gr-video-sdl/lib/libgnuradio-video-sdl-3.7.13.4.so.0.0.0
gr-video-sdl/swig/_video_sdl_swig.so: gnuradio-runtime/lib/libgnuradio-runtime-3.7.13.4.so.0.0.0
gr-video-sdl/swig/_video_sdl_swig.so: gnuradio-runtime/lib/pmt/libgnuradio-pmt-3.7.13.4.so.0.0.0
gr-video-sdl/swig/_video_sdl_swig.so: volk/lib/libvolk.so.1.4
gr-video-sdl/swig/_video_sdl_swig.so: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
gr-video-sdl/swig/_video_sdl_swig.so: /usr/lib/arm-linux-gnueabihf/libboost_program_options.so
gr-video-sdl/swig/_video_sdl_swig.so: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
gr-video-sdl/swig/_video_sdl_swig.so: /usr/lib/arm-linux-gnueabihf/libboost_system.so
gr-video-sdl/swig/_video_sdl_swig.so: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
gr-video-sdl/swig/_video_sdl_swig.so: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
gr-video-sdl/swig/_video_sdl_swig.so: /usr/lib/arm-linux-gnueabihf/libSDLmain.a
gr-video-sdl/swig/_video_sdl_swig.so: /usr/lib/arm-linux-gnueabihf/libSDL.so
gr-video-sdl/swig/_video_sdl_swig.so: /usr/lib/arm-linux-gnueabihf/libboost_chrono.so
gr-video-sdl/swig/_video_sdl_swig.so: /usr/lib/arm-linux-gnueabihf/libboost_atomic.so
gr-video-sdl/swig/_video_sdl_swig.so: gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/udooer/Downloads/gnuradio-3.7.13.4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared module _video_sdl_swig.so"
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-video-sdl/swig && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/_video_sdl_swig.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/build: gr-video-sdl/swig/_video_sdl_swig.so

.PHONY : gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/build

gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/clean:
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-video-sdl/swig && $(CMAKE_COMMAND) -P CMakeFiles/_video_sdl_swig.dir/cmake_clean.cmake
.PHONY : gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/clean

gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/depend: gr-video-sdl/swig/video_sdl_swigPYTHON_wrap.cxx
gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/depend: gr-video-sdl/swig/video_sdl_swig.py
	cd /home/udooer/Downloads/gnuradio-3.7.13.4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/udooer/Downloads/gnuradio-3.7.13.4 /home/udooer/Downloads/gnuradio-3.7.13.4/gr-video-sdl/swig /home/udooer/Downloads/gnuradio-3.7.13.4/build /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-video-sdl/swig /home/udooer/Downloads/gnuradio-3.7.13.4/build/gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : gr-video-sdl/swig/CMakeFiles/_video_sdl_swig.dir/depend

