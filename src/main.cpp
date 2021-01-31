////// Copyright 2021 Ozhiganova Polina
#include <iostream>
#include "Reader.h"
#include "Deanery.h"

int main() {
  // WORK WITH FILE
  Reader *r = new Reader;
  std::ifstream f("C:\\Lab_5\\groups.json");                 // CHANGE!!!!!!!!!!!!
  nlohmann::json jf = nlohmann::json::parse(f);
  // PARSE DATA
  std::map<std::string, std::string> nameGrSp = r->parseGrSp(jf);
  std::vector<std::vector<std::string>> namesFI = r->parseFI(jf);
  // CREATE DEANERY
  Deanery *d = new Deanery;
  // CREATE GROUPS
  d->createGroups(nameGrSp, namesFI);
  // GENERATE MARKS TO ALL ST-S
  d->addMarksToAll();
  // MOVE ST-S
  std::map<std::vector<Student *>, std::string> stsMove = d->getStatisticsPunish();
  for (auto &obj1:stsMove) {
    if (!obj1.first.empty()) {
      std::cout << ">> Will be MOVED: " << std::endl;
      for (auto &el:stsMove) {
        std::cout << ">> STUDENTS: " << el.first.size() << "\n\n";
        for (auto &stName:el.first) {
          std::cout << stName->getStNamed() << " (" << stName->getStSpec() << ")" << std::endl;
        }
        std::cout << ">> MOVE TO: " << el.second << "\n\n";
        d->moveStudents(el.first, el.second);
      }
      break;
    }
  }
  // NEW GROUPS SIZE
  for (auto &gr:d->getGroups()) {
    std::cout << gr->getStudents().size() << " (" << gr->getSpec() << ")" << std::endl;
  }
  std::cout << "*** === ***" << std::endl;
  // FIRE ST-S
  std::vector<Student *> stsFire = d->getStatisticsFire();
  if (!stsFire.empty()) {
    std::cout << ">> Will be FIRED: " << stsFire.size() << std::endl;
    for (auto &st:stsFire) {
      std::cout << st->getStNamed() << " (" << st->getStSpec() << ")" << std::endl;
    }
    d->fireStudents(stsFire);
  }
  // NEW GROUPS SIZE
  for (auto &gr:d->getGroups()) {
    std::cout << gr->getStudents().size() << " (" << gr->getSpec() << ")" << std::endl;
  }
  return 0;
}