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
        Resume createContactInfo(Resume currentResume, std::string contactInfo);
        Resume createObjInfo(Resume currentResume, std::string objInfo);
        Resume createSkillInfo(Resume currentResume, std::string skillInfo);
        Resume createEduInfo(Resume currentResume, std::string eduInfo);
        Resume createWorkInfo(Resume currentResume, std::string workInfo);
        std::string resumeToString(Resume currentResume);

        ~ResumeManager() noexcept override;
    };
}

#endif