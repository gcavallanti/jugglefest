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
// Data struct to keep track of which jugglers are on a given circuit

#include <algorithm>
#include "circuitassignment.hpp"

void CircuitAssignment::RegisterJuggler(const Juggler &juggler) {

  jugglers_.push_back(juggler);
  std::push_heap(jugglers_.begin(), jugglers_.end(), juggler_matchscore_cmp_);
}

Juggler CircuitAssignment::DeregisterWorstMatchedJuggler() {

  Juggler juggler  = jugglers_.front();

  std::pop_heap(jugglers_.begin(), jugglers_.end(), juggler_matchscore_cmp_);  
  jugglers_.pop_back();
  
  return juggler;
}

std::ostream &operator<<(std::ostream &out, const CircuitAssignment &circuit_assignment) {

  out << circuit_assignment.circuit_.name();

  const std::vector<Juggler> &jugglers = circuit_assignment.jugglers_;

  for (std::vector<Juggler>::const_iterator jugglers_it = jugglers.begin();
       jugglers_it != jugglers.end(); jugglers_it++) {

    if (jugglers_it == jugglers.begin())
      out << " ";
    else
      out << ", ";

    out << jugglers_it->name();
  }

  out << std::endl;
}
