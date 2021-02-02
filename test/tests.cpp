////// Copyright 2021 Ozhiganova Polina
#include <gtest/gtest.h>
#include "Student.h"
#include "Group.h"
#include "Deanery.h"
#include "Reader.h"

TEST(Student, check_empty_const) {
Student student;
int rez = 0;
EXPECT_EQ(rez, student.getStId());
}

TEST(Student, check_id_creation) {
  UniqueID *newId = new UniqueID;
  Student student("Mitchel Mia", newId);
  int rez = 1;
  EXPECT_EQ(rez, student.getStId());
}

TEST(Student,check_st_name) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  std::string rez = "Mitchel Mia";
  ASSERT_EQ(rez, student1->getStNamed());
}

TEST(Student, check_st_spec) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  std::string rez = "PI";
  ASSERT_EQ(rez, student1->getStSpec());
}

TEST(Student, check_st_av_mark) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  float rez = 0.0;
  ASSERT_EQ(rez, student1->getAverageMark());
}

TEST(Student, finale_st) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  student1->~Student();
  EXPECT_EQ(0, student1->getStId());
}

TEST(Group, check_gr_head) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  UniqueID *newId2 = new UniqueID;
  Student * student2 = new Student("Greich Mark", newId2);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  newStudents.push_back(student2);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  bool rez = true;
  ASSERT_TRUE(rez, student1->isHeadOfGroup());
}

TEST(Group, check_gr_empty) {
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  Group *newGr = new Group("PI", "1st",
                           newStudents, nullptr);
  bool rez = false;
  ASSERT_TRUE(rez, newGr->isEmpty());
}


TEST(Group, check_sts_size_in_gr) {
  UniqueID *newId1 = new UniqueID;
  Student* student1 = new Student("Mitchel Mia", newId1);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  bool rez = true;
  ASSERT_TRUE(rez, newGr->containStudent(1));
}

TEST(Group, check_gr_spec) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  UniqueID *newId2 = new UniqueID;
  Student * student2 = new Student("Greich Mark", newId2);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  newStudents.push_back(student2);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  std::string rez = "PI";
  ASSERT_EQ(rez, newGr->getSpec());
}

TEST(Group, check_gr_title) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  UniqueID *newId2 = new UniqueID;
  Student * student2 = new Student("Greich Mark", newId2);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  newStudents.push_back(student2);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  std::string rez = "1st";
  ASSERT_EQ(rez, newGr->getTitle());
}

TEST(Group, check_sts_size_in_gr) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  UniqueID *newId2 = new UniqueID;
  Student * student2 = new Student("Greich Mark", newId2);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  newStudents.push_back(student2);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  int rez = 2;
  ASSERT_EQ(rez, newGr->getStudents().size());
}

TEST(Group, check_get_st) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  UniqueID *newId2 = new UniqueID;
  Student * student2 = new Student("Greich Mark", newId2);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  newStudents.push_back(student2);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  std::string rez = "Greich Mark";
  ASSERT_EQ(rez, newGr->getStudent(2)->getStNamed());
}

TEST(Group, check_gr_not_empty) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  UniqueID *newId2 = new UniqueID;
  Student * student2 = new Student("Greich Mark", newId2);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  newStudents.push_back(student2);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  bool rez = false;
  ASSERT_FALSE(rez, newGr->isEmpty());
}

TEST(Group, check_get_st) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  UniqueID *newId2 = new UniqueID;
  Student * student2 = new Student("Greich Mark", newId2);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  newStudents.push_back(student2);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  std::string rez = "Greich Mark";
  ASSERT_EQ(rez, newGr->getStudent(2)->getStNamed());
}

TEST(Deanery, check_empty_dean_size) {
  Deanery* d = new Deanery;
  int rez = 0;
  ASSERT_EQ(rez, d->getGrsSize());
}

TEST(Deanery, check_groups_creation) {
  Reader *r = new Reader;
  std::ifstream f("groups.json");
  nlohmann::json jf = nlohmann::json::parse(f);
  f.close();
  std::map<std::string, std::string> nameGrSp = r->parseGrSp(jf);
  std::vector<std::vector<std::string>> namesFI = r->parseFI(jf);
  Deanery *d = new Deanery;
  d->createGroups(nameGrSp, namesFI);
  int rez = 3;
  ASSERT_EQ(rez, d->getGrsSize());
}
