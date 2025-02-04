# Copyright 2013 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.

set(MAJOR_VERSION 3)
set(API_COMPAT 7)
set(MINOR_VERSION 13)
set(MAINT_VERSION 4)

set(PACKAGE_VERSION
  ${MAJOR_VERSION}.${API_COMPAT}.${MINOR_VERSION}.${MAINT_VERSION})

if(${PACKAGE_FIND_VERSION_MAJOR} EQUAL ${MAJOR_VERSION})
  if(${PACKAGE_FIND_VERSION_MINOR} EQUAL ${API_COMPAT})
    if(NOT ${PACKAGE_FIND_VERSION_PATCH} GREATER ${MINOR_VERSION})
      set(PACKAGE_VERSION_EXACT 1)    # exact match for API version
      set(PACKAGE_VERSION_COMPATIBLE 1)  # compat for minor/patch version
    endif(NOT ${PACKAGE_FIND_VERSION_PATCH} GREATER ${MINOR_VERSION})
  endif(${PACKAGE_FIND_VERSION_MINOR} EQUAL ${API_COMPAT})
endif(${PACKAGE_FIND_VERSION_MAJOR} EQUAL ${MAJOR_VERSION})
