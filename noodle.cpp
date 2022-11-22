//
// Created by Rares on 11/2/2022.
//

#include "noodle.h"

noodle &noodle::operator=(const noodle &other) {
    cooked = other.cooked;
    return *this;
}
