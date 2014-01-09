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
// Yodle Careers Jugglefest puzzle solver

#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <set>
#include <map>
#include <iostream>
#include "juggler.hpp"
#include "jugglefestparser.hpp"
#include "jugglefestplanner.hpp"
#include "circuitassignment.hpp"
#include "circuitassignments.hpp"

int main(int argc, char *argv[]) {

  std::ifstream ifs_file;
  ifs_file.open(argv[1]);

  std::list<Circuit> circuits;
  std::list<Juggler> jugglers;
  
  try {
    
    JuggleFestParser::Parse(ifs_file, circuits, jugglers);

  } catch (JuggleFestParser::ParseException e) {

  ifs_file.close();
    std::cout << e.errMsg << std::flush;
    return 1;
  }

  ifs_file.close();

#if DEBUG
  std::copy(circuits.begin(), circuits.end(), std::ostream_iterator<Circuit>(std::cout));
  std::copy(jugglers.begin(), jugglers.end(), std::ostream_iterator<Juggler>(std::cout));
#endif
  
  CircuitAssignments circuit_assignments = 
  JuggleFestPlanner::MakeAssignments(circuits, jugglers);

  print(std::cout, circuit_assignments);

  return 0;
}

