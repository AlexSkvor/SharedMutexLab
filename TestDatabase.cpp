#include "TestDatabase.h"

void ATestDatabase::doSomething(){
	if(randUntill(100) <= WRITES_PERCENT) write();
	else read();
}

void ATestDatabase::wait(){
	std::this_thread::sleep_for(std::chrono::milliseconds(randUntill(10)));
}

void ATestDatabase::write(){
	m_.lock();
	wait();
	m_.unlock();
}

int ATestDatabase::randUntill(int until){
	if (until == 0) return 0;
	return (rand()%until + 1);
}


void CommonDatabase::read(){
	m_.lock();
	wait();
	m_.unlock();
}

void SharedDatabase::read(){
	m_.shared_lock();
	wait();
	m_.shared_unlock();
}
