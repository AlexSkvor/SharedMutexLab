#ifndef SharedMutex_H
#define SharedMutex_H

#include <mutex>
#include <atomic>

class SharedMutex
{
	public:
		
    	explicit SharedMutex():
    	    readersNumber_(0){}
    	
    	void shared_lock(){
			innerMutex_.lock();
			readersNumber_++;
			innerMutex_.unlock();
		}
		
		void shared_unlock(){
			readersNumber_--;
		}
    	
		void lock(){
			innerMutex_.lock();
			while(readersNumber_);
		}
    	
		void unlock(){
			innerMutex_.unlock();
		}
   		
	private:
		std::mutex innerMutex_;
		std::atomic<int> readersNumber_;
};

#endif
