#ifndef __RESUMEHANDLER__
#define __RESUMEHANDLER__

#include <memory>
#include <vector>

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
        virtual std::vector<std::string> getResumeTypes() = 0;
        virtual long long buildResume(std::string selectedResume) = 0;
        virtual bool createContactInfo(long long resumeId, std::string contactInfo) = 0;
        virtual bool createObjInfo(long long resumeId, std::string objInfo) = 0;
        virtual bool createSkillInfo(long long resumeId, std::string skillInfo) = 0;
        virtual bool createEduInfo(long long resumeId, std::string eduInfo) = 0;
        virtual bool createWorkInfo(long long resumeId, std::string workInfo) = 0;
        virtual std::string resumeToString(long long resumeId) = 0;


    };
}

#endif