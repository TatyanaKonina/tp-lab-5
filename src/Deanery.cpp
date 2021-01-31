////// Copyright 2021 Ozhiganova Polina
#include <thread>
#include "Deanery.h"

std::vector<Student *> Deanery::hireStudents(const std::vector<std::string> &namesFI) {
  std::vector<Student *> newStudents;
  for (auto &fi : namesFI) {
    UniqueID *newId = new UniqueID;
    Student *newSt = new Student(fi, newId); // create new student
    newStudents.push_back(newSt);
  }
  return newStudents;
}

void Deanery::createGroups(const std::map<std::string, std::string> &nameGrSp,
                           const std::vector<std::vector<std::string>> &namesFI) {
  auto it = nameGrSp.begin();
  for (int i = 0; it != nameGrSp.end(); it++, i++) {
    Group *gr;
    std::vector<Student *> newStudents;
    newStudents = hireStudents(namesFI[i]);
    Student *newHead = initHeads(gr, newStudents);
    Group *newGr = new Group(it->first, it->second, newStudents, newHead);
    for (auto &st:newStudents) {    /////////////////////////////////////////////////////
      st->addToGroup(st, newGr);
    }
    groups.push_back(newGr);
  }
}

void Deanery::addMarksToAll() {
  std::vector<int> marks;
  for (auto &gr:groups) {
    for (auto &st:gr->students) {
      std::this_thread::sleep_for(std::chrono::milliseconds(30));
      PRNG *gen_low_mark = new PRNG;
      initGenerator(*gen_low_mark);
      int low_mark = random(*gen_low_mark, 1, 4);
      sleep(1);
      PRNG *generator = new PRNG;
      bool addBadMarks = false;
      if (low_mark == 1) {
        addBadMarks = true;
        st->addMark(generator, addBadMarks);
      } else {
        st->addMark(generator, addBadMarks);
      }

    }
  }
}
// print amount and направление (BI...)
// ask what to do
// do some actions
void Deanery::getStatistics(STATISTICS statistics) {
//  if (statistics == FIRE) {
//
//  } else if (statistics == REWARD) {
//
//  } else if (statistics == PUNISH) {
//
//  }
}

std::map<std::vector<Student *>, std::string> Deanery::getStatisticsMove() {
  float generalAverageMark = 0.0;
  std::string lowerPI;
  std::vector<Student *> stsLowerPI;
  std::string lowerPMI;
  std::vector<Student *> stsLowerPMI;
  std::map<std::vector<Student *>, std::string> stsToGrMove;

  for (auto &gr:groups) {
    generalAverageMark = gr->getAverageMark();
    for (auto &st:gr->students) {
      Student *s = st;  ////
      if (st->getAverageMark() < generalAverageMark) {  // so-so --> move to lower group
        std::string t = st->group->spec; ////
        if (st->group->spec == "PI") {  // to PMI
          stsLowerPI.push_back(st);
        } else if (st->group->spec == "PMI") {  // to BI
          stsLowerPMI.push_back(st);
        } else if (st->group->spec == "BI") {  // stay here ;(
          continue;
        }
      } /////////////////////////////////////////////////////  whrite smth more
    }
  }
  stsToGrMove[stsLowerPI] = "PMI";
  stsToGrMove[stsLowerPMI] = "BI";
  return stsToGrMove;
}

std::vector<Student *> Deanery::getStatisticsFire() {      //////////////////
  float generalAverageMark = 0.0;
  std::vector<Student *> stsToFire;

  for (auto &gr:groups) {
    generalAverageMark = gr->getAverageMark();
    for (auto &st:gr->students) {
      if (st->getAverageMark() <= 3) {  // very bad marks  --> fire
        stsToFire.push_back(st);
      }
    }
  }
  return stsToFire;
}

void Deanery::moveStudents(const std::vector<Student *>& sts, const std::string& newGr) {
  std::vector<Student *> stsToMove;
  Student *stMove = new Student;

  Group *newGroup;
  for (auto &gr:groups) {
    if (gr->spec == newGr) {
      newGroup = gr;
      break;
    }
  }

  for (auto &st:sts) {
    // save all info
    stMove->id = st->id;
    stMove->fio = st->fio;
    stMove->group = newGroup;
    stMove->marks = st->marks;
    // del from group
    st->group->removeStudent(st->id);
    // add to new
    newGroup->addStudent(stMove, newGroup);
  }
}

void Deanery::fireStudents(const std::vector<Student *> &sts) {
  for (auto &st:sts) {
    Group* gr = st->group;
    gr->removeStudent(st->id);
  }
}

void Deanery::saveStaff() {   ////////////////////////////

}

Student *Deanery::initHeads(Group *gr, const std::vector<Student *> &newStudents) {
  return gr->chooseHead(newStudents);
}

std::vector<Group *> Deanery::getGroups() {
  return this->groups;
}