#pragma once
#include "../include/dni.hpp"
#include "../include/counter.hpp"



counter dni::cntr_; 
dni::dni()
{
    value_ = rand() % BOUND;
    lvalue_ = value_;
    length_ = std::to_string(value_).length();
}


dni::dni(int seed)
{   srand(seed);
    value_ = rand() % BOUND;
    length_ = std::to_string(value_).length();
}

dni::~dni(){}


int dni::nth_compare() { return dni::cntr_.value(); }
void dni::reset_c(void) { dni::cntr_.reset(); }
std::ostream& operator<< (std::ostream& os, dni& dni_t)
{
    switch( dni_t.length() )
    {
        case 0:
            os << " 0000000" <<  dni_t.value() << " ";
            break;    
        case 1:
            if (dni_t.value() != -1)
                os << " 0000000" <<  dni_t.value() << " ";
            else 
                os << "          ";  
            break;

        case 2:
            if (dni_t.value() != -1)
                os << " 000000" <<  dni_t.value() << " ";
            else 
                os << "          ";            
            break;

        case 3:
            if (dni_t.value() != -1)    
                os << " 00000" <<  dni_t.value() << " ";
            else 
                os << "          ";            
            break;

        case 4:
            if (dni_t.value() != -1)    
                os << " 0000" <<  dni_t.value() << " ";
            else 
                os << "          ";            
            break;

        case 5:
            if (dni_t.value() != -1)    
                os << " 000" <<  dni_t.value() << " ";
            else 
                os << "          ";            
            break;

        case 6:
            if (dni_t.value() != -1)    
                os << " 00" <<  dni_t.value() << " ";
            else 
                os << "          ";            
            break;

        case 7:

            if (dni_t.value() != -1)
                os << " 0" <<  dni_t.value() << " ";
            else 
                os << "          ";            
            break;

        case 8:
            if (dni_t.value() != -1)
                os << " " <<  dni_t.value() << " ";
            else 
                os << "          ";
            break;

        default:
            os << " XXXXXXXX ";
            break;
    }
    return os;
}

bool dni::operator== (dni& r_value)
{
    dni::cntr_.increase();
    return value() == r_value.value();
}
bool dni::operator!= (dni& r_value)
{
    dni::cntr_.increase();
    return value() != r_value.value();
}
bool dni::operator> (dni& r_value)
{
    dni::cntr_.increase();
    return value() > r_value.value();
}
bool dni::operator< (dni& r_value)
{
    dni::cntr_.increase();
    return value() < r_value.value();
}
bool dni::operator>= (dni& r_value)
{
    dni::cntr_.increase();
    return value() >= r_value.value();
}
bool dni::operator<= (dni& r_value)
{
    dni::cntr_.increase();
    return value() <= r_value.value();
}


dni::operator unsigned long() const
{
    return lvalue_;
}


void dni::inc(void)
{
    cntr_.increase();
}