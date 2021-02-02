// Copyright 2020 Konina Tatiana
#ifndef INCLUDE_DEANERY_H_
#define INCLUDE_DEANERY_H_

#include <vector>
#include <string>
#include<map>

class Group;
class Student;

class Deanery {
 private:
  std::vector<Group*> groups;
  std::map<std::string, int> specList;

 public:
  explicit Deanery(std::string groups_list);
  Deanery(std::string groups_list, std::string st_list);

  void createGroups(std::string input);
  void hireStudent(std::string input);

  void printGroups() const;
  void printStudents() const;

  void addMarksToAll(Group*group) const;
  void updateInfo(std::string output) const;
  bool moveStudent(unsigned int id);
  void getStatistics();
  void initHeads();
  void fireStudents();
  Group* findGroup(std::string spec, int title);
  Student* findStudent(unsigned int id);
};
#endif  // INCLUDE_DEANERY_H_

