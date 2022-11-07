//
// Created by Rares on 10/26/2022.
//

#ifndef TEMA1_DATE_H
#define TEMA1_DATE_H
class date
{
public:
    int day;
    int month;
    int year;

    bool operator==(const date &rhs) const {
        return day == rhs.day &&
               month == rhs.month &&
               year == rhs.year;
    }

    bool operator!=(const date &rhs) const {
        return !(rhs == *this);
    }

};
#endif //TEMA1_DATE_H
