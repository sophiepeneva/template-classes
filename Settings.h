# template-classes

#pragma once
#include "Pair.h"
template <typename T>
class Settings
{
public:
	Settings(const Pair<T>* container = nullptr, int elements = 0);
	Settings(const Settings&);
	Settings& operator=(const Settings& s);
	~Settings();

	int count() const { return m_elements; }
	void set(const char* key, T value);
	bool get(const char* key, T& value);
private:
	void Destroy();
	void Copy(const Settings& s);
	Pair<T> * m_container;
	int m_elements;
};

template <typename T>
Settings<T>::Settings(const Pair<T>* container, int elements) : m_elements(elements)
{
	m_container = new Pair<T>[elements];
	for (int i = 0;i < m_elements;i++)
	{
		m_container[i] = container[i];
	}
}

template <typename T>
Settings<T>::~Settings()
{
	Destroy();
}

template <typename T>
Settings<T>::Settings(const Settings<T>& s)
{
	Copy();
}

template <typename T>
Settings<T>& Settings<T>::operator=(const Settings<T>& s)
{
	if (this != &p) {
		Destroy();
		Copy();
	}
}

template <typename T>
void Settings<T>::Destroy()
{
	delete[] m_container;
}

template <typename T>
void Settings<T>::Copy(const Settings<T>& s)
{
	m_elements = s.m_elements;
	m_container = new Pair[s.m_elements];
	for (int i = 0;i < m_elements;i++)
	{
		m_container[i] = s.m_container[i];
	}
}

template <typename T>
void Settings<T>::set(const char* key, T value)
{
	if (get(key, value) == false) {
		Pair<T>* temp = new Pair<T>[m_elements];
		
		for (int i = 0;i < m_elements;i++) {
			temp[i] = m_container[i];
		}
		m_container = new Pair<T>[++m_elements];
		for (int i = 0;i < m_elements - 1;i++) {
			m_container[i] = temp[i];
		}
		Pair<T> newPair(key, value);

		m_container[m_elements-1] = newPair;		
	}
}

template <typename T>
bool Settings<T>::get(const char* key, T& value)
{
	bool found = false;
	for (int i = 0;i < m_elements;i++)
	{
		if (strcmp(m_container[i].getKey(), key) == 0)
		{
			found = true;
			value = m_container[i].getValue();
		}
	}
	return found;
}
