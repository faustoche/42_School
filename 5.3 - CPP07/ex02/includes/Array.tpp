#ifndef ARRAY_TPP
#define ARRAY_TPP

/*-------------- CONSTRUCTORS --------------*/

template<typename T>
Array<T>::Array() : _data(NULL), _size(0){}

template<typename T>
Array<T>::Array(int n) : _data(new T[n]), _size(n){}

template<typename T>
Array<T>::Array(const Array &other) : _data(NULL), _size(0){
	*this = other;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other){
	if (this != &other){
		delete[] _data;
		_size = other._size;
		_data = new T[_size];
		for (int i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array<T>(){
	delete[] _data;
}

/*-------------- [] CONSTRUCTORS --------------*/

template<typename T>
T &Array<T>::operator[](int index){
	if (index < 0 || index >= _size)
		throw (std::out_of_range("Index is out of range"));
	return (_data[index]);
}

template<typename T>
const T &Array<T>::operator[](int index) const {
	if (index < 0 || index >= _size)
		throw (std::out_of_range("Index is out of range"));
	return (_data[index]);
}

/*-------------- MEMBER FUNCTIONS --------------*/

template<typename T>
int Array<T>::size() const {
	return (_size);
}

#endif