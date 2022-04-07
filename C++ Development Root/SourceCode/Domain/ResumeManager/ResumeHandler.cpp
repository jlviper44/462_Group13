#include <memory>
#include <iostream>
#include "Domain/ResumeManager/ResumeHandler.hpp"
#include "Domain/ResumeManager/ResumeManager.hpp"


namespace Domain::ResumeManager
{
    std::unique_ptr<ResumeHandler> ResumeHandler::createMgr()
    {
        std::cout << "ResumeHandler running...";
        return std::make_unique<ResumeManager>();
    }
    ResumeHandler::~ResumeHandler(){}
}