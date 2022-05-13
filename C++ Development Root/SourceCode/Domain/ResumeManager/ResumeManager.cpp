#include "TechnicalServices/Persistence/PersistenceHandler.hpp"
#include "Domain/ResumeManager/ResumeManager.hpp"
#include "Domain/ResumeManager/Resume.hpp"
#include "TechnicalServices/PaymentAuth/PaymentAuthHandler.hpp"

#include <iostream>
#include <string>

namespace Domain::ResumeManager{

    ResumeManager::ResumeManager()
    : _persistentData( TechnicalServices::Persistence::PersistenceHandler::instance() ),
    _paymentSystemPtr( TechnicalServices::PaymentAuth::PaymentAuthHandler::createPaymentAuth() ) {}
    ResumeManager::~ResumeManager(){}

    long long ResumeManager::buildResume(std::string selectedResume){
        long long resumeID = _persistentData.resumes.size();
        
        _paymentSystem.newCharge();
        
        if(selectedResume == "College")
        {
            _persistentData.resumes.push_back(CollegeResume(resumeID));
        }
        else if(selectedResume == "Work")
        {
            _persistentData.resumes.push_back(WorkResume(resumeID));
        }
        else if(selectedResume == "Unemployed")
        {
            _persistentData.resumes.push_back(UnemployedResume(resumeID));
        }
        else
        {
            _persistentData.resumes.push_back(Resume(resumeID));
        }
        
        return resumeID;
    }
    std::vector<std::string> ResumeManager::getResumeTypes()
    {
        return _persistentData.getResumeTypes();
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
            {   result += "Resume Type: " + i.getType() + "\n" + "\n";
                result += "Phone number: " + i._contactInfo + "\n";
                result += "Objective Statement: " + i._objInfo + "\n";
                result += "Skills: " + i._skillInfo + "\n";
                result += "Previous Education: " + i._eduInfo + "\n";
                result += "Previous Work Experience: " + i._workInfo + "\n";
            }
        }
        return result;
    }
}

