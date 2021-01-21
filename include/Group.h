// Copyright 2021 valvarl

#ifndef TP_LAB_5_GROUP_H
#define TP_LAB_5_GROUP_H

#include <string>
#include <vector>


class Student;

class Deanery;

class Group {
    friend class Deanery;
 private:
    std::string title;
    std::string spec;
    std::vector<Student *> *students;
    Student *head{};
    Deanery *deanery;
    void addStudent(Student &student);
    void removeStudent(Student& student);
    void chooseHead();
public:
    Group(std::string& _title, std::string& _spec, Deanery &_deanery) :
    title(_title), spec(_spec), deanery(&_deanery),
    students(new std::vector<Student *>()) {}
    double getAverageMark();
    Student& getStudent(std::string& fio);
    Student& getStudent(int id);
    int containsStudent(Student &student);
    std::string getTitle();
    Student& getHead();
    bool isEmpty();
    ~Group();
};


#endif //TP_LAB_5_GROUP_H
