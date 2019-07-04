#ifndef TVECTOR_H
#define TVECTOR_H

const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;

using namespace std;

template <typename DATA>
class MyVec {
public:
    
    MyVec(){
        capacity = DEF_CAPACITY;
        data = new DATA[DEF_CAPACITY];
        sz = 0;
    }
    

    
    MyVec(int sz, DATA val=0):sz(sz){
        data = new DATA[max(DEF_CAPACITY, 2 * sz)];
        capacity = max(DEF_CAPACITY, 2 * sz);
        for(int i=0; i < sz; i++){
            data[i] = val;
        }
    }
    
    MyVec(const MyVec<DATA>& v2){
        copy(v2);
    }
    
    
    
    ~MyVec(){
        delete [] data;
    }
    
    
    MyVec<DATA>& operator=(const MyVec<DATA>& v2){
        if (this != &v2) {
            delete [] data;
            copy(v2);
        }
        return *this;
    }
    
    
    void push_back(DATA val) {
        if (sz == capacity) {
            cout << "Increasing capacity\n";
            capacity *= CAPACITY_MULT;
            DATA* old_data = data;
            data = new DATA[capacity];
            for (int i = 0; i < sz; i++) {
                data[i] = old_data[i];
            }
            delete [] old_data;
        }
        data[sz] = val;
        sz++;
    }
    
    
    
    int size() const { return sz; }
    
    
    DATA operator[](int i) const{
        return data[i];
    }
    
    
    DATA& operator[](int i){
        return data[i];
    }
    
    
private:
    void copy(const MyVec<DATA>& v2){
        sz = v2.sz;
        capacity = v2.capacity;
        data = new DATA[capacity];
        for (int i = 0; i < sz; i++) {
            data[i] = v2.data[i];
        }
    }
    
    DATA* data;
    int sz;
    int capacity;
};

template <typename DATA>

void print_vector(const MyVec<DATA>& v) {
    cout << "[";
    for(int i = 0; i < v.size(); i++){
         std::cout << v[i];
            if(i != (v.size() - 1)){cout <<",";}
        }
    cout << "]" << endl;
}


template <typename DATA>

bool operator==(MyVec<DATA>& v1, MyVec<DATA>& v2) {
    if ((v1.size() != v2.size())) {
        cout << "SIZE NOT EQUAL";
        return false;
    }
    for (int i = 0; i < v1.size() ; i++) {
        if (v1[i] != v2[i]) {
            cout << "SOMETHING DIFFERENT";
            return false;
        }
    }
    return true;
}

#endif
