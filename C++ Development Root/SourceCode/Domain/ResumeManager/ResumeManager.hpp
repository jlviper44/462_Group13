#ifndef __RESUMEMANAGER__
#define __RESUMEMANAGER_

#include "Domain/ResumeManager/ResumeHandler.hpp"
#include "Resume.hpp"

#include <string>

namespace Domain::ResumeManager
{

    class ResumeManager : public Domain::ResumeManager::ResumeHandler
    {
        public:
        ResumeManager();
        Resume buildResume();
        std::string createContactInfo();
        std::string createObjInfo();
        std::string createSkillInfo();
        std::string createEduInfo();
        std::string createWorkInfo();
        std::string resumeToString(Resume currentResume);

        ~ResumeManager() noexcept override;
    };
}

#endif