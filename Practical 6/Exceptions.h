//u21582735 Siyamthanda Ndlovu
//File for all exception definitions
//See spec for inclusion strategy

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <sstream>


class AboveWeightEx {
    private:
        double weightDiff;
    public:
        AboveWeightEx(double wd);
        double getDifference() const;
};


class EmptyEx{
};


class UnauthorisedEx{
};


//class UndervaluedEx
template <class E>
class UndervaluedEx{
    private:
        E* underVal;
        double sum;
    public:
        UndervaluedEx( E* uv , double s );
        E* getUndervalued() const;
        double getSum() const;
};
//class UndervaluedEx


//class NotFoundEx
template <class E>
class NotFoundEx{
    private:
        E* missing;
    public:
        NotFoundEx( E* nf );
        E* getNotFound() const;
};//so like we cannnot add Exceptions.cpp into the makefile and have it compile without working on the 
//class NotFoundEx
#endif

#include "Exceptions.cpp"