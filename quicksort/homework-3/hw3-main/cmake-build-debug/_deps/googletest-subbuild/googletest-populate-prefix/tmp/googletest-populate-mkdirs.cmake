# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/code/C++_quicksort/hw3-main/hw3-main/cmake-build-debug/_deps/googletest-src"
  "D:/code/C++_quicksort/hw3-main/hw3-main/cmake-build-debug/_deps/googletest-build"
  "D:/code/C++_quicksort/hw3-main/hw3-main/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "D:/code/C++_quicksort/hw3-main/hw3-main/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "D:/code/C++_quicksort/hw3-main/hw3-main/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "D:/code/C++_quicksort/hw3-main/hw3-main/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "D:/code/C++_quicksort/hw3-main/hw3-main/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/code/C++_quicksort/hw3-main/hw3-main/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
