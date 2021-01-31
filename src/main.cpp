////// Copyright 2021 Ozhiganova Polina
#include <iostream>
#include "Reader.h"
#include "Deanery.h"
#include "Group.h"
#include "Student.h"

int main() {
  Reader *r = new Reader;
  std::ifstream f("C:\\Lab_5\\groups.json");  // CHANGE!!!!!!!!!!!!
  nlohmann::json jf = nlohmann::json::parse(f);

  std::map<std::string, std::string> nameGrSp = r->parseGrSp(jf);
  std::vector<std::vector<std::string>> namesFI = r->parseFI(jf);

  Deanery *d = new Deanery;
  d->createGroups(nameGrSp, namesFI);
  d->addMarksToAll();
// MOVE
  std::map<std::vector<Student *>, std::string> stsMove = d->getStatisticsMove();
  for (auto &obj1:stsMove) {
    if (!obj1.first.empty()){
      std::cout << "Will be MOVED: " << std::endl;
      for (auto &el:stsMove) {
        std::cout << "STUDENTS: " << "\n\n";
        for (auto & stName:el.first){
          std::cout << stName->getStNamed() << std::endl;
        }
        std::cout << "Move to: " << el.second << "\n\n";
        d->moveStudents(el.first, el.second);
      }
//      d->moveStudents(stsMove);
      break;
    }
  }
// PRINT DIFFERENCE
  for (auto & gr:d->getGroups()) {
    std::cout << gr->getStudents().size() << std::endl;
  }

//// FIRE
//  std::vector<Student *> stsFire = d->getStatisticsFire();
//  if (!stsFire.empty()){
//    d->fireStudents(stsFire);
//  }
//// PRINT DIFFERENCE
//  for (auto & gr:d->getGroups()) {
//    std::cout << gr->getStudents().size() << std::endl;
//  }


return 0;
}