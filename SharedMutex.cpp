#include "SharedMutex.h"

SharedMutex::SharedMutex():
    readersNumber_(0){}

void SharedMutex::shared_lock(){
	std::mutex::lock();
    readersNumber_++;
	std::mutex::unlock();
}
		
void SharedMutex::shared_unlock(){
  	readersNumber_--;
}
  	
void SharedMutex::lock(){
	std::mutex::lock();
	while(readersNumber_);
}
    	
void SharedMutex::unlock(){
    std::mutex::unlock();
}
