# template-classes

#pragma once

template <typename T>
class Pair
{
public:
	Pair(const char* key = "NO NAME", T value = 0);
	~Pair();
	Pair(const Pair& p);
	Pair& operator=(const Pair& p);

	char* getKey() const { return m_key; }
	T getValue() const { return m_value; }
	void setValue(T value) { m_value = value; }
private:
	void Destroy();
	void Copy(const Pair& p);
	char* m_key;
	T m_value;
};

template <typename T>
Pair<T>::Pair(const char* key, T value) : m_value(value)
{
	m_key = new char[strlen(key) + 1];
	strcpy_s(m_key, strlen(key) + 1, key);
}

template <typename T>
Pair<T>::~Pair()
{
	delete[] m_key;
}

template <typename T>
Pair<T>::Pair(const Pair<T>& p)
{
	Copy(p);
}

template <typename T>
Pair<T>& Pair<T>::operator=(const Pair<T>& p)
{
	if (this != &p)
	{
		Destroy();
		Copy(p);
	}
	return *this;
}



template <typename T>
void Pair<T>::Destroy()
{
	delete[] m_key;
}

template <typename T>
void Pair<T>::Copy(const Pair<T>& p)
{
	m_value = p.m_value;
	m_key = new char[strlen(p.m_key) +1];
	strcpy_s(m_key, strlen(p.m_key) + 1, p.m_key);
}
