#include <iostream>
#include <iomanip>

using namespace std;

template <class T>
class Dynamic_Array {
public:
   // constructor, initialize
   Dynamic_Array(): _data(NULL), _size(0), _capacity(0) {}

   // destructor, release memory
   ~Dynamic_Array() { delete[] _data; }

   // element access
   T& operator [] (size_t i) { return _data[i]; }

   // get size
   unsigned size() const { return _size; }

   // get capacity
   unsigned capacity() const { return _capacity; }

   // push an element to the back of the array
   void push(T val) {
      if(_size == _capacity) expand();
      _data[_size] = val;
      _size++;
   }

private:
   // expand the data array to twice the capacity
   void expand() {
      unsigned new_capacity = (_capacity == 0? 1 : 2*_capacity);
      T* new_data = new T[new_capacity];
      // copy elements
      for(unsigned i=0; i<_size; ++i)
         new_data[i] = _data[i];
      // release the old data array
      delete[] _data;
      // link the pointer to the new data array
      _data = new_data;
      _capacity = new_capacity;
   }

   // member variables
   T*          _data;      // pointer to data array
   unsigned    _size;      // number of elements
   unsigned    _capacity;  // size of data array
};

int main(){
   Dynamic_Array<int> arr;
   for(int i=1; i<=10; ++i){
      arr.push(i);
      cout << "[size = " << setw(2) << arr.size() << ", "
         << "capacity = " << setw(2) << arr.capacity() << "]: ";
      for(unsigned j=0; j<arr.size(); ++j)
         cout << arr[j] << " ";
      cout << endl;
   }
   return 0;
}