#include <gtest/gtest.h>
#include "qsort.cpp"
#include "iostream"
using namespace std;

TEST(QuickSortTest, SortEmpty)
{
    std::vector<int> v;
    quick_sort(v.begin(), v.end(), std::less<int>());
    cout<<"--"<<endl;
    std::vector<int> expected;
    ASSERT_EQ(v, expected);
}

TEST(QuickSortTest, SortVectorWithOneElement)
{

    std::vector<int> v{1};
    quick_sort(v.begin(), v.end(), std::less<int>());

    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<endl;
    }
    std::vector<int> expected{1};
    ASSERT_EQ(v, expected);
}

// TODO: Add more tests here
// 比较器函数对象，按照升序排序
TEST(QuickSortTest, SortVectorWithOneElement2)
{

    std::vector<int> v{5,7,1,3,6};
    quick_sort(v.begin(), v.end(), std::less<int>());

    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<endl;
    }
    std::vector<int> expected{1,3,5,6,7};
    ASSERT_EQ(v, expected);
}

TEST(QuickSortTest, SortVectorWithOneElement3)
{

    std::vector<int> v{6,1,2,7,9,3,4,5,10,8};
    quick_sort(v.begin(), v.end(), std::less<int>());

    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<endl;
    }
    std::vector<int> expected{1,2,3,4,5,6,7,8,9,10};
    ASSERT_EQ(v, expected);
}