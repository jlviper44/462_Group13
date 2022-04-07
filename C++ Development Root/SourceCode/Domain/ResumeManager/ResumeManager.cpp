#include "Domain/ResumeManager/ResumeManager.hpp"
#include "Resume.hpp"

#include <iostream>
#include <string>

namespace Domain::ResumeManager
{
    ResumeManager::ResumeManager()
    {
        std::cout << "Resume says hey c:";
    }
    ResumeManager::~ResumeManager(){}

    Resume ResumeManager::buildResume() {
        std::string name;
        std::string desc;



        std::cout << "Enter your phone number: ";
        std::getline (std::cin, name);

        std::cout << "Enter your objecttive statenebt: ";
        std::getline (std::cin, desc);

    }
}

