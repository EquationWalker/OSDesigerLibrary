#include "Semaphore.h"
namespace liuxin {
	Semaphore::Semaphore(int n)
	{
		m_sem_id = semget((key_t)1234, 1, IPC_CREAT | IPC_EXCL | 0600);
		m_ctl.val = n;
		semctl(m_sem_id, 0, SETVAL, m_ctl);
	}
	Semaphore::~Semaphore()
	{
		semctl(m_sem_id, NULL, IPC_RMID);
	}
	void Semaphore::acquire(int n)
	{
		m_semop.sem_num = 0;
		m_semop.sem_op = -n;
		m_semop.sem_flg = SEM_UNDO;
		semop(m_sem_id, &m_semop, 1);
	}
	bool Semaphore::tryAcquire(int n)
	{
		m_semop.sem_num = 0;
		m_semop.sem_op = -n;
		// 不能操作时立即返回
		m_semop.sem_flg = IPC_NOWAIT;
		if (semop(m_sem_id, &m_semop, 1) == -1)
			return false;
		return true;
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