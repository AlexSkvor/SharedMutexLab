#ifndef Scheduler_H
#define Scheduler_H

#include <vector>
#include <thread>

class Scheduler{
	public:
		Scheduler();
		Scheduler(std::thread obj);
		
		void addThread(std::thread obj);
		
		static int maxThreads();
		
		void joinAll();
		
		~Scheduler();
		Scheduler(Scheduler &obj) = delete;
		Scheduler& operator=(Scheduler &obj) = delete;
		
	private:
		std::vector<std::thread> threads;
};

#endif
