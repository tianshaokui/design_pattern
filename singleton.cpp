class Singleton
{
public:
	static Singleton *GetInstance()
	{
		if (m_Instance == NULL )
		{
			Lock(); // C++没有直接的Lock操作，请使用其它库的Lock，比如Boost，此处仅为了说明
			if (m_Instance == NULL )
			{
				m_Instance = new Singleton ();
			}
			UnLock(); // C++没有直接的Lock操作，请使用其它库的Lock，比如Boost，此处仅为了说明
		}
		return m_Instance;
	}
	static void DestoryInstance()
	{
		if (m_Instance != NULL )
		{
			delete m_Instance;
			m_Instance = NULL ;
		}
	}
private:
	Singleton(){}
	static Singleton *m_Instance;
};
Singleton *Singleton ::m_Instance = NULL;
