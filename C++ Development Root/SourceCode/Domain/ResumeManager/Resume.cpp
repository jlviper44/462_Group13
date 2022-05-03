#include "Resume.hpp"

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
}

Resume::~Resume(){}
Resume::Resume(long long id)
{
	_id = id;
}