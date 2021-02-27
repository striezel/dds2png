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

#include "GitInfos.hpp"

GitInfos::GitInfos()
: mCommit(""),
  mDate("")
{
  const std::string git_hash = "@GIT_HASH@";
  const std::string git_time = "@GIT_TIME@";

  if ((git_hash != std::string("@GIT_") + "HASH@") && !git_hash.empty())
    mCommit = git_hash;
  else
    mCommit = "unknown";

  if ((git_time != std::string("@GIT_") + "TIME@") && !git_time.empty())
    mDate = git_time;
  else
    mDate = "unknown";
}

const std::string& GitInfos::commit() const
{
  return mCommit;
}

const std::string& GitInfos::date() const
{
  return mDate;
}
