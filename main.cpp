#include <fstream>
#include <iostream>

#include "ThreadSheduler.h"
#include "TestDatabase.h"

void work(ATestDatabase& db){
	for(int i = 0; i < 200; i++) db.doSomething();
}

int main() {
	SharedDatabase db;
	Scheduler scheduler;
	for(int i = 0; i < 20; i++){
		scheduler.addThread(std::thread(work, std::ref(db)));
	}
	return 0;
}
