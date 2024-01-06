#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

//u21582735 Siyamthanda Ndlovu
//Exception implementations
//#include "Exceptions.h" //imake am i supposed to include the cpp in the h instead?
//and then does that mean i should list this h and cpp as a dependant on planes???
//^^ how does this compile even though some of the classess are templates that havent been used yet?

using namespace std;
//AboveWeightEx
AboveWeightEx::AboveWeightEx(double wd) {
//A constructor which takes in a single parameter, to assign to its member variable
weightDiff = wd;
}

double AboveWeightEx::getDifference() const {
return weightDiff;
}
//AboveWeightEx

template<class E>
UndervaluedEx<E>::UndervaluedEx(E* uv , double s)
{
    underVal = uv;
}

template<class E>
E* UndervaluedEx<E>::getUndervalued() const
{
    return underVal;
}

template<class E>
double UndervaluedEx<E>::getSum() const
{
    return sum;
}

template<class E>
NotFoundEx<E>::NotFoundEx(E* nf)
{
    missing = nf;
}

template<class E>
E* NotFoundEx<E>::getNotFound() const
{
    return missing;
}

#endif // __EXCEPTIONS_H__