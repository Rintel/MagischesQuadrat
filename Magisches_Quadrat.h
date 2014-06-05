/* 
 * File:   Magisches_Quadrat.h
 * Author: Cedric Laier
 *
 * Created on 7. Januar 2014, 15:26
 */

#ifndef MAGISCHES_QUADRAT_H
#define	MAGISCHES_QUADRAT_H
#include <vector>

using namespace std;

class Magisches_Quadrat
{
private:
    vector<int> magisches_q;
    int ausgangszahl;
    
public:
    Magisches_Quadrat(int angabe_ausgangszahl);
    Magisches_Quadrat(vector<int> ein_vector, int angabe_ausgangszahl);
    
    int liefere_ausgangszahl();
    vector<int> liefere_quadrat();
    void schreibe_quadrat();
    Magisches_Quadrat drehe_90_grad() const;
    Magisches_Quadrat drehe_180_grad() const;
    Magisches_Quadrat drehe_270_grad() const;
    bool operator==(Magisches_Quadrat ein_m_quadrat) const;
    vector<Magisches_Quadrat> vertausche_spalten() const;
    vector<Magisches_Quadrat> vertausche_zeilen() const;
    vector<Magisches_Quadrat> spiegeln_dia() const;
    
private:
    vector<int> liefere_magisches_quadrat(int angabe_ausgangszahl) ;
    bool ueberpruefe_ausgangszahl(int angabe_ausgangszahl) const;
};

#endif	/* MAGISCHES_QUADRAT_H */

