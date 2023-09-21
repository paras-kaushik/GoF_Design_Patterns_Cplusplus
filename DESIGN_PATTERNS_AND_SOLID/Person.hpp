//
//  Person.hpp
//  DESIGN_PATTERNS_AND_SOLID
//
//  Created by Paras Kaushik on 04/08/23.
//

#ifndef Person_h
#define Person_h
#pragma once
#include "headers"

struct Person
{
  std::string name;

  class PersonImpl;
  PersonImpl *impl; // bridge - not necessarily inner class, can vary

  Person();
  ~Person();

  void greet();
};
/*
 The actual behaviour of person is deleted to the bridge
 We are hiding implementation details behind this bridge
 Now whoever is consuming header file does not get exposed to the details of implementation
 **/
#endif /* Person_h */
