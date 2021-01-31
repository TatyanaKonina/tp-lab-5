////// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <functional>
#include <ctime>
#include <cassert>

class UniqueID {
 protected:
  static int nextID;
 public:
  int id;
  UniqueID();
  UniqueID(const UniqueID &orig);
  UniqueID &operator=(const UniqueID &orig);
  [[nodiscard]] int getId() const;
};

struct PRNG {
  unsigned seed = 0;
};
void initGenerator(PRNG &generator);
unsigned random(PRNG &generator, unsigned minValue, unsigned maxValue);

class Group;
class Student {
  friend class Group;
  friend class Deanery;

 public:
  explicit Student(std::string newFio, UniqueID* newId); //создание студента с указанием ИД и ФИО
  Student(); //создание студента с указанием ИД и ФИО
  bool isHeadOfGroup();
  float getAverageMark(); // вычисление средней оценки
  [[nodiscard]] int getStId() const;
  std::string getStNamed() const;

 protected:
  static int nextID;

 private:
  int id; // идентификационный номер
  std::string fio; // - фамилия и инициалы
  Group *group{}; // ссылка на группу (объект Group)
  std::vector<int> marks; // вектор оценок

  void addMark(PRNG *generator, bool addBadMarks);//добавление оценки
  void addToGroup(Student *st, Group *gr); //   зачисление в группу
};

#endif //INCLUDE_STUDENT_H_
