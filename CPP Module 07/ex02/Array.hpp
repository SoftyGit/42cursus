#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
	private:
		T* 		_array;
		size_t	_len;
	public:
		Array() : _len(0) {
			_array = new T[0];
		}
		Array(size_t n) : _len(n) {
			_array = new T[n];
		}
		~Array() {
			if (_array)
				delete[] _array;
		}
		Array(const Array<T>& srcs) {
			_len = srcs.size();
			_array = new T[_len];
			for (size_t i = 0; i < _len; i++)
				_array[i] = srcs._array[i];
		}

		T& operator[] (size_t len) {
			if (len >= _len)
				throw(OutOfBoundException());
			return _array[len];
		}
		const T& operator[] (size_t len) const {
			if (len >= _len)
				throw(OutOfBoundException());
			return _array[len];
		}

		Array<T>& operator= (const Array<T>& srcs) {
			if (this != &srcs) {
				delete[] _array;
				_len = srcs.size();
				_array = new T[_len];
				for (size_t i = 0; i < _len; i++)
					_array[i] = srcs._array[i];
			}
			return *this;
		}
		size_t size() const {
			return _len;
		}

		class OutOfBoundException : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return "Out of Bound!";
				}
		};
};

#endif
