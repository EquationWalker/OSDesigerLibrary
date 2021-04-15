#include "Semaphore.h"
namespace liuxin {
	Semaphore::Semaphore(int n)
	{
		m_sem_id = semget((key_t)1234, 1, IPC_CREAT | IPC_EXCL | 0600);
		semun a;
		a.val = n;
		semctl(m_sem_id, 0, SETVAL, a);
	}
	Semaphore::~Semaphore()
	{
		semctl(m_sem_id, NULL, IPC_RMID);
	}
	void Semaphore::acquire(int n)
	{
		sembuf a;
		a.sem_num = 0;
		a.sem_op = -n;
		a.sem_flg = SEM_UNDO;
		semop(m_sem_id, &a, 1);
	}
	bool Semaphore::tryAcquire(int n)
	{

	}
	int Semaphore::available()const
	{

	}
	void Semaphore::release(int n)
	{
		sembuf a;
		a.sem_num = 0;
		a.sem_op = n;
		a.sem_flg = SEM_UNDO;
		semop(m_sem_id, &a, 1);
	}
}