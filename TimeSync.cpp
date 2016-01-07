#include "TimeSync.h"

uint64_t ReadULLtxt(std::string filepath)
{
	uint64_t result = 0;
	std::ifstream fp;
	fp.open(filepath); 
	while (fp >> result)
	{
		std::cout << result << std::endl;
	}
	//  end of 함수 내용
	fp.close();
	return result;
}


TimerHost::TimerHost() {
	//  will save time asset at C://RoboticsTimer/
	this->stdPath = "C:\\RoboticsTimer\\sync";
	// asdf

}

void TimerHost::set(uint64_t delay) {
	std::string tempPath;
	std::ostringstream ost;
	this->startTime = delay + CPU_TIME;
	std::cout << "CPU_TIME : " << this->startTime - delay << std::endl;
	std::cout << "delay value : " << delay << std::endl;
	std::cout << "aprx value : " << this->startTime << std::endl;
	for (int i = 0; i < 10; i++) {
		ost.str("");
		ost << i;
		tempPath = stdPath + ost.str();
		
		auto accessResult = access(tempPath.c_str(), 0);
		if (accessResult == 0) {
			std::cout << "file is already exist\n";
			remove(tempPath.c_str());
			accessResult = access(tempPath.c_str(), 0);
		}

		if (accessResult == -1) {
			this->fp.open(tempPath.c_str());
			this->fp << startTime;
			this->fp.close();
		}

	}
}

void TimerHost::order() {



}

TimerClient::TimerClient() {
	std::string stdPath = "C:\\RoboticsTimer\\sync";
	std::string tempPath;
	std::ostringstream ost;
	for (int i = 0; i < 10; i++) {
		ost.str("");
		ost << i;
		tempPath = stdPath + ost.str();

		try {
			std::ofstream fp;
			fp.open(tempPath.c_str());
			fp.close();
		}
		catch (std::ios_base::failure& e) {
			std::cerr << e.what() << '\n';
			continue;
		}
	}
}

void TimerClient::wait() {

	return;
}