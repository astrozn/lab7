#pragma once
#include "dayOfYear.h"
#include <string>

namespace HongKildong1234567
{
    class holiday
    {
        std::string name;
        dayOfYear date;
        bool parking;

        public:

        holiday(std::string n = "Birthday", dayOfYear d = {1,1}, bool p = true) : name{n}, date{d}, parking{p} {}
        
        std::string getname() const {return name;}
        void setname(std::string n) {name = n;}
        dayOfYear getdate() const {return date;}
        void setdate(int m, int d) {date = dayOfYear{m,d};}
        bool getparking() const {return parking;}
        void setparking(bool p) {parking = p;}
        
        friend std::istream& operator>>(std::istream& is, holiday& h)
        {
            std::cout << "Enter holiday name: ";
            std::getline(is >> std::ws, h.name);
            is >> h.date;
            std::cout << "Enter parking(0 or 1): ";
            is >> h.parking;
            return is;
        }
        friend std::ostream& operator<<(std::ostream& os, const holiday& h)
        {
            os << h.name << ", " << h.date;
            if (h.parking) os << "yes parking\n";
            else os << "no parking\n";
            return os;
        }
    };
}