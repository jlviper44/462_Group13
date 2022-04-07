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
        virtual std::string createContactInfo() = 0;
        virtual std::string createObjInfo() = 0;
        virtual std::string createSkillInfo() = 0;
        virtual std::string createEduInfo() = 0;
        virtual std::string createWorkInfo() = 0;
        virtual std::string resumeToString(Resume currentResume) = 0;


    };
}

#endif