#ifndef __RESUMEMANAGER__
#define __RESUMEMANAGER_

#include "Domain/ResumeManager/ResumeHandler.hpp"
#include "Resume.hpp"

namespace Domain::ResumeManager
{
    class ResumeManager : public Domain::ResumeManager::ResumeHandler
    {
        public:
        ResumeManager();
        Resume buildResume();



        ~ResumeManager() noexcept override;
    };
}

#endif