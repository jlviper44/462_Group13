#include "Session.hpp"
#include <chrono>
#include <ctime>
#include <iomanip> 
#include <sstream> 
#include <string>

Session::Session()
{
	const auto p1 = std::chrono::system_clock::now();
	_sessionID = std::chrono::duration_cast<std::chrono::seconds>(p1.time_since_epoch()).count();

	std::stringstream myTime;
	auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	#if defined(_MSC_VER)  &&  _MSC_VER >= 1920     // if using Visual Studio 2019 version 16.0 or earlier  (I believe VSC++ started enforcing the deprecation here)
      std::tm destination;
      ::localtime_s(&destination, &now);
      myTime << std::put_time( &destination, "%Y-%m-%d %X" );
    
    #else
      myTime << std::put_time( std::localtime( &now ), "%Y-%m-%d %X" );
    #endif

    _sessionDate = myTime.str();
}