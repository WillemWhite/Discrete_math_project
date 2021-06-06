#ifndef INTERF_FUNC_H
#define INTERF_FUNC_H

#include <iostream>
#include <iomanip>
#include "L_int.h"
#include "L_nat.h"
#include "L_pol.h"
#include "L_rat.h"
#include "in_out.h"

char mainMenu();
void intMenu();
void natMenu();
void ratMenu();
void polMenu();

// Naturals.
void comNNtoDmMenu();
void notZeroNtoBmMenu();
void add1NtoNmMenu();
void addNNtoNmMenu();
void subNNtoNmMenu();
void mulNDtoNmMenu();
void mulNktoNmMenu();
void mulNNtoNmMenu();
void subNDNtoNmMenu();
void divNNtoDkmMenu();
void divNNtoNmMenu();
void modNNtoNmMenu();
void GCFofNNtoNmMenu();
void LCMofNNtoNmMenu();

// Integers.
void comZZtoBmMenu();
void absZtoNmMenu();
void pozZtoDmMenu();
void mulZMtoZmMenu();
void transNtoZmMenu();
void transZtoNmMenu();
void addZZtoZmMenu();
void subZZtoZmMenu();
void mulZZtoZmMenu();
void divZZtoZmMenu();
void modZZtoZmMenu();

// Rationals.
void comQQtoBmMenu();
void redQtoQmMenu();
void intQtoBmMenu();
void transZtoQmMenu();
void transQtoZmMenu();
void addQQtoQmMenu();
void subQQtoQmMenu();
void mulQQtoQmMenu();
void divQQtoQmMenu();

// Polynomials.
void comPPtoBmMenu();
void addPPtoPmMenu();
void subPPtoPmMenu();
void mulPQtoPmMenu();
void mulPxktoPmMenu();
void ledPtoQmMenu();
void degPtoNmMenu();
void facPtoQmMenu();
void mulPPtoPmMenu();
void divPPtoPmMenu();
void modPPtoPmMenu();
void GCFofPPtoPmMenu();
void derPtoPmMenu();
void NMRofPtoPmMenu();

#endif
