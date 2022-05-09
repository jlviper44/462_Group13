#ifndef __RESUMEMANAGER__
#define __RESUMEMANAGER_

#include "TechnicalServices/Persistence/PersistenceHandler.hpp"
#include "Domain/ResumeManager/ResumeHandler.hpp"
#include "TechnicalServices/PaymentAuth/PaymentAuthHandler.hpp"


#include <string>

namespace Domain::ResumeManager
{

    class ResumeManager : public Domain::ResumeManager::ResumeHandler
    {
        public:
        ResumeManager();

        std::vector<std::string> getResumeTypes();
        long long buildResume(std::string selectedResume);
        bool createContactInfo(long long resumeId, std::string contactInfo);
        bool createObjInfo(long long resumeId, std::string objInfo);
        bool createSkillInfo(long long resumeId, std::string skillInfo);
        bool createEduInfo(long long resumeId, std::string eduInfo);
        bool createWorkInfo(long long resumeId, std::string workInfo);
        std::string resumeToString(long long resumeId);

        ~ResumeManager() noexcept override;

        private:
        TechnicalServices::Persistence::PersistenceHandler & _persistentData;
        std::unique_ptr<TechnicalServices::PaymentAuth::PaymentAuthHandler> _paymentSystemPtr;
        TechnicalServices::PaymentAuth::PaymentAuthHandler & _paymentSystem = *_paymentSystemPtr;
    };
}

#endif