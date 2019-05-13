#ifndef SharedMutex_H
#define SharedMutex_H

#include <mutex>
#include <atomic>

class SharedMutex: public std::mutex{
	public:
		
    	explicit SharedMutex();
    	
    	void shared_lock();
		void shared_unlock();
    	
    	void lock();
    	void unlock();
   		
   	private:
   		std::atomic<int> readersNumber_;
};

#endif

