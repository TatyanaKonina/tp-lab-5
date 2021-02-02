// Copyright 2020 Konina Tatiana
#include "Deanery.h"
#include "Student.h"
#include "Group.h"
#include <iostream>
int main() {
  Deanery* test = new Deanery("specList.txt","students.txt");
  test->initHeads();
  test->fireStudents();
  Group* gr = test->findGroup("Ancient landuages(assembler)", 1);
  std::cout<<gr->getGroupSize();
 
  return 0;
}