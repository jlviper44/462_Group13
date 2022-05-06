#include "TechnicalServices/Persistence/PersistenceHandler.hpp"
#include "Domain/ResumeManager/ResumeManager.hpp"
#include "Resume.hpp"

#include <iostream>
#include <string>

namespace Domain::ResumeManager{

    ResumeManager::ResumeManager()
    : _persistentData( TechnicalServices::Persistence::PersistenceHandler::instance() ) {}
    ResumeManager::~ResumeManager(){}

    long long ResumeManager::buildResume(){
        long long resumeID = _persistentData.resumes.size();
        _persistentData.resumes.push_back(Resume(resumeID));
        return resumeID;
    }

    bool ResumeManager::createContactInfo(long long resumeId, std::string contactInfo)
    {
        bool foundResume = false;
        for (auto &i : _persistentData.resumes)
        {
            if(i._id == resumeId)
            {
                foundResume = true;
                i._contactInfo = contactInfo;
            }
        }

        return foundResume;
    }
    bool ResumeManager::createObjInfo(long long resumeId, std::string objInfo)
    {
        bool foundResume = false;
        for (auto &i : _persistentData.resumes)
        {
            if(i._id == resumeId)
            {
                foundResume = true;
                i._objInfo = objInfo;
            }
        }

        return foundResume;
    }
    bool ResumeManager::createSkillInfo(long long resumeId, std::string skillInfo)
    {
        bool foundResume = false;
        for (auto &i : _persistentData.resumes)
        {
            if(i._id == resumeId)
            {
                foundResume = true;
                i._skillInfo = skillInfo;
            }
        }

        return foundResume;
    }
    bool ResumeManager::createEduInfo(long long resumeId, std::string eduInfo)
    {
        bool foundResume = false;
        for (auto &i : _persistentData.resumes)
        {
            if(i._id == resumeId)
            {
                foundResume = true;
                i._eduInfo = eduInfo;
            }
        }

        return foundResume;
    }
    bool ResumeManager::createWorkInfo(long long resumeId, std::string workInfo)
    {
        bool foundResume = false;
        for (auto &i : _persistentData.resumes)
        {
            if(i._id == resumeId)
            {
                foundResume = true;
                i._workInfo = workInfo;
            }
        }

        return foundResume;
    }
    std::string ResumeManager::resumeToString(long long resumeId)
    {
        std::string result = "";
        for (auto &i : _persistentData.resumes)
        {
            if(i._id == resumeId)
            {
                result += "Phone number: " + i._contactInfo + "\n";
                result += "Objective Statement: " + i._objInfo + "\n";
                result += "Skills: " + i._skillInfo + "\n";
                result += "Previous Education: " + i._eduInfo + "\n";
                result += "Previous Work Experience: " + i._workInfo + "\n";
            }
        }
        return result;
    }

    // std::string ResumeManager::resumeToString(Resume currentResume){
    //     std::string result = "";
    //     result += "Phone number: " + currentResume._contactInfo + "\n";
    //     result += "Objective Statement: " + currentResume._objInfo + "\n";
    //     result += "Skills: " + currentResume._skillInfo + "\n";
    //     result += "Previous Education: " + currentResume._eduInfo + "\n";
    //     result += "Previous Work Experience: " + currentResume._workInfo + "\n";

    //     return result;
    // }
}

