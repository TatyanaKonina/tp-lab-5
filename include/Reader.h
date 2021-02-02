//// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_READER_H_
#define INCLUDE_READER_H_
#include <fstream>
#include "Deanery.h"
#include <external/json.hpp>

class Reader {
 public:
  using json = nlohmann::json;
  std::map<std::string, std::string> parseGrSp(const json &file);
  std::vector<std::vector<std::string>> parseFI(const json &file);
  void saveStaff(Deanery *d, json &file);
};

#endif //INCLUDE_READER_H_
