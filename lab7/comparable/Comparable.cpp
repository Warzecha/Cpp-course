//
// Created by warzecha on 22.04.18.
//

#include "Comparable.h"

bool academia::ByFirstNameAscending::IsLess(const academia::Student &left, const academia::Student &right) {
    return left.FirstName().compare(right.FirstName()) < 0;
}

bool academia::ByFirstNameAscending::operator()(const academia::Student &left, const academia::Student &right) {
    return IsLess(left, right);
}

bool academia::ByFirstNameDescending::IsLess(const academia::Student &left, const academia::Student &right) {
    return left.FirstName().compare(right.FirstName()) > 0;
}

bool academia::ByFirstNameDescending::operator()(const academia::Student &left, const academia::Student &right) {
    return IsLess(left, right);
}

bool academia::ByLastNameAscending::IsLess(const academia::Student &left, const academia::Student &right) {
    return left.LastName().compare(right.LastName()) < 0;
}

bool academia::ByLastNameAscending::operator()(const academia::Student &left, const academia::Student &right) {
    return IsLess(left, right);
}

bool academia::ByProgramAscendingEmptyFirst::IsLess(const academia::Student &left, const academia::Student &right) {

    if(left.Program() == "")
        return true;

    if(right.Program() == "")
        return false;

    return left.Program().compare(right.Program()) < 0;

}

bool academia::ByProgramAscendingEmptyFirst::operator()(const academia::Student &left, const academia::Student &right) {
    return IsLess(left, right);
}

bool academia::ByProgramAscendingEmptyLast::IsLess(const academia::Student &left, const academia::Student &right) {
    if(left.Program() == "")
        return false;

    if(right.Program() == "")
        return false;

    return left.Program().compare(right.Program()) < 0;
}

bool academia::ByProgramAscendingEmptyLast::operator()(const academia::Student &left, const academia::Student &right) {
    return IsLess(left, right);
}
