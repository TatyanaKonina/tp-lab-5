//// Copyright 2021 Ozhiganova Polina
#include "Reader.h"

std::map<std::string, std::string> Reader::parseGrSp(const json &file) {
  std::map<std::string, std::string> grSp;
  for (auto &el1 : file.items()) {
    std::string gr;
    std::string sp;
    std::string strGrSp = el1.key();
    int begSp = (el1.key().find('-'));
    gr.append(strGrSp, 0, begSp);
    sp.append(strGrSp, begSp + 1, strGrSp.size() - begSp);
    grSp[gr] = sp;
  }
  return grSp;
}

std::vector<std::vector<std::string>> Reader::parseFI(const json &file) {
  std::vector<std::string> fi;
  std::vector<std::vector<std::string>> finale;

  for (auto &el1 : file.items()) {
    for (auto &el2: el1.value()) {
      std::string name = el2["name"];
      std::string surname = el2["surname"];
      std::string surnameName = surname + " " + name;
      fi.push_back(surnameName); // put fi in vec
    }
    finale.push_back(fi);
    fi.clear();
  }
  return finale;
}



