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
// Jugglefest circuit

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include <ostream>
#include <string>
#include "skillset.hpp"

class Circuit {

  std::string name_;
  Skillset skills_;

public:
  Circuit(std::string name, Skillset::Rating H, Skillset::Rating E, 
	  Skillset::Rating P)
    : name_(name), skills_(H, E, P)
  {}
    std::string name() const {return name_;}
  const Skillset &skills() const {return skills_; }

  void Print(std::ostream &out) const;

  friend std::ostream& operator<< (std::ostream& out, const Circuit &circuit);

};

#endif //CIRCUIT_HPP_
