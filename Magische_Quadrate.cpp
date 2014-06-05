#include <iostream>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "meine_eingabe.h"
#include "Magisches_Quadrat.h"
#include "Magische_Quadrate.h"

/** Konstruiert ein Objekt Magische_Quadrate  **/
Magische_Quadrate::Magische_Quadrate(Magisches_Quadrat ein_magisches_quadrat)
{
  bilde_liste_aus_einem_quadrat(ein_magisches_quadrat);
}

/** Schreibt */
void Magische_Quadrate::schreibe_quadrate()
{
  cout << "\n\nEs wurden " << magische_q.size() << " magische Quadrate aus der magischen Zahl " << magische_q[0].liefere_ausgangszahl() << " erstellt:\n\n";
  for(unsigned int i = 0; i < magische_q.size(); i++)
  {
    magische_q[i].schreibe_quadrat();
    cout << "\n\n";
  }
}

/** Diese Funktion schreibt die magischen Quadrate in eine Textdatei mit einem uebergebenen Namen fuer die Textdatei 
  * @param datei_name Ein Name fuer die Textdatei.
  */
void Magische_Quadrate::schreibe_liste_in_datei(string datei_name)
{
  string name = ueberpruefe_ob_file_existiert(datei_name);
  fstream f;
  f.open(name.c_str(), ios::out);
  f << "\n\nEs wurden " << magische_q.size() << " magische Quadrate aus der magischen Zahl " << magische_q[0].liefere_ausgangszahl() << " erstellt:\n\n";
  for(unsigned int i = 0; i < magische_q.size(); i++)
  {
    vector<int> x = magische_q[i].liefere_quadrat();
    for(unsigned int k = 1; k < x.size(); k++)
    {
      f << setw(4) << x[k];
      if(k > 0 && k % magische_q[0].liefere_ausgangszahl() == 0)
        f << "\n";
    }
    f << "\n\n";
  }
  f.close();
}

/** Diese Funktion prueft ob die Datei mit gewuenschten Namen bereits existiert. 
  * Wenn der Name bereits vergeben wurde, so hat der Nutzer die Moeglichkeit einen neuen Namen zu vergeben 
  * oder die bereits bestehende Datei zu ueberschreiben.
  * @param name Der Dateiname.
  */
string Magische_Quadrate::ueberpruefe_ob_file_existiert(string name)
{
  string file_name = name;
  bool ok = false;
  do
  {
    ifstream FileTest(file_name.c_str());
    if (FileTest && ok == false)
    {
      int eingabe = 0;
      cout << "\nDie Datei " + file_name + " existiert bereits!\n";
      cout << "Soll die Datei ueberschrieben werden [0] oder moechten Sie eine neue angeben[1]?\n";
      cout << "Ihre Wahl: ";
      eingabe = erfasse_int(0,1);
      if (eingabe == 1)
      {
        cout << "\nBitte geben Sie den Namen Ihrer neuen Datei an: ";
        erfasse_zeichenkette(file_name);
      }
      else
        ok = true;
    }
    else
    {
      ok = true;
      FileTest.close();
    }
  } while (!ok);
  return file_name;
}

/** Diese Funktion prueft ob ein Magisches Quadrat schon vorhanden ist.
  * @param ein_m_quadrat
  * @return Wird true wenn wenn das Quadrat schon existiert, false wenn es nicht existiert.
  */
bool Magische_Quadrate::pruefe_ob_vorhanden(Magisches_Quadrat ein_m_quadrat)
{
  bool ok = false;
  for(unsigned int i = 0; i < magische_q.size(); i++)
  {
    if(magische_q[i] == ein_m_quadrat)
      ok = true;
  }
  return ok;
}

/** Diese Funktion 
void Magische_Quadrate::bilde_liste_aus_einem_quadrat(Magisches_Quadrat ein_magisches_quadrat)
{
  unsigned int vorher = 0;
  unsigned int nachher = 1;
  magische_q.push_back(ein_magisches_quadrat);
  while(vorher != nachher)
  {
    nachher = 1;
    vorher = magische_q.size();
    for(unsigned int i = 0; i < magische_q.size(); i++)
    {
      vector<Magisches_Quadrat> x = magische_q[i].vertausche_spalten();
      for(unsigned int k = 0; k < x.size(); k++)
        if(!pruefe_ob_vorhanden(x[k]))
          magische_q.push_back(x[k]);
      vector<Magisches_Quadrat> y = magische_q[i].vertausche_zeilen();
      for(unsigned int w = 0; w < y.size(); w++)
        if(!pruefe_ob_vorhanden(y[w]))
          magische_q.push_back(y[w]);
      vector<Magisches_Quadrat> z = magische_q[i].spiegeln_dia();
      for(unsigned int u = 0; u < z.size(); u++)
        if(!pruefe_ob_vorhanden(z[u]))
          magische_q.push_back(z[u]);
      Magisches_Quadrat l = magische_q[i].drehe_90_grad();
      if(!pruefe_ob_vorhanden(l))
        magische_q.push_back(l);
      Magisches_Quadrat b = magische_q[i].drehe_180_grad();
      if(!pruefe_ob_vorhanden(b))
        magische_q.push_back(b);
      Magisches_Quadrat g = magische_q[i].drehe_270_grad();
      if(!pruefe_ob_vorhanden(g))
        magische_q.push_back(g);
    }
    nachher = magische_q.size();
  }
}
