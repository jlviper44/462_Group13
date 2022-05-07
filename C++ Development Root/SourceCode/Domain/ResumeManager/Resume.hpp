#ifndef __RESUME__
#define __RESUME__

class Resume
{
	public:
		long long _id;
		std::string _contactInfo;
		std::string _objInfo;
		std::string _skillInfo;
		std::string _eduInfo;
		std::string _workInfo;

		Resume( long long id,
				std::string contactInfo,
				std::string objInfo,
				std::string skillInfo,
				std::string eduInfo,
				std::string workInfo);
		~Resume();

		Resume(long long id);
		std::string getType();
		void setType(std::string type);
		
	private:
		std::string _type;
};

class CollegeResume: public Resume
{
	public:
		CollegeResume( long long id,
				std::string contactInfo,
				std::string objInfo,
				std::string skillInfo,
				std::string eduInfo,
				std::string workInfo);
		~CollegeResume();

		CollegeResume(long long id);
	
	private:
		std::string _type;
};


class WorkResume: public Resume
{
	public:
		WorkResume( long long id,
				std::string contactInfo,
				std::string objInfo,
				std::string skillInfo,
				std::string eduInfo,
				std::string workInfo);
		~WorkResume();

		WorkResume(long long id);
	
	private:
		std::string _type;
};


class UnemployedResume: public Resume
{
	public:
		UnemployedResume( long long id,
				std::string contactInfo,
				std::string objInfo,
				std::string skillInfo,
				std::string eduInfo,
				std::string workInfo);
		~UnemployedResume();

		UnemployedResume(long long id);
	
	private:
		std::string _type;
};

#endif