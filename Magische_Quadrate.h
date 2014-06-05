#ifndef MAGISCHE_QUADRATE_H
#define	MAGISCHE_QUADRATE_H
#include <vector>

#include "Magisches_Quadrat.h"
using namespace std;

class Magische_Quadrate
{
  /** Ein Vector aus magischen Quadraten */
  private:
    vector<Magisches_Quadrat> magische_q;
    
  public:
    Magische_Quadrate(Magisches_Quadrat ein_magisches_quadrat);
    
    vector<Magisches_Quadrat> liefere_magische_liste();
    void schreibe_liste_in_datei(string datei_name);
    void schreibe_quadrate();
    
private:
    bool pruefe_ob_vorhanden(Magisches_Quadrat ein_m_quadrat);
    void bilde_liste_aus_einem_quadrat(Magisches_Quadrat ein_magisches_quadrat);
    string ueberpruefe_ob_file_existiert(string name);
};


#endif	/* MAGISCHE_QUADRATE_H */

