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

#ifndef DDS2PNG_RETURNCODES_HPP
#define DDS2PNG_RETURNCODES_HPP

namespace dds2png
{

/** \brief exit code for invalid command line parameters */
const int rcInvalidParameter = 1;

/** \brief exit code for I/O-related errors */
const int rcInputOutputError = 2;

/** \brief exit code for when the DevIL runtime version is too old */
const int rcLibraryTooOld = 3;

} // namespace

#endif // DDS2PNG_RETURNCODES_HPP
