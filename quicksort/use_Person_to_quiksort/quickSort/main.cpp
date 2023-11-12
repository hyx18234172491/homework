#include <iostream>

#include "vector"

template<typename RandomAccessIter, typename Comparator>
void quick_sort(RandomAccessIter first, RandomAccessIter last, Comparator comparator) {
    if (first >= last - 1) {
        return;
    }
    RandomAccessIter pivot = first;
    RandomAccessIter i = first + 1;
    RandomAccessIter j = last - 1;
    while (i <= j) {
        while (i <= j && comparator(*i, *pivot)) {
            i++;
        }
        while (i <= j && !comparator(*j, *pivot)) {
            j--;
        }
        if (i < j) {
            std::iter_swap(i, j);
        }
    }
    std::iter_swap(pivot, j);
    quick_sort(first, j, comparator);
    quick_sort(j + 1, last, comparator);

}

using namespace std;

class Person {
public:
    int age;
    int height;

public:
    Person(int age, int height) {
        this->age = age;
        this->height = height;
    }
};

bool cmp(Person person1, Person person2) {
    return person1.age > person2.age;
}


int main() {
    Person person1(10, 0);
    Person person2(5, 0);
    Person person3(9, 0);
    vector<Person> vec_person({person1, person2,person3});
    quick_sort(vec_person.begin(), vec_person.end(), cmp);
//
//    for (vector<Person>::iterator i = vec_person.begin(); i < vec_person.end(); i++) {
//        cout << (*i).age << endl;
//    }

    vector<int>a;
    a.push_back(10);
    a.push_back(9);
    a.push_back(15);
    a.push_back(17);

    int nums = a.size();
    // 两种遍历vector的方式
    // 1. 直接索引
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<endl;
    }
    // 2. 迭代器
    for(vector<int>::iterator i= a.begin(); i<a.end();i++){
        cout<<"is:" << (*i) <<endl;
        *i = 10;
    }

    for(int i=0;i<a.size();i++){
        cout<<a[i]<<endl;
    }

//    int b=10;
//    int *c = &b;
//    cout<<*c<<endl;
//
//
//    int a1[10];
//    for(int i=0;i<sizeof(a1);i++){
//        cout<<a1[i]<<endl;
//    }
    return 0;
}
