//// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_DEANERY_H_
#define INCLUDE_DEANERY_H_
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
  std::vector<Student *> hireStudents(const std::vector<std::string> &namesFI); //создание студентов на основе данных из файла
  void createGroups(const std::map<std::string, std::string> &nameGrSp,
                    const std::vector<std::vector<std::string>> &namesFI); //   создание групп на основе данных из файла
  void addMarksToAll(); //добавление случайных оценок студентам
  void getStatistics(STATISTICS statistics);
  std::map<std::vector<Student *>,
           std::string> getStatisticsMove(); //получение статистики по успеваемости студентов и групп
  std::vector<Student *> getStatisticsFire();
//  void moveStudents(const std::map<std::vector<Student *>,
//                                   std::string> &stsToGr); //   перевод студентов из группы в группу
  void moveStudents(const std::vector<Student *>& sts, const std::string& newGr);
  void fireStudents(const std::vector<Student *> &sts);//   отчисление студентов за неуспеваемость
  void saveStaff(); //   сохранение обновленных данных в файлах
  Student *initHeads(Group *gr, const std::vector<Student *> &newStudents);  // инициация выборов старост в группах
  std::vector<Group *> getGroups();

 private:
  std::vector<Group *> groups; // - массив групп
};

#endif //INCLUDE_DEANERY_H_
