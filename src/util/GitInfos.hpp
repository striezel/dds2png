/*
 -------------------------------------------------------------------------------
    This file is part of dds2png.
    Copyright (C) 2017, 2021  Dirk Stolle

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

#ifndef DDS2PNG_GITINFOS_HPP
#define DDS2PNG_GITINFOS_HPP

#include <string>

class GitInfos
{
  public:
    /** \brief Default constructor.
     */
    GitInfos();


    /** \brief Gets the SHA1 hash of the current commit (40 hex digits).
     *
     * \return Returns the SHA1 hash of the current commit.
     */
    const std::string& commit() const;


    /** \brief Gets date of the last commit (e.g. "2017-01-29 14:59:33 +0200").
     *
     * \return Returns the date of the last commit.
     */
    const std::string& date() const;
  private:
    std::string mCommit; /**< commit hash */
    std::string mDate; /**< time of the commit */
}; //class

#endif // DDS2PNG_GITINFOS_HPP
