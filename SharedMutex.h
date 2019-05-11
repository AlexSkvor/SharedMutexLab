#ifndef SharedMutex_H
#define SharedMutex_H

#include <mutex>
#include <atomic>

class SharedMutex
{
	public:
		
    	explicit SharedMutex():
    	    readersNumber_(0),
    	    writersNumber_(0){}
    	
    	void shared_lock(){
    		while(writersNumber_);
    		readersNumber_++;
		}
		
		void shared_unlock(){
    		readersNumber_--;
		}
    	
    	void lock(){
    	    writersNumber_++;
    	    while(readersNumber_);
    	    innerMutex_.lock();
    	}
    	
    	void unlock(){
    	    writersNumber_--;
    	    innerMutex_.unlock();
    	}
   		
   	private:
    	std::mutex innerMutex_;
   		std::atomic<int> readersNumber_;
    	std::atomic<int> writersNumber_;
};

#endif
