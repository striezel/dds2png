/*
 -------------------------------------------------------------------------------
    This file is part of dds2png.
    Copyright (C) 2021  Dirk Stolle

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

#include "Version.hpp"
#include <IL/il.h>

namespace dds2png
{

std::string ilVersionCompiled()
{
  constexpr int major = IL_VERSION / 100;
  constexpr int minor = (IL_VERSION - 100 * major) / 10;
  constexpr int patch = IL_VERSION % 10;
  return std::to_string(major).append(".")
        .append(std::to_string(minor)).append(".")
        .append(std::to_string(patch));
}

std::string ilVersionRuntime()
{
  const ILint runtimeVersion = ilGetInteger(IL_VERSION_NUM);
  const int major = runtimeVersion / 100;
  const int minor = (runtimeVersion - 100 * major) / 10;
  const int patch = runtimeVersion % 10;
  return std::to_string(major).append(".")
        .append(std::to_string(minor)).append(".")
        .append(std::to_string(patch));
}

} // namespace
