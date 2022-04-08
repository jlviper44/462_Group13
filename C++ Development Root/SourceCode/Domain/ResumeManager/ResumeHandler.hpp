#ifndef __RESUMEHANDLER__
#define __RESUMEHANDLER__

#include <memory>
#include "Resume.hpp"

namespace Domain::ResumeManager
{
    class ResumeHandler
    {
        public:
        
        //Manager Factory
        static std::unique_ptr<ResumeHandler> createMgr();
        //Operations
        //virtual std::string getUserLogByID(std::long long userID) = 0;
        //Destructor

        virtual ~ResumeHandler() noexcept = 0;
        //virtual Resume createContactInfo() = 0;

        virtual Resume buildResume() = 0;
        virtual Resume createContactInfo(Resume currentResume, std::string contactInfo) = 0;
        virtual Resume createObjInfo(Resume currentResume, std::string objInfo) = 0;
        virtual Resume createSkillInfo(Resume currentResume, std::string skillInfo) = 0;
        virtual Resume createEduInfo(Resume currentResume, std::string eduInfo) = 0;
        virtual Resume createWorkInfo(Resume currentResume, std::string workInfo) = 0;
        virtual std::string resumeToString(Resume currentResume) = 0;


    };
}

#endif