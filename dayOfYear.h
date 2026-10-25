#pragma once
#include <iostream>

namespace HongKildong1234567
{
    class dayOfYear
    {
        int month;
        int day;

        void testmonth()
        {
            if (month < 1 || month > 12) {
                std::cout << "Invalid number.\n"; std::exit(1);
            }
        }

        void testday()
        {
            if (day < 1 || day >32) {
                std::cout << "Invalid number.\n"; std::exit(1);
            }
        }

        public:
            dayOfYear(int m = 1, int d = 1) : month{m}, day{d} {testday(); testmonth();}
            int getmonth() const {return month;}
            int getday() const {return day;}
            void setmonth(int m) {month = m; testmonth();}
            void setday(int d) {day = d; testday();}

            void print() const
            {
                std::cout << month << '/' << day << std::endl;
            }
            void input()
            {
                std::cout << "Enter month: ";
                std::cin >> month; testmonth();
                std::cout << "Enter day: ";
                std::cin >> day; testday();
            }

            dayOfYear operator++(int)
            {
                dayOfYear old;
                old = *this;
                ++*this;
                return old;
            }

            dayOfYear& operator++()
            {
                ++day; ++month;
                return *this;
            }

            dayOfYear& operator+=(const dayOfYear& d)
            {
                *this = *this + d;
                return *this;
            }

            friend std::ostream& operator<<(std::ostream& os, const dayOfYear& d)
            {
                os << d.month << '/' << d.day << std::endl;
                return os;
            }
            friend std::istream& operator>>(std::istream& is, dayOfYear& d)
            {
                std::cout << "Enter month: ";
                is >> d.month; d.testmonth();
                std::cout << "Enter day: ";
                is >> d.day; d.testday();
                return is;
            }
            friend dayOfYear operator+(const dayOfYear& d1, const dayOfYear& d2)
            {
                return dayOfYear{d1.month+d2.month, d1.day+d2.day};
            }
            friend dayOfYear operator-(const dayOfYear& d1, const dayOfYear& d2)
            {
                return dayOfYear{d1.month-d2.month, d1.day-d2.day};
            }
            friend bool operator==(const dayOfYear& d1, const dayOfYear& d2)
            {
                return (d1.month==d2.month && d1.day==d2.day);
            }
    };
}