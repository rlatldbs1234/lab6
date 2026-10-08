#pragma once
#include "student.h"

namespace KimSiyun2649069 //본인이름학번 네임스페이스
{
    class studentStatus //-생성자: 모든 멤버변수 초기화, 기본값 설정
    {
        student s;
        bool status;
    public:
        studentStatus(student s0=student{2649069,0,'F'}, bool st = false)
            :s{s0}, status{st}
        {}
//-print: 표준스트림출력으로 멤버변수를 출력
//-클래스1형 student형 객체 s의 접근함수를 참조형식으로 구현
        void print() const //studentStatus::print
        {
            s.print(); //studentStatus::print()
            if (status) std::cout << "on school\n";
            else std::cout << "NOT on school\n";
        }
        const student& getStudent() const {return s;}
        void setStudent(const student& s0){s=s0;}
    };
}