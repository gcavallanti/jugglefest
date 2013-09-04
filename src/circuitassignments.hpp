#ifndef CIRCUITASSIGNMENTS_HPP_
#define CIRCUITASSIGNMENTS_HPP_

#include <map>
#include <string>
#include <ostream>
#include "circuitassignment.hpp"

typedef std::map<std::string, CircuitAssignment> CircuitAssignments;

void print(std::ostream& out, const std::map<std::string, CircuitAssignment> &circuit_assignments);

#endif //CIRCUITASSIGNMENTS_HPP_
