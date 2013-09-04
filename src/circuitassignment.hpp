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

#ifndef CIRCUITASSIGNMENT_HPP_
#define CIRCUITASSIGNMENT_HPP_

#include <vector>
#include "circuit.hpp"
#include "juggler.hpp"
#include "skillset.hpp"


class JugglerMatchscoreCmp {
  Circuit circuit_;
  
public:
  JugglerMatchscoreCmp(const Circuit &circuit)
    : circuit_(circuit)
  {
  }

  bool operator()(Juggler &lhs, Juggler &rhs) const
  {
    return ComputeMatchscore(circuit_.skills(),lhs.skills()) > ComputeMatchscore(circuit_.skills(), rhs.skills());
  }
};

class CircuitAssignment {
  JugglerMatchscoreCmp juggler_matchscore_cmp_;
  Circuit circuit_;
  int size_;
  std::vector<Juggler> jugglers_;
public:
  CircuitAssignment(const Circuit &circuit, int size) 
    : juggler_matchscore_cmp_(circuit), circuit_(circuit), size_(size)
  {}
  
  Circuit circuit() const
  {
    return circuit_;
  }

  bool HasSpace() const
  {
    return jugglers_.size() < size_;
  }

  std::vector<Juggler> jugglers() const
  {
    return jugglers_;
  }
  
  Skillset::Rating GetWorstMatchscore() const
  {
    return ComputeMatchscore(circuit_.skills(), jugglers_.front().skills());
  }
  
  void RegisterJuggler(const Juggler &juggler);

  Juggler DeregisterWorstMatchedJuggler();

  friend std::ostream &operator<<(std::ostream &out, 
				  const CircuitAssignment &circuit_assignment);
    
};
#endif // CIRCUITASSIGNMENT_HPP_
