/* 
 * File:   magisches_q_main.cpp
 * Author: Cedric Laier
 *
 * Created on 7. Januar 2014, 15:26
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>

#include "Magisches_Quadrat.h"
#include "Magische_Quadrate.h"

using namespace std;

bool ueberpruefe_parameter(int argc, char* argv[]);

/**  Der Nutzer kann mit diesem Programm Magische Quadrate erstellen. Diese Magische Quadrate werden nach einem bestimmten Algorithmus
  *  erstellt. Hierbei ist zu beachten, dass die Anzahl der gewuenschten Quadrate mindestens groesser 2 und ungerade sein muss.
  *  Nachdem das Standart Magische Quadrat erstellt worden ist, werden unterschiedliche Operationen mit dem Quadrat ausgefuehrt.
  *  Dazu zaehlen unter anderem, dem vertauschen von Zeilen und Spalten, dem drehen der Quadrate um 90,180,270 Grad und dem spiegeln
  *  des Quadrates an der Hauptdiagonale und der Nebendiagonale. Alle Operationen werden auf dem Bildschirm ausgegeben und gleichzeitig in
  *  die Textdatei 'magische_Quadrate.txt' geschrieben. Diese Datei wird im gleichen Ordner wie in dem des Programmes erstellt. 
  */

int main(int argc, char** argv) 
{
  bool ok = ueberpruefe_parameter(argc, argv);
  if(ok == true)
  {
    Magisches_Quadrat x = Magisches_Quadrat(atof(argv[1]));
    Magische_Quadrate y = Magische_Quadrate(x);
    y.schreibe_liste_in_datei("magische_Quadrate.txt");
    y.schreibe_quadrate();
  }
}

/** Diese Funktion ueberprueft, ob die uebergebenen Programmparameter den Bedingungen des Programmes gerecht werden.
  * @param argc
  * @param argv[]
  * @return Wird true wenn die Bedingungen erfuellt worden sind, false wenn die Bedingungen nicht eingehalten werden.
  *         In diesem Falle wird dem Benutzer auf dem Bildschirm ausgegeben, wie das Programm aufzurufen ist.
  */
bool ueberpruefe_parameter(int argc, char* argv[])
{
  bool ok = true;
  if(argc != 2)
    ok = false;
  else
  {
    if((int)atof(argv[1]) < 3)
      ok = false;
    else if((int)atof(argv[1]) % 2 == 0)
      ok = false;
  }
  if(!ok)
    cout << "Aufruf: [programmname] [n]\n\nn muss ungerade und groesser 2 sein.\n\n";
  return ok;
}

