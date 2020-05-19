#pragma once

class counter
{
private:
    int val_;
public:
    counter(): val_(0){}
    ~counter(){}
    inline int value(){ return val_; }
    inline void increase(){ val_++; }
    inline void decrease(){ (val_ > 0) ? val_-- : val_= 0; }
    inline void reset(){ val_ = 0; }
};

