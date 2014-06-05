#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <cmath>
#include <iomanip>
#include "Magisches_Quadrat.h"

using namespace std;

/**
  *
  *
  */
Magisches_Quadrat::Magisches_Quadrat(int angabe_ausgangszahl)
{
  if(ueberpruefe_ausgangszahl(angabe_ausgangszahl) == false)
    cout << "Eingabefehler";
  else
  {
    ausgangszahl = angabe_ausgangszahl;
    magisches_q = liefere_magisches_quadrat(angabe_ausgangszahl);
  }
}

/**
	*
	*
	*/
Magisches_Quadrat::Magisches_Quadrat(vector<int> ein_vector, int angabe_ausgangszahl) 
{
  magisches_q = ein_vector;
  ausgangszahl = angabe_ausgangszahl;
}

/** Diese FUnktion liefert die Ausgangszahl des magischen Quadrates. */
int Magisches_Quadrat::liefere_ausgangszahl()
{
  return ausgangszahl;
}

/** Diese Funktion liefert das magische Quadrat */
vector<int> Magisches_Quadrat::liefere_quadrat()
{
  return magisches_q;
}

/**
	*
  *
  *
  */
vector<int> Magisches_Quadrat::liefere_magisches_quadrat(int angabe_ausgangszahl) 
{
  int n = angabe_ausgangszahl;
  int n2 = (n*angabe_ausgangszahl);
  vector<int> quadrat;
  for(int i = 0; i < (n2 + 1); i++)
    quadrat.push_back(0);
  int s = 1;
  int position = (int)((n / 2) + 1);
  quadrat[position] = s;
  while(s < n2)
  {
    s++;
    if(((position - n) < 0) && (((position + 1) % n) != 1))
    {
      position += 1;
      while(position <= n2)
        position += n;
      position -= n;
    }
    else if(((position - n) > 0) && (((position + 1) % n) != 1))
    {
      if(quadrat[((position - n) + 1)] == 0)
        position = (position - n) + 1;
      else
        position += n;
    }
    else if(((position - n) > 0) && ((position + 1) % n) == 1)
    {
      position -= n;
      position = (position - n) + 1;
    }
    else if(((position - (n + 1)) < 0) && ((position + 1) % n) == 1)
      position += n;
    quadrat[position] = s;
    cout << "\n\n \n";
  }
  return quadrat;
}

/** Diese Funktion ueberprueft, ob die Ausgangszahl (Groesse der Quadrate) nicht den Bedingungen zum erstellen der Quadrate
  * entspricht.
  */
bool Magisches_Quadrat::ueberpruefe_ausgangszahl(int angabe_ausgangszahl) const
{
  bool ok = true;
  if (angabe_ausgangszahl < 3)
    ok = false;
  else if (angabe_ausgangszahl % 2 == 0)
    ok = false;
  return ok;
}

/** Diese Funktion gibt die Magischen Quadrate auf dem Bildschirm aus */ 
void Magisches_Quadrat::schreibe_quadrat()
{
  for(unsigned int i = 1; i < magisches_q.size(); i++)
  {
    cout << setw(4) << magisches_q[i];
    if(i > 0 && i % ausgangszahl == 0)
      cout << "\n";
  }
}

/** Diese Funtion vertauscht die Spalten in einem Magischen Quadrat miteinander */
vector<Magisches_Quadrat> Magisches_Quadrat::vertausche_spalten() const
{
  int mittel_spalte = (int)((ausgangszahl / 2) + 1);
  vector<vector<int> > rueckgabe(mittel_spalte - 1, vector<int>(0));
  int count = 1;
  while(count < mittel_spalte)
  {
    vector<int> anfangs_vec = magisches_q;
    vector<int> zwsp;
    for(int i = 0; i < ausgangszahl; i++)
      zwsp.push_back(anfangs_vec[count + (i * ausgangszahl)]);
    int spalte = (ausgangszahl - count) + 1;
    for(int k = 0; k < ausgangszahl; k++)
      anfangs_vec[count + (k * ausgangszahl)] = anfangs_vec[spalte + (k * ausgangszahl)];
    for(int g = 0; g < ausgangszahl; g++)
      anfangs_vec[spalte + (g * ausgangszahl)] = zwsp[g];
    for(unsigned int z = 0; z < anfangs_vec.size(); z++)
      rueckgabe[count - 1].push_back(anfangs_vec[z]);
    count++;
  }
  vector<Magisches_Quadrat> x;
  for(unsigned int i = 0; i < rueckgabe.size(); i++)
    x.push_back(Magisches_Quadrat(rueckgabe[i], ausgangszahl));
  return x;
}


/** Diese Funtion vertauscht die Zeilen ein einem Magischen Quadrat miteinander */
vector<Magisches_Quadrat> Magisches_Quadrat::vertausche_zeilen() const
{
  int mittel_zeile = (int)((ausgangszahl / 2) + 1);
  vector<vector<int> > rueckgabe(mittel_zeile - 1, vector<int>(0));
  int count = 1;
  while(count < mittel_zeile)
  {
    vector<int> anfangs_vec = magisches_q;
    vector<int> zwsp;
    for(int i = 0; i < ausgangszahl; i++)
      zwsp.push_back(anfangs_vec[((count - 1) * ausgangszahl + 1) + i]);
    int zeile_pos = 1 + ((mittel_zeile + (mittel_zeile - count) - 1) * ausgangszahl);
    for(int k = 0; k < ausgangszahl; k++)
      anfangs_vec[((count - 1) * ausgangszahl + 1) + k] = anfangs_vec[zeile_pos + k];
    for(int g = 0; g < ausgangszahl; g++)
      anfangs_vec[zeile_pos + g] = zwsp[g];
    for(unsigned int z = 0; z < anfangs_vec.size(); z++)
      rueckgabe[count - 1].push_back(anfangs_vec[z]);
    count++;
  }
  vector<Magisches_Quadrat> x;
  for(unsigned int i = 0; i < rueckgabe.size(); i++)
    x.push_back(Magisches_Quadrat(rueckgabe[i], ausgangszahl));
  return x;
}

/** Diese Funtion spiegelt an der Haupt- und Nebendiagonale in einem Magischen Quadrat*/
vector<Magisches_Quadrat> Magisches_Quadrat::spiegeln_dia() const
{
  int a = 1;
  int temp = 0;
  vector<vector<int> > rueckgabe(2, vector<int>(ausgangszahl * ausgangszahl + 1));
  vector<vector<int> > x(ausgangszahl, vector<int>(ausgangszahl));
  for(int i = 0; i < ausgangszahl; i++)
    for(int k = 0; k < ausgangszahl; k++)
    {
      x[i][k] = magisches_q[a]; 
      a++;
    }
  for(int z = 0; z < ausgangszahl; z++)
    for(int j = z+1; j < ausgangszahl; j++)
    {
      temp = x[z][j];
      x[z][j] = x[j][z];
      x[j][z] = temp;
    }
  int q = 1;
  for(int i = 0; i < ausgangszahl; i++)
    for(int k = 0; k < ausgangszahl; k++)
    {
      rueckgabe[0][q] = x[i][k];
      q++;
    }
  a = 1;
  for(int i = 0; i < ausgangszahl; i++)
    for(int k = 0; k < ausgangszahl; k++)
    {
      x[i][k] = magisches_q[a]; 
      a++;
    }
  for(int m = 0; m < ausgangszahl; m++)
  {
    for(int j = 0; j < ausgangszahl - m; j++)
    {
      swap(x[m][j], x[ausgangszahl - 1 - j][ausgangszahl - 1 - m]);
    }
  }
  q = 1;
  for(int i = 0; i < ausgangszahl; i++)
    for(int k = 0; k < ausgangszahl; k++)
    {
      rueckgabe[1][q] = x[i][k];
      q++;
    }
  vector<Magisches_Quadrat> e;
  for(unsigned int i = 0; i < rueckgabe.size(); i++)
    e.push_back(Magisches_Quadrat(rueckgabe[i], ausgangszahl));
  return e;
}

/** Diese Funktion dreht das Magische Quadrat um 90 Grad */ 
Magisches_Quadrat Magisches_Quadrat::drehe_90_grad() const
{
  vector<int> rueck;
  vector<vector<int> > x(ausgangszahl, vector<int>(ausgangszahl));
  vector<vector<int> > y(ausgangszahl, vector<int>(ausgangszahl));
  int a = 1;
  for(int i = 0; i < ausgangszahl; i++)
    for(int k = 0; k < ausgangszahl; k++)
    {
      x[i][k] = magisches_q[a];
      a++;
    }
  for (int i = 0; i < ausgangszahl; ++i) 
    for (int j = 0; j < ausgangszahl; ++j) 
      y[i][j] = x[ausgangszahl - j - 1][i];
  rueck.push_back(0);
  for(int i = 0; i < ausgangszahl; i++)
    for(int k = 0; k < ausgangszahl; k++)
      rueck.push_back(y[i][k]);
  Magisches_Quadrat e = Magisches_Quadrat(rueck, ausgangszahl);
  return e;
}

/** Diese Funktion dreht das Magische Quadrat um 180 Grad */
Magisches_Quadrat Magisches_Quadrat::drehe_180_grad() const
{
  Magisches_Quadrat x = drehe_90_grad();
  Magisches_Quadrat rueckgabe = x.drehe_90_grad();
  return rueckgabe;
}

/** Diese Funktion dreht das Magische Quadrat um 270 Grad */
Magisches_Quadrat Magisches_Quadrat::drehe_270_grad() const
{
  Magisches_Quadrat x = drehe_180_grad();
  Magisches_Quadrat rueckgabe = x.drehe_90_grad();
  return rueckgabe;
}

/** Diese Funktion vergleich zwei Magische Quadrate mit einander.
  * @param ein_m_quadrat Ein Magisches Quadrat
  * @return Wird true wenn 
bool Magisches_Quadrat::operator ==(Magisches_Quadrat ein_m_quadrat) const
{
  bool ok = true;
  if(ausgangszahl != ein_m_quadrat.liefere_ausgangszahl())
    ok = false;
  else
  {
    vector<int> x = ein_m_quadrat.liefere_quadrat();
    for(unsigned int i = 1; i < x.size(); i++)
    {
      if(x[i] != magisches_q[i])
      {
        ok = false;
        i = x.size();
      }
    }
  }
  return ok;
}


