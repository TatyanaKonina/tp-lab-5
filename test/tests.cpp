// Copyright 2020 Konina Tatiana

#include <gtest/gtest.h>
#include "Data.h"
#include "Student.h"
#include "Group.h"
#include "Deanary.h"


TEST(st_test, test1) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  Student* st = test->findStudent(2);
  EXPECT_EQ(2, st->getId());
}

TEST(st_test, test2) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  Student* st = test->findStudent(2);

  EXPECT_EQ("Peter Parker", st->getFio());
}

TEST(st_test, test3) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  Student* st = test->findStudent(2);

  EXPECT_EQ(true, st->isHeadOfGroup());
}

TEST(gr_test, test4) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  Group* gr = test->findGroup("Masochist club(algorithms)", 1);
  EXPECT_EQ(4, gr->getGroupSize());
}

TEST(gr_test, test5) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  Group* gr = test->findGroup("Masochist club(algorithms)", 1);
  EXPECT_EQ(4.25, gr->getAverageMarks());
}

TEST(gr_test, test6) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  Group* gr = test->findGroup("Masochist club(algorithms)", 1);
  EXPECT_EQ(-1, gr->getHead());
}
TEST(d_test, test7) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  test->initHeads();
  Group* gr = test->findGroup("Masochist club(algorithms)", 1);
  EXPECT_EQ(5, gr->getHead());
}
TEST(d_test, test8) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  test->initHeads();
  test->fireStudents();
  Group* gr = test->findGroup("Masochist club(algorithms)", 1);
  EXPECT_EQ(5, gr->getGroupSize());
}

TEST(d_test, test9) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  test->initHeads();
  Group* gr = test->findGroup("Ancient landuages(assembler)", 1);
  EXPECT_EQ(2, gr->getHead());
}

TEST(d_test, test10) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  test->initHeads();
  test->fireStudents();
  Group* gr = test->findGroup("Ancient landuages(assembler)", 1);
  EXPECT_EQ(4, gr->getGroupSize());
}

