// Copyright 2011, Giovanni Cavallanti
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

#ifndef SKILLSET_HPP_
#define SKILLSET_HPP_

class Skillset {
public:
  typedef int Rating;

private:
  Rating H_;
  Rating E_;
  Rating P_;

public:
  Skillset(Rating H, Rating E, Rating P)
    : H_(H), E_(E), P_(P)
  {}

  Rating H() const { return H_; }
  Rating E() const { return E_; }
  Rating P() const { return P_; }
  
  friend Rating ComputeMatchscore(const Skillset &lhs, const Skillset &rhs);
};

#endif // SKILLSET_HPP_
