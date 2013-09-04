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
// Input data parser 

#ifndef JUGGLERFESTPARSER_HPP_
#define JUGGLERFESTPARSER_HPP_

#include <set>
#include <fstream>
#include "types.hpp"
#include "circuit.hpp"
#include "juggler.hpp"

namespace JuggleFestParser {

  struct ParseException {};
  
  void Parse(std::ifstream &ifs_file, std::list<Circuit> &circuits, std::list<Juggler> &jugglers);
  Circuit ParseCircuit(std::string &circuit_line);
  Juggler ParseJuggler(std::string &juggler_line,
		       std::set<std::string> &circuit_names);
};

#endif // JUGGLERFESTPARSER_HPP_
