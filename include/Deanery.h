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
    std::stringbuf generateStatistic();
    std::minstd_rand simple_rand;
    Group &groupByStudent(int _id);
    Group &groupByStudent(const std::string& name);
    Group &getGroup(const std::string &title);
 public:
    Deanery();
    void addMarksToAll(int amount);
    void getStatistics();
    void moveStudents(int _id, std::string &title);
    void moveStudents(std::string& name, std::string &title);
    void saveStuff();
    void initHeads();
    void fireStudents(int _id);
    void fireStudents(std::string& name);
    int rand_int() { return simple_rand(); }
    ~Deanery();
};

#endif  // TP_LAB_5_DEANERY_H
