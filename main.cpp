#include <fstream>
#include <iostream>

#include "ThreadSheduler.h"
#include "SharedMutex.h"
#include <time.h>

int randBetweenOneAndHundred(){
	return (rand()%100 + 1);
}

class IDatabase{
	public:
		virtual void read() = 0;
		virtual void write() = 0;
};

class JustDatabase : public IDatabase{
	public:
		void read() override{
			m_.lock();
			std::this_thread::sleep_for(std::chrono::milliseconds(randBetweenOneAndHundred()));
			m_.unlock();
		}
		
		void write() override{
			m_.lock();
			std::this_thread::sleep_for(std::chrono::milliseconds(randBetweenOneAndHundred()));
			m_.unlock();
		}
	private:
		std::mutex m_;
};

class SharedDatabase: public IDatabase{
	public:
		void read() override{
			sm_.shared_lock();
			std::this_thread::sleep_for(std::chrono::milliseconds(randBetweenOneAndHundred()));
			sm_.shared_unlock();
		}
		
		void write() override{
			sm_.lock();
			std::this_thread::sleep_for(std::chrono::milliseconds(randBetweenOneAndHundred()));
			sm_.unlock();
		}
	private:
		SharedMutex sm_;
};

const int WRITES_PERCENT = 10;

void doSomething(IDatabase& db){
	if(randBetweenOneAndHundred() <= WRITES_PERCENT){
		db.write();
	}else db.read();
}

void work(IDatabase& db){
	for(int i = 0; i < 50; i++) doSomething(db);
}

int main() {
	srand(time(NULL));
	SharedDatabase db;
	Scheduler scheduler;
	for(int i = 0; i < 20; i++){
		scheduler.addThread(std::thread(work, std::ref(db)));
	}
	return 0;
}
