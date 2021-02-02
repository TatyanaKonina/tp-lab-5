//// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_DEANERY_H_
#define INCLUDE_DEANERY_H_
#include <iostream>
#include <thread>
#include <bprinter/table_printer.h>
#include "external/json.hpp"
#include <vector>
#include <zconf.h>
#include "Student.h"
#include "Group.h"

enum STATISTICS {
  FIRE,
  REWARD,
  PUNISH
};

class Deanery {
  friend class Group;
  friend class UniqueID;

 public:
  ~Deanery();
  std::vector<Student *> hireStudents(const std::vector<std::string> &namesFI);
  void createGroups(const std::map<std::string, std::string> &nameGrSp,
                    const std::vector<std::vector<std::string>> &namesFI);
  void addMarksToAll();
  void getStatistics(STATISTICS statistics);
  std::map<std::vector<Student *>, std::string> getStatisticsReward();
  std::map<std::vector<Student *>,
           std::string> getStatisticsPunish();
  std::vector<Student *> getStatisticsFire();
  void moveStudents(const std::vector<Student *> &sts, const std::string &newGr);
  void fireStudents(const std::vector<Student *> &sts);
  Student *initHeads(Group *gr, const std::vector<Student *> &newStudents);
  std::vector<Group *> getGroups();
  void printGroupSize();
  void addMarkToSt(int mark, int stId);
  int getGrsSize();

 private:
  std::vector<Group *> groups;
};

#endif //INCLUDE_DEANERY_H_
