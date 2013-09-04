#ifndef JUGGLEFEST_HPP_
#define JUGGLEFEST_HPP_

#include "juggler.hpp"
#include "circuit.hpp"

Rating ComputeMatchscore(const Circuit *circuit, 
			 const Juggler *juggler);

#endif // JUGGLEFEST_HPP_
