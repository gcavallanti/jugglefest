#include <ostream>
#include "circuitassignments.hpp"

void print(std::ostream& out, const std::map<std::string, CircuitAssignment> &circuit_assignments)  {

  for (std::map<std::string, CircuitAssignment>::const_iterator 
	 it = circuit_assignments.begin();
       it != circuit_assignments.end(); it++) {
   
    std::string circuit_name = it->first;
    CircuitAssignment circuit_assignment =  it->second;
    out << circuit_name << ' ';

    std::vector<Juggler> jugglers = circuit_assignment.jugglers();
    for (std::vector<Juggler>::const_iterator jugglers_it = jugglers.begin();
    	 jugglers_it != jugglers.end(); jugglers_it++) {

      if (jugglers_it != jugglers.begin())
	out << ',';

      out << jugglers_it->name() << ' ';

      for (int rank = 0; rank < jugglers_it->GetPreferencesCount(); rank++) {

	std::string preference = jugglers_it->GetPreference(rank);
	if (rank != 0)
	  out << ' ';
	out << preference << ':';

      	std::map<std::string, CircuitAssignment>::const_iterator 
      	  circuit_assignments_it = 
      	  circuit_assignments.find(preference);
      	Circuit circuit = circuit_assignments_it->second.circuit();
      	out << ComputeMatchscore(circuit.skills(), jugglers_it->skills());	
      }
    }
    out << std::endl;
  }
}
