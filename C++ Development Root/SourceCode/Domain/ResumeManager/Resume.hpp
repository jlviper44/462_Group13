#ifndef __RESUME__
#define __RESUME__

class Resume
{
	public:
		std::string _contactInfo;
		std::string _objInfo;
		std::string _skillInfo;
		std::string _eduInfo;
		std::string _workInfo;

		Resume( std::string contactInfo,
				std::string objInfo,
				std::string skillInfo,
				std::string eduInfo,
				std::string workInfo);
		~Resume();

		Resume();
};


#endif