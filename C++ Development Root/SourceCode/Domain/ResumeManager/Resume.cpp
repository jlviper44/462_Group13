#include "Domain/ResumeManager/Resume.hpp"

#include <string>
#include <iostream>

Resume::Resume( long long id,
				std::string contactInfo,
				std::string objInfo,
				std::string skillInfo,
				std::string eduInfo,
				std::string workInfo)
{
	_contactInfo = contactInfo;
	_objInfo 	 = objInfo;
	_skillInfo	 = skillInfo;
	_eduInfo	 = eduInfo;
	_workInfo	 = workInfo;
	this -> setType("");
}

Resume::~Resume(){}
Resume::Resume(long long id)
{
	_id = id;
	this -> setType("");
}
std::string Resume::getType()
{
	return _type;
}
void Resume::setType(std::string type)
{
	_type = type;
}


CollegeResume::CollegeResume(   long long id,
								std::string contactInfo,
								std::string objInfo,
								std::string skillInfo,
								std::string eduInfo,
								std::string workInfo)
:Resume::Resume(id, contactInfo, objInfo, skillInfo, eduInfo, workInfo)
{
	_contactInfo = contactInfo;
	_objInfo 	 = objInfo;
	_skillInfo	 = skillInfo;
	_eduInfo	 = eduInfo;
	_workInfo	 = workInfo;
	this -> setType("College");
}

CollegeResume::~CollegeResume(){}
CollegeResume::CollegeResume(long long id)
:Resume::Resume(id)
{
	_id = id;
	this -> setType("College");
}

WorkResume::WorkResume(   long long id,
								std::string contactInfo,
								std::string objInfo,
								std::string skillInfo,
								std::string eduInfo,
								std::string workInfo)
:Resume::Resume(id, contactInfo, objInfo, skillInfo, eduInfo, workInfo)
{
	_contactInfo = contactInfo;
	_objInfo 	 = objInfo;
	_skillInfo	 = skillInfo;
	_eduInfo	 = eduInfo;
	_workInfo	 = workInfo;
	this -> setType("Work");
}

WorkResume::~WorkResume(){}
WorkResume::WorkResume(long long id)
:Resume::Resume(id)
{
	_id = id;
	this -> setType("Work");
}

UnemployedResume::UnemployedResume(   long long id,
								std::string contactInfo,
								std::string objInfo,
								std::string skillInfo,
								std::string eduInfo,
								std::string workInfo)
:Resume::Resume(id, contactInfo, objInfo, skillInfo, eduInfo, workInfo)
{
	_contactInfo = contactInfo;
	_objInfo 	 = objInfo;
	_skillInfo	 = skillInfo;
	_eduInfo	 = eduInfo;
	_workInfo	 = workInfo;
	this -> setType("Unemployed");
}

UnemployedResume::~UnemployedResume(){}
UnemployedResume::UnemployedResume(long long id)
:Resume::Resume(id)
{
	_id = id;
	this -> setType("Unemployed");
}