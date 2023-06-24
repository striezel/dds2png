/*
 -------------------------------------------------------------------------------
    This file is part of dds2png.
    Copyright (C) 2021, 2022  Dirk Stolle

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
 -------------------------------------------------------------------------------
*/

#include <filesystem>
#include <iostream>
#include "ReturnCodes.hpp"
#include "Version.hpp"
#include "util/GitInfos.hpp"
#include <IL/il.h>

void showVersion()
{
  GitInfos info;
  std::cout << "dds2png, " << dds2png::version << "\n"
            << "\n"
            << "Version control commit:  " << info.commit() << "\n"
            << "Version control date:    " << info.date() << "\n"
            << "IL version (build time): " << dds2png::ilVersionCompiled() << "\n"
            << "IL version (current):    " << dds2png::ilVersionRuntime() << std::endl;
}

void showHelp()
{
  std::cout << "dds2png [OPTIONS]\n"
            << "dds2png -i file.dds -o file.png\n"
            << "\n"
            << "options:\n"
            << "  -? | --help             - shows this help message\n"
            << "  -v | --version          - shows version information\n"
            << "  -i FILE | --input FILE  - sets the file name of the DDS file to convert.\n"
            << "  -o FILE | --output FILE - sets the file name of the PNG file to produce.\n";
}

int main(int argc, char** argv)
{
  namespace fs = std::filesystem;

  std::string ddsFile;
  std::string pngFile;

  if ((argc > 1) && (argv != nullptr))
  {
    for (int i = 1; i < argc; ++i)
    {
      if (argv[i] == nullptr)
      {
        std::cerr << "Error: Parameter at index " << i << " is null pointer!\n";
        return dds2png::rcInvalidParameter;
      }
      const std::string param(argv[i]);
      if ((param == "-v") || (param == "--version"))
      {
        showVersion();
        return 0;
      } // if version
      else if ((param == "-?") || (param == "/?") || (param == "--help"))
      {
        showHelp();
        return 0;
      } // if help
      else if ((param == "--input") || (param == "-i"))
      {
        if (!ddsFile.empty())
        {
          std::cerr << "Error: Input file was already set to "
                    << ddsFile << "!" << std::endl;
          return dds2png::rcInvalidParameter;
        }
        // enough parameters?
        if ((i+1 < argc) && (argv[i+1] != nullptr))
        {
          ddsFile = std::string(argv[i+1]);
          // Skip next parameter, because it's already used as file path.
          ++i;
        }
        else
        {
          std::cerr << "Error: You have to enter a file path after \""
                    << param << "\"." << std::endl;
          return dds2png::rcInvalidParameter;
        }
      } // if input file
      else if ((param == "--ouput") || (param == "-o"))
      {
        if (!pngFile.empty())
        {
          std::cerr << "Error: Output file was already set to "
                    << pngFile << "!" << std::endl;
          return dds2png::rcInvalidParameter;
        }
        // enough parameters?
        if ((i+1 < argc) && (argv[i+1] != nullptr))
        {
          pngFile = std::string(argv[i+1]);
          // Skip next parameter, because it's already used as file path.
          ++i;
        }
        else
        {
          std::cerr << "Error: You have to enter a file path after \""
                    << param << "\"." << std::endl;
          return dds2png::rcInvalidParameter;
        }
      } // if output file
      else
      {
        std::cerr << "Error: Unknown parameter " << param << "!\n"
                  << "Use --help to show available parameters." << std::endl;
        return dds2png::rcInvalidParameter;
      }
    } // for i
  } // if arguments are there

  if (ddsFile.empty())
  {
    std::cerr << "Error: No input file is specified." << std::endl;
    return dds2png::rcInvalidParameter;
  }
  if (pngFile.empty())
  {
    std::cerr << "Error: No output file is specified." << std::endl;
    return dds2png::rcInvalidParameter;
  }

  fs::path input { ddsFile };
  fs::path output { pngFile };
  if (!fs::exists(input) || !fs::is_regular_file(input))
  {
    std::cerr << "Error: " << ddsFile << " does not exist or is not a regular file!"
              << std::endl;
    return dds2png::rcInputOutputError;
  }
  if (fs::exists(output))
  {
    std::cerr << "Error: " << pngFile << " already exists!" << std::endl;
    return dds2png::rcInputOutputError;
  }

  ilInit();
  // Make sure this is not running with a version of IL that might be too old.
  if (ilGetInteger(IL_VERSION_NUM) < IL_VERSION)
  {
    std::cerr << "Error: The library DevIL is too old! Version "
              << dds2png::ilVersionRuntime() << " was found, but at least "
              << dds2png::ilVersionCompiled() << " is required." << std::endl;
    return dds2png::rcLibraryTooOld;
  }

  const ILuint imageName = ilGenImage();
  ilBindImage(imageName);
  const auto input_as_string = input.string();
  const ILboolean loadSuccess = ilLoad(IL_DDS, input_as_string.c_str());
  if (!loadSuccess)
  {
    std::cerr << "Error: Failed to load DDS from " << ddsFile << "!" << std::endl;
    ilDeleteImage(imageName);
    return dds2png::rcInputOutputError;
  }
  const ILboolean saveSuccess = ilSave(IL_PNG, pngFile.c_str());
  ilDeleteImage(imageName);
  if (!saveSuccess)
  {
    std::cerr << "Error: Failed to save PNG to " << pngFile << "!" << std::endl;
    return dds2png::rcInputOutputError;
  }

  // Done.
  return 0;
}
