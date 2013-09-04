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
// Jugglefest juggler

#include <algorithm>
#include <iterator>
#include "juggler.hpp"

void Juggler::Print(std::ostream &out) const {

  out << "J " << name_ << " H:" << skills_.H() 
      << " E:" << skills_.E() << " P:" << skills_.P();

  for (PreferenceCollection::const_iterator 
  	 preferences_it = preferences_.begin(); 
       preferences_it != preferences_.end(); 
       preferences_it++) {
    if (preferences_it == preferences_.begin())
      out << " ";
    else
      out << ",";
    out << *preferences_it;
  }

  out << std::endl;
}

std::ostream& operator<< (std::ostream& out, const Juggler &juggler) {

  juggler.Print(out);
  
  return out;
}
