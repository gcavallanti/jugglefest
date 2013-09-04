// Copyright 2011 Giovanni Cavallanti
// All rights reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// Author: gcavallanti@gmail.com (Giovanni Cavallanti)
//
// Jugglefest juggler

#ifndef JUGGLER_HPP_
#define JUGGLER_HPP_

#include <ostream>
#include <list>
#include <string>
#include "skillset.hpp"

class Juggler {
public:
  typedef std::list<std::string> PreferenceCollection;

private:
  std::string name_;
  Skillset skills_;
  PreferenceCollection preferences_;

public:
  
  Juggler(std::string name, Skillset::Rating H, Skillset::Rating E, 
	  Skillset::Rating P, const PreferenceCollection &preferences)
    : name_(name), skills_(H, E, P), preferences_(preferences)
  {}
  std::string name() const { return name_; } 
  const Skillset &skills() const {return skills_; }
  const PreferenceCollection &preferences() const { return preferences_; }

  const std::string GetPreference(int rank) const {

    Juggler::PreferenceCollection::const_iterator it = preferences_.begin();
    std::advance(it, rank);

    return *it;
  }

  const int GetPreferencesCount() const { return preferences_.size(); }

  void Print(std::ostream &out) const;

  friend std::ostream& operator<< (std::ostream& out, const Juggler &juggler);
};

#endif //JUGGLER_HPP_
