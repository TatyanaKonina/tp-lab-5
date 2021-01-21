// Copyright 2021 valvarl

#ifndef TP_LAB_5_DEANERY_H
#define TP_LAB_5_DEANERY_H

#include <vector>
#include <string>
#include <chrono>
#include <random>
#include "Student.h"


class Student;

class Group;

class Deanery {
 private:
    int id;
    std::vector<Group *> *groups;
    void createGroups();
    void hireStudents();
    std::minstd_rand simple_rand;
 public:
    Deanery();
    Group& getGroup(const std::string &title);
    void addMarksToAll();
    void getStatistics();
    void moveStudents();
    void saveStuff();
    void initHeads();
    void fireStudents();
    int rand_int() { return simple_rand(); }
    ~Deanery();
};

#endif //TP_LAB_5_DEANERY_H
