#ifndef ADatabase_H
#define ADatabase_H

#include <mutex>
#include <thread>

#include "SharedMutex.h"

class ATestDatabase{
	public:		
		void doSomething();
		
	protected:
		virtual void read() = 0;
		
		void write();
		void wait();
		
		SharedMutex m_;
		
	private:
		int randUntill(int until);
		const int WRITES_PERCENT = 10;
};

class CommonDatabase : public ATestDatabase{
	protected:
		void read() override;
};

class SharedDatabase: public ATestDatabase{
	protected:
		void read() override;
};

#endif
