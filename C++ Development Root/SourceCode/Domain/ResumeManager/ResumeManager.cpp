#include "Domain/ResumeManager/ResumeManager.hpp"
#include "Resume.hpp"

#include <iostream>
#include <string>

namespace Domain::ResumeManager{

    ResumeManager::ResumeManager() {
        std::cout << "Resume says hey c:";

    }
    ResumeManager::~ResumeManager(){}

    Resume ResumeManager::buildResume(){
        return Resume();
    }

    std::string ResumeManager::createContactInfo() {
        std::string contactInfo;

        std::cout << "Enter your contact information: ";
        std::cin.ignore();
        std::getline (std::cin, contactInfo);

        return contactInfo;
    }

    std::string ResumeManager::createObjInfo() {
        std::string objStatement;

        std::cout << "Enter your objective statement: ";
        std::getline (std::cin, objStatement);

        return objStatement;
    }

    std::string ResumeManager::createSkillInfo() {
        std::string skills;

        std::cout << "List your skills: ";
        std::getline (std::cin, skills);

        return skills;
    }

    std::string ResumeManager::createEduInfo() {
        std::string prevEducation;

        std::cout << "List your previous education: ";
        std::getline (std::cin, prevEducation);

        return prevEducation;
    }

    std::string ResumeManager::createWorkInfo() {
        std::string prevWorkExp;

        std::cout << "List your previous work experience: ";
        std::getline (std::cin, prevWorkExp);

        return prevWorkExp;
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

