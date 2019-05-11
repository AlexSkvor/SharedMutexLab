#ifndef Scheduler_H
#define Scheduler_H

#include <vector>
#include <thread>

class Scheduler{
	private:
		std::vector<std::thread> threads;
	public:
		Scheduler(){}
		Scheduler(std::thread obj){
			threads.push_back(std::move(obj));
		}
		
		void addThread(std::thread obj){
			threads.push_back(std::move(obj));
		}
		
		static int maxThreads(){
			int temp = std::thread::hardware_concurrency();
			if (temp < 2) temp = 2;
			return temp;
		}
		
		void joinAll(){
			for(std::vector<std::thread>::iterator it = threads.begin(); it != threads.end(); ++it){
				if(it->joinable()) it->join();
			}
		}
		
		~Scheduler(){
			for(std::vector<std::thread>::iterator it = threads.begin(); it != threads.end(); ++it){
				if(it->joinable()) it->join();
			}
		}
		Scheduler(Scheduler &obj) = delete;
		Scheduler& operator=(Scheduler &obj) = delete;
};

#endif
