// Copyright 2021 valvarl

#ifndef TP_LAB_5_STUDENT_H
#define TP_LAB_5_STUDENT_H

#include "Group.h"
#include <utility>
#include <vector>
#include <numeric>
#include <string>

class Group;

class Student {
    friend class Deanery;
 private:
    int id;
    std::string fio;
    Group *group{};
    std::vector<int>marks;
    void addToGroup(Group *_group);
    void addmark(int mark);
public:
    Student(int _id, std::string& _fio) : id(_id), fio(_fio) {}
    [[nodiscard]] int getId() const;
    [[nodiscard]] const std::string &getName() const;
    double getAverageMark();
    bool isHeadOfGroup();
};

#endif //TP_LAB_5_STUDENT_H
