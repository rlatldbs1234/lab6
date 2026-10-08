#include "student.h"
#include <array>
namespace KimSiyun2649069
{
    void printStudentArray(const student a[], const int n)
    {
        for(int i = 0 ; i < n; ++i)
            std::cout << a[i];
    }
}

int main()
{
    using namespace KimSiyun2649069;

    const int n{4};
    student a[n];
    a[0] = student{"Kim Siyun", 2649069, 99, 'A'};
    a[1].setName("Lee Siyun"); a[1].setId(2649069); a[1].setScore(89); a[1].setGrade('B');
    a[2].input();
    std::cin >> a[3];
    printStudentArray(a,n);
    std::array<student, n> arr;
    for (int i = 0; i<n; ++i)
    {
        arr.at(i) = a[i];//arr[i] = a[i];
    }
    for (const auto& arri : arr)
    {
        arri.print();
    }
    return 0;
}