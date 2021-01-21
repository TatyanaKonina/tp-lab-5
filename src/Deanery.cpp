// Copyright 2021 valvarl

#include <fstream>
#include <nlohmann/json.hpp>
#include <chrono>
#include <string>
#include <iostream>
#include "Deanery.h"


void Deanery::createGroups() {
    std::string g = R"(F:\Projects\C++\tp-lab-5\src\data\groups.json)";
    std::ifstream ig(g);
    nlohmann::json jg;
    ig >> jg;
    auto groups_json = jg.get<std::vector<nlohmann::json>>();
    for (const auto& v : groups_json) {
        auto title = v["title"].get<std::string>();
        auto spec = v["spec"].get<std::string>();
        auto *_g = new Group{title, spec, *this};
        groups->push_back(_g);
    }
}

void Deanery::hireStudents() {
    std::string s = R"(F:\Projects\C++\tp-lab-5\src\data\students.json)";
    std::ifstream is(s);
    nlohmann::json js;
    is >> js;
    auto students = js.get<std::vector<std::string>>();
    std::string title;
    for (auto v : students) {
        auto *student = new Student{id++, v};
        Group *g = groups->at(rand_int() % groups->size());
        g->addStudent(*student);
        student->addToGroup(g);
    }
}

Deanery::Deanery() {
    id = 0;
    groups = new std::vector<Group *>();
    simple_rand.seed(std::chrono::system_clock::now().time_since_epoch().count());
    createGroups();
    hireStudents();
    std::cout << groups->at(0)->students->at(25)->id<< std::endl;
}

Group &Deanery::getGroup(const std::string &title) {
    Group *gp;
    for (Group *g : *groups) {
        if (g->getTitle() == title) {
            gp = g;
            break;
        }
    }
    return *gp;
}

Deanery::~Deanery() {
    for (auto group : *groups) {
        delete group;
    }
    delete groups;
}
