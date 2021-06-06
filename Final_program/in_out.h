#ifndef IN_OUT_H
#define IN_OUT_H

#include <iostream>
#include <iomanip>
#include <limits>
#include "L_int.h"
#include "L_nat.h"
#include "L_pol.h"
#include "L_rat.h"

void outN(const LongN&);
void outZ(const LongZ&);
void outQ(const LongQ&);
void outP(const LongP&);

void inputN(LongN&);
void inputZ(LongZ&);
void inputQ(LongQ&);
void inputP(LongP&);

#endif // IN_OUT_H
