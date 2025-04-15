/*#include <gtest/gtest.h>

extern "C" {
    #include "calcolatrice.h"
}

TEST(CalcolatriceTest, Somma) {
    EXPECT_DOUBLE_EQ(somma(2.0, 3.0), 5.0);
}

TEST(CalcolatriceTest, DivisioneByZero) {
    EXPECT_DOUBLE_EQ(divisione(10.0, 0.0), 0.0);  // gestione errore
}*/

#include <gtest/gtest.h>

extern "C" {
    #include "calcolatrice.h"
}

TEST(CalcolatriceTest, Somma) 
{
    EXPECT_DOUBLE_EQ(somma(2.0, 3.0), 5.0);
}

TEST(CalcolatriceTest, Sottrazione) {
    EXPECT_DOUBLE_EQ(sottrazione(5.0, 3.0), 2.0);
}

TEST(CalcolatriceTest, Moltiplicazione) {
    EXPECT_DOUBLE_EQ(moltiplicazione(3.0, 2.0), 6.0);
}

TEST(CalcolatriceTest, Divisione) {
    EXPECT_DOUBLE_EQ(divisione(10.0, 2.0), 5.0);
}

/*
Comandi per la compilazione e l'esecuzione dei test:
g++ testCalcolatrice.cpp calcolatrice.c -lgtest -lgtest_main -pthread -o testCalcolatrice
./testCalcolatrice
*/