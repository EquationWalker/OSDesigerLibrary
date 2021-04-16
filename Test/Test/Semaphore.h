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
	public:
		union semun {
			int val; /* Value for SETVAL */
		};
		Semaphore(int n = 1);
		~Semaphore();
		void acquire(int n = 1);
		bool tryAcquire(int n = 1);
		int available()const;
		void release(int n = 1);
	private:
		int m_sem_id;
		sembuf m_semop;
		semun m_ctl;

	};
}