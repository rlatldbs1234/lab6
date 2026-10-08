#pragma once
#include <iostream>
#include <string>
namespace KimSiyun2649069
{
    class student
    {
        std::string name {};
        int id{};
        int score{};
        char grade{};
        void testId(){
            if (id < 1000000 || id > 9999999)
            {
                std::cout << "Invalid ID\n";
                std::exit(1);
            }
        }
        void testScore(){
            if(score < 0 || score > 100)
            {
                std::cout << "Invalid score\n";
                std::exit(1);
            }
        }
        void testGrade(){
            if (grade < 'A' || grade > 'F')
            {
                std::cout << "Invalid grade\n";
                std::exit(1);
            }
        }
        public:
        student(const std::string n = "no name yet", int d = 2649069, int s = 0, char g = 'F')
            :name{n}, id{d}, score{s}, grade{g}
        {
            testId(); testScore(); testGrade();
        }
        void input(){
            std::cout << "Enter name: ";
            std::getline(std::cin >> std::ws, name);//std::cin >> name;
            std::cout << "Enter id: ";
            std::cin >> id; testId();
            std::cout << "Enter score: ";
            std::cin >> score; testScore();
            std::cout << "Enter grade: ";
            std::cin >> grade; testGrade();
        }
        friend std::istream& operator>>(std::istream& is, student& s)
        {//input: std::cin --> is
            std::cout << "Enter name: ";
            std::getline(is >> std::ws, s.name);//is >> name;
            std::cout << "Enter id: ";
            is >> s.id; s.testId();
            std:: cout << "Enter score: ";
            is >> s.score; s.testScore();
            std:: cout << "Enter grade: ";
            is >> s.grade; s.testGrade();
            return is;
        }
        void setName(const std::string& n){name = n;}
        void setId(int d){id = d; testId();}
        void setScore(int s){score = s; testScore();}
        void setGrade(char g){grade = g; testGrade();}
        void print() const
        {
            std::cout << name << "(" << id << "): " << score << " (" << grade << ")\n";
        }
        friend std::ostream& operator<<(std::ostream& os, const student& s)
        {//print(): std::cout --> os
            os << s.name << "(" << s.id << "): " << s.score << " (" << s.grade << ")\n";
            return os;
        }
        const std::string& getName() const {return name;}
        int getId() const {return id;}
        int getScore() const {return score;}
        char getGrade() const {return grade;}
        student operator++()
        {
            return student{name, id, ++score, grade};
        }

        student operator++(int)//{return student{id, score++, grade};}
        {
            student temp{name, id, score, grade};
            score++;
            return temp;
        }
        friend bool operator==(const student& s1, const student& s2)
        {
            return s1.id == s2.id;
        }
        friend int operator+(const student& s1, const student& s2)
        {
            return s1.score + s2.score;
        }
    };
}