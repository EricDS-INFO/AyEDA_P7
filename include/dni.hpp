#pragma once
#include <iostream>
#include <cstdlib>


#define BOUND 100000000



class counter;
class dni
{
    private:
        int             value_;
        unsigned long   lvalue_;
        int             length_;
        static counter  cntr_;
    
    public: 
        dni();
        dni(int seed);
        ~dni();

        inline  int value() const { return value_; }
        inline  void value(int value) { value_ = value; } 
        
        static int nth_compare(); 
        inline int set_none(void){ value_ = -1;}
        inline int length() const { return length_; }

        friend std::ostream& operator<< (std::ostream& os, dni& dni_t);
        
        bool operator== (dni& r_value);
        bool operator!= (dni& r_value);
        bool operator> (dni& r_value);
        bool operator< (dni& r_value);
        bool operator>= (dni& r_value);
        bool operator<= (dni& r_value);


        operator unsigned long() const;

        static void reset_c(void);

    private:
        void inc(void);
};
