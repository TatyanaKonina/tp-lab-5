// Copyright 2021 valvarl

#include <iostream>
#include <Deanery.h>
#include <Group.h>

void Group::addStudent(Student &student) {
    students->push_back(&student);
}

void Group::removeStudent(Student &student) {
    int student_index = containsStudent(student);
    if (-1 != student_index) {
        std::cout << student.getName() << " удален из группы \""
                  << title << "\"." << std::endl;
        students->erase(students->begin() + student_index);
    }
}

void Group::chooseHead() {
    if (!isEmpty()) {
        Student &st = *students->at(deanery->rand_int() % students->size());
        std::cout << "В группе \"" << title << "\" старостой назначен(а) "
        << st.getName() << std::endl;
        head = &st;
    }
}

double Group::getAverageMark() {
    return 0;
}

Student &Group::getStudent(std::string& fio) {
    for (auto & student : *students) {
        if (student->getName() == fio) {
            return *student;
        }
    }
}

Student &Group::getStudent(int id) {
    for (auto & student : *students) {
        if (student->getId() == id) {
            return *student;
        }
    }
}

int Group::containsStudent(Student &student) {
    for (int i = 0; i < students->size(); i++) {
        if (students->at(i)->getId() == student.getId()) {
            return i;
        }
    }
    return -1;
}

std::string Group::getTitle() {
    return title;
}

Student &Group::getHead() {
    return *this->head;
}

bool Group::isEmpty() {
    return this->students->empty();
}

Group::~Group() {
    for (auto student : *students){
        delete student;
    }
    delete students;
}