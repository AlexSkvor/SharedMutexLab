#include "ThreadSheduler.h"

Scheduler::Scheduler(){}

Scheduler::Scheduler(std::thread obj){
	threads.push_back(std::move(obj));
}

void Scheduler::addThread(std::thread obj){
	threads.push_back(std::move(obj));
}

int Scheduler::maxThreads(){
	int temp = std::thread::hardware_concurrency();
	if (temp < 2) temp = 2;
	return temp;
}
		
void Scheduler::joinAll(){
	for(std::vector<std::thread>::iterator it = threads.begin(); it != threads.end(); ++it){
		if(it->joinable()) it->join();
	}
}
		
Scheduler::~Scheduler(){
	for(std::vector<std::thread>::iterator it = threads.begin(); it != threads.end(); ++it){
		if(it->joinable()) it->join();
	}
}
