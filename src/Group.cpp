////// Copyright 2021 Ozhiganova Polina
#include "Group.h"

Group::Group(std::string newTitle,
             std::string newSpec,
             const std::vector<Student *> &newStudents,
             Student *newHead) {

  this->title = std::move(newTitle);
  this->spec = std::move(newSpec);
  this->head = newHead;
}

bool Group::containStudent(int stId) {
  for (auto &st:students) {
    if (st->getStId() == stId) {
      return true;
    } else {
      return false;
    }
  }
  return false;
}

Student *Group::getStudent(int stId) {
  for (auto &st:students) {
    if (st->getStId() == stId) {
      return st;
    }
  }
  return nullptr;
}

float Group::getAverageMark() {
  float sum = 0.0;
  for (auto &st:students) {
    sum += st->getAverageMark();
  }
  return sum / students.size();
}

bool Group::isEmpty() {
  if (students.empty()) {
    return true;
  } else {
    return false;
  }
}

void Group::addStudent(Student *st, Group *gr) {
  st->addToGroup(st, gr);
}

void removeFromVec(std::vector<Student *> &vec, size_t pos) {
  auto it = vec.begin();
  std::advance(it, pos);
  vec.erase(it);

}

void Group::removeStudent(int stId) {
  Student *st = getStudent(stId);
  int stIndexInVec = 0;
  for (int i = 0; i < students.size(); ++i) {
    if (st == students[i]) {
      stIndexInVec = i;
      break;
    }
  }
  bool isHead = false;
  if (st->isHeadOfGroup()) {
    isHead = true;
  }

  //  st->id = 0;
  //  st->fio = nullptr;
  //  st->group = nullptr;
  //  st->marks = static_cast<const std::vector<int>>(0);

  removeFromVec(students, stIndexInVec);  // del from students vec
  if (isHead) {
    chooseHead(students);
  }
}

Student *Group::chooseHead(const std::vector<Student *> &newStudents) {
  int beginId = newStudents[0]->getStId();
  int endId = newStudents[newStudents.size() - 1]->getStId();
  if (beginId < endId) { //////////////////////////////////////////////////////////////
    int tmp;
    tmp = beginId;
    beginId = endId;
    endId = tmp;
  }
  PRNG *generator = new PRNG;
  initGenerator(*generator);
  int idHead = random(*generator, beginId, endId);
  for (auto &st:newStudents) {
    if (st->getStId() == idHead) {
      return st;
    }
  }
  return nullptr;
}

std::vector<Student *> Group::getStudents() {
  return this->students;
}

std::string Group::getSpec() {
  return this->spec;
}
