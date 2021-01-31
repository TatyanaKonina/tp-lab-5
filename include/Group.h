////// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <string>
#include "Student.h"

class Deanery;
class Group {
  friend class Deanery;
  friend class Student;

 public:
  explicit Group(std::string newTitle,
                 std::string newSpec,
                 const std::vector<Student *> &newStudents,
                 Student *newHead);
  bool containStudent(int stId); // проверка на наличие студента
  Student *getStudent(int stId); //  поиск студента по ФИО или ИД
  float getAverageMark(); //  вычисление соеднего балла в группе
  bool isEmpty();
  std::vector<Student *> getStudents();
  std::string getSpec();

 private:
  std::string title; // название группы
  std::string spec; // специальность
  std::vector<Student *> students;  // - вектор ссылок на студентов
  Student *head = nullptr; // - ссылка на старосту (из членов группы)
  void addStudent(Student *st, Group *gr); //  добавление студента
  Student *chooseHead(const std::vector<Student *> &newStudents); // избрание старосты
  void removeStudent(int stId); // исключение студента из группы
};

#endif //INCLUDE_GROUP_H_
