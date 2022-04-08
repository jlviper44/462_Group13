#include "Domain/ResumeManager/ResumeManager.hpp"
#include "Resume.hpp"

#include <iostream>
#include <string>

namespace Domain::ResumeManager{

    ResumeManager::ResumeManager() {

    }
    ResumeManager::~ResumeManager(){}

    Resume ResumeManager::buildResume(){
        return Resume();
    }

    Resume ResumeManager::createContactInfo(Resume currentResume, std::string contactInfo) {
        // std::string contactInfo;

        // std::cout << "Enter your contact information: ";
        // std::cin.ignore();
        // std::getline (std::cin, contactInfo);
        currentResume._contactInfo = contactInfo;
        return currentResume;
    }

    Resume ResumeManager::createObjInfo(Resume currentResume, std::string objInfo) {
        // std::string objStatement;

        // std::cout << "Enter your objective statement: ";
        // std::getline (std::cin, objStatement);

        // return objStatement;
        currentResume._objInfo = objInfo;
        return currentResume;
    }

    Resume ResumeManager::createSkillInfo(Resume currentResume, std::string skillInfo) {
        // std::string skills;

        // std::cout << "List your skills: ";
        // std::getline (std::cin, skills);

        // return skills;
        currentResume._skillInfo = skillInfo;
        return currentResume;
    }

    Resume ResumeManager::createEduInfo(Resume currentResume, std::string eduInfo) {
        // std::string prevEducation;

        // std::cout << "List your previous education: ";
        // std::getline (std::cin, prevEducation);

        // return prevEducation;
        currentResume._eduInfo = eduInfo;
        return currentResume;
    }

    Resume ResumeManager::createWorkInfo(Resume currentResume, std::string workInfo) {
        // std::string prevWorkExp;

        // std::cout << "List your previous work experience: ";
        // std::getline (std::cin, prevWorkExp);

        // return prevWorkExp;
        currentResume._workInfo = workInfo;
        return currentResume;
    }

    std::string ResumeManager::resumeToString(Resume currentResume){
        std::string result = "";
        result += "Phone number: " + currentResume._contactInfo + "\n";
        result += "Objective Statement: " + currentResume._objInfo + "\n";
        result += "Skills: " + currentResume._skillInfo + "\n";
        result += "Previous Education: " + currentResume._eduInfo + "\n";
        result += "Previous Work Experience: " + currentResume._workInfo + "\n";

        return result;
    }
}

