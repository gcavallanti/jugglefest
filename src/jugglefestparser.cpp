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
//
// The parsing is implemented through a very simple recursive-descent
// parser.  Both syntactic and semantic (i.e., an error is reported if
// a juggler shows a preference for a non previously listed circuit)
// checks are performed.  The 'semantic actions' simply construct the
// circuits and jugglers lists. A 'symbol table' variable
// (circuit_names) is populated as each circuit line is processed and
// used later for parsing the juggler lines.

#include <sstream>
#include "jugglefestparser.hpp"
#include "types.hpp"

void JuggleFestParser::Parse(std::ifstream &ifs_file, std::list<Circuit> &circuits, std::list<Juggler> &jugglers) {

  std::string line;
  std::set<std::string> circuit_names;

  int i = 0;
  std::getline(ifs_file, line);
  do {
    if ((ifs_file >> std::noskipws >> std::ws) && ifs_file.eof())
      continue;

    std::istringstream iss_line(line);
    char token;
    if ( !(iss_line >> token) || (token != 'C') )
      break;

    Circuit circuit = JuggleFestParser::ParseCircuit(line);
    circuit_names.insert(circuit.name());
    circuits.push_back(circuit);

  } while (std::getline(ifs_file, line));

  do {
    std::istringstream iss_line(line);
    if ((iss_line >> std::noskipws >> std::ws) && iss_line.eof())
      continue;

    Juggler juggler = JuggleFestParser::ParseJuggler(line, circuit_names);
    jugglers.push_back(juggler);

  } while (std::getline(ifs_file, line));
}

Circuit JuggleFestParser::ParseCircuit(std::string &circuit_line) {

  std::istringstream in(circuit_line);
  char token1;
  if ( !(in >> token1) 
       || (token1 != 'C') )
    throw ParseException();

  std::string name;  
  if ( !(in >> name) )
    throw ParseException();

  char token2;
  double H;
  if ( !(in >> token1 >> std::noskipws >> token2 >> H >> std::skipws) 
       || (token1 != 'H')
       || (token2 != ':') )
    throw ParseException();

  double E;
  if ( !(in >> token1 >> std::noskipws >> token2 >> E >> std::skipws)
       || (token1 != 'E')
       || (token2 != ':') )
    throw ParseException();

  double P;
  if ( !(in >> token1 >> std::noskipws >> token2 >> P >> std::skipws)
       || (token1 != 'P')
       || (token2 != ':') )
    throw ParseException();

  if (!(in >> std::noskipws >> std::ws) || !in.eof())
    throw ParseException();

  return Circuit(name, H, E, P);
}

Juggler JuggleFestParser::ParseJuggler(std::string &juggler_line,
				       std::set<std::string> &circuit_names) {

  std::istringstream in(juggler_line);

  char token1;
  if ( !(in >> token1) 
       || (token1 != 'J') )
    throw ParseException();

  std::string name;
  if ( !(in >> name) )
    throw ParseException();

  char token2;
  double H;
  if ( !(in >> token1 >> std::noskipws >> token2 >> H >> std::skipws) 
       || (token1 != 'H')
       || (token2 != ':') )
    throw ParseException();

  double E;
  if ( !(in >> token1 >> std::noskipws >> token2 >> E >> std::skipws)
       || (token1 != 'E')
       || (token2 != ':') )
    throw ParseException();

  double P;
  if ( !(in >> token1 >> std::noskipws >> token2 >> P >> std::skipws)
       || (token1 != 'P')
       || (token2 != ':') )
    throw ParseException();

  std::string field;
  if ( !(in >> field) )
    throw ParseException();

  std::stringstream iss_field(field);
  std::list<std::string> circuit_preferences;
  std::string circuit_name;
  while(std::getline(iss_field, circuit_name, ','))
    if (circuit_names.find(circuit_name) == circuit_names.end())
      throw ParseException();
    else
      circuit_preferences.push_back(circuit_name);

  if (!(in >> std::noskipws >> std::ws) || !in.eof())
    throw ParseException();

  return Juggler(name, H, E, P, circuit_preferences);
}
