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
// Jugglers-to-circuits assignment logic

#ifndef JUGGLERFESTPLANNER_HPP_
#define JUGGLERFESTPLANNER_HPP_

#include <vector>
#include <queue>
#include "juggler.hpp"
#include "circuit.hpp"
#include "circuitassignment.hpp"
#include "circuitassignments.hpp"

namespace JuggleFestPlanner {

  void PlanAssignments(CircuitAssignments &circuit_assignments, 
		       std::list<Juggler> &jugglers,
		       std::list<std::string> &free_circuit_names);
  

  CircuitAssignments  MakeAssignments(const std::list<Circuit> &circuits,
				      const std::list<Juggler> &jugglers);
}
#endif // JUGGLERFESTPLANNER_HPP_
