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

#ifndef DDS2PNG_VERSION_HPP
#define DDS2PNG_VERSION_HPP

#include <string>

namespace dds2png
{

/** \brief version information */
const std::string version = "version 0.1.0, 2021-02-27";

/** \brief Gets the DevIL version with which the executable was compiled.
 *
 * \return Returns a string containing the version, e. g. "1.2.3".
 */
std::string ilVersionCompiled();

/** \brief Gets the DevIL version that is currently used.
 *
 * \return Returns a string containing the version, e. g. "1.2.3".
 */
std::string ilVersionRuntime();

} // namespace

#endif // DDS2PNG_VERSION_HPP
