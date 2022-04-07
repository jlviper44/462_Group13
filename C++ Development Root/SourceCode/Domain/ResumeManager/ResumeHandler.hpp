#ifndef __RESUMEHANDLER__
#define __RESUMEHANDLER__

#include <memory>

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
    };
}

#endif