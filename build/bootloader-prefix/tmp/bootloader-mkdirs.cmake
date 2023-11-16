# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/Espressif/frameworks/esp-idf-v5.0.2/components/bootloader/subproject"
  "D:/Espressif/workspace/TestingPJ/build/bootloader"
  "D:/Espressif/workspace/TestingPJ/build/bootloader-prefix"
  "D:/Espressif/workspace/TestingPJ/build/bootloader-prefix/tmp"
  "D:/Espressif/workspace/TestingPJ/build/bootloader-prefix/src/bootloader-stamp"
  "D:/Espressif/workspace/TestingPJ/build/bootloader-prefix/src"
  "D:/Espressif/workspace/TestingPJ/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Espressif/workspace/TestingPJ/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/Espressif/workspace/TestingPJ/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
