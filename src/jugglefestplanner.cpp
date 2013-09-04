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

#include <map>
#include <queue>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include "circuitassignment.hpp"
#include "jugglefestplanner.hpp"
#include "circuitassignments.hpp"

void 
JuggleFestPlanner::PlanAssignments(CircuitAssignments &circuit_assignments, 
				   std::list<Juggler> &jugglers,
				   std::list<std::string> &free_circuit_names) {
  
  std::map<std::string, int> juggler_ranks;
  
  while (!jugglers.empty()) {

    Juggler juggler = jugglers.front();
    jugglers.pop_front();

    bool assigned = false;
    while ( juggler_ranks[juggler.name()] != juggler.preferences().size()) {

      int rank = juggler_ranks[juggler.name()]++;
      std::string circuit_name = juggler.GetPreference(rank);
      
      CircuitAssignment &circuit_assignment = circuit_assignments.find(circuit_name)->second;

      // juggler is assigned to the first favorite (according the its
      // personal ranking) favorite circuit that is not full
      if (circuit_assignment.HasSpace()) {

	circuit_assignment.RegisterJuggler(juggler);
	assigned = true;
	break;
	
      // if juggler is a better match than any of the jugglers that
      // are currently assigned to circuit, assign it to circuit and
      // drop the juggler that has lowest matching score, putting it
      // back on the 'to-assign' juggler list
      } else if (circuit_assignment.GetWorstMatchscore() < 
		 ComputeMatchscore(circuit_assignment.circuit().skills(), juggler.skills()) ) {

	circuit_assignment.RegisterJuggler(juggler);
	Juggler worst_matched_juggler 
	  = circuit_assignment.DeregisterWorstMatchedJuggler();
	jugglers.push_front(worst_matched_juggler);
	assigned = true;
	break;
      } 
    } 

    // juggler couldn't be assigned to any of its favorite circuits so
    // assign it a non full circuit
    if (assigned == false)
      for (std::list<std::string>::iterator iter = free_circuit_names.begin();
	   iter != free_circuit_names.end(); iter++) {
	CircuitAssignment &circuit_assignment = circuit_assignments.find(*iter)->second;
	if (circuit_assignment.HasSpace()) {
	  
	  circuit_assignment.RegisterJuggler(juggler);
	  //break;
	}
      }
  }
}


CircuitAssignments
JuggleFestPlanner::MakeAssignments(const std::list<Circuit> &circuits,
				   const std::list<Juggler> &jugglers) {
  
  int size = jugglers.size() / circuits.size();

  CircuitAssignments circuit_assignments;
  std::list<std::string> free_circuit_names;

  for (std::list<Circuit>::const_iterator circuits_it = circuits.begin();
       circuits_it != circuits.end(); 
       circuits_it++) {  

    const CircuitAssignment &circuit_assignment = CircuitAssignment(*circuits_it, size);
    circuit_assignments.insert(std::make_pair(circuits_it->name(), circuit_assignment));

    free_circuit_names.push_back(circuits_it->name());
  }

  std::list<Juggler> jugglers_queue(jugglers.begin(), jugglers.end());
  PlanAssignments(circuit_assignments, jugglers_queue, free_circuit_names);

  return circuit_assignments;
}
