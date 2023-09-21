//
//  Person.cpp
//  DESIGN_PATTERNS_AND_SOLID
//
//  Created by Paras Kaushik on 04/08/23.
//

//PIMPL (Pointer to Implementation) idiom
//hiding by sticking it into its implementation
#include "Person.h"
//Implementation details are bridged into a separate class
struct Person::PersonImpl
{
  void greet(Person* p);
};

void Person::PersonImpl::greet(Person* p)
{
  printf("hello %s", p->name.c_str());
}

Person::Person()
  : impl(new PersonImpl)
{
}

Person::~Person()
{
  delete impl;
}

void Person::greet()
{
  impl->greet(this);
}


