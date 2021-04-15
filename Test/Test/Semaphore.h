#pragma once
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/sem.h>

namespace liuxin
{
	class Semaphore {
	private:
		struct sembuf {
			unsigned short sem_num;
			short sem_op;
			short sem_flg;
		};
		union semun {
			int val; /* Value for SETVAL */
		};
		int m_sem_id;
	public:
		Semaphore(int n = 1);
		~Semaphore();
		void acquire(int n = 1);
		bool tryAcquire(int n = 1);
		int available()const;
		void release(int n = 1);
	};
}