# dds2png - a DDS to PNG converter

[![GitHub CI Clang status](https://github.com/striezel/dds2png/workflows/Clang/badge.svg)](https://github.com/striezel/dds2png/actions)
[![GitHub CI GCC status](https://github.com/striezel/dds2png/workflows/GCC/badge.svg)](https://github.com/striezel/dds2png/actions)
[![GitHub CI MSYS2 status](https://github.com/striezel/dds2png/workflows/MSYS2/badge.svg)](https://github.com/striezel/dds2png/actions)
[![GitLab pipeline status](https://gitlab.com/striezel/dds2png/badges/master/pipeline.svg)](https://gitlab.com/striezel/dds2png/)

dds2png is a command line tool that converts DDS (DirectDraw Surface) files into
PNG files.

It is still in an early stage of development.

## Building from source

### Prerequisites

To build dds2png from source you need a C++ compiler with support for C++17,
CMake 3.8 or later and the DevIL library. pkg-config is required to make it
easier to find compiler options for the installed libraries.

It also helps to have Git, a distributed version control system, on your build
system to get the latest source code directly from the Git repository.

All of that can usually be installed be typing

    # Debian-based systems
    apt-get install cmake g++ git libdevil-dev pkg-config

into a root terminal.

### Getting the source code

Get the source directly from Git by cloning the Git repository and change to
the directory after the repository is completely cloned:

    git clone https://gitlab.com/striezel/dds2png.git
    cd dds2png

That's it, you should now have the current source code on your machine.

### Build process

The build process is relatively easy, because CMake does all the preparations.
Starting in the root directory of the source, you can do the following steps:

    mkdir build
    cd build
    cmake ../
    make -j4

If you want to run the test suite, too, then there is one more step:

    ctest -V

## Building from source on Windows

For information how to build dds2png on Windows, see the
[build instructions for MSYS2](./documentation/msys2-build.md).

## Usage

    dds2png [OPTIONS]
    dds2png -i file.dds -o file.png

    options:
      -? | --help             - shows this help message
      -v | --version          - shows version information
      -i FILE | --input FILE  - sets the file name of the DDS file to convert.
      -o FILE | --output FILE - sets the file name of the PNG file to produce.

## History of changes

A changelog is available in [changelog.md](./changelog.md).

## Copyright and Licensing

Copyright 2021  Dirk Stolle

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
