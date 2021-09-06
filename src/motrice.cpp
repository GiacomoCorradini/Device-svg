#include "motrice.h"
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <cmath>

using namespace std;

/**
 *Inizializza.
 *
 * @return puntatore a device
 */

MeniniDevice* menini_init(){
    MeniniDevice *device = new MeniniDevice;
    device->w = 0;
    device->h = 0;
    return device;
}

/**
 * resetta le dimensioni dell'immagine.Da usare in caso di modifica di un parametro: fa in modo che le misure tornino compatibili
 *
 * @param device contiene i parametri dell'immagine
 * @return un puntatore a device
 */

MeniniDevice* menini_reset(MeniniDevice* device){
    if (device==NULL){
        return NULL;
    }

    device->ruotasx.r = device->ruotadx.r;

    device->cabina.x = device->margineds;
    device->cabina.y = device->marginess;
    device->cabina.w = device->pianale.w / 3;
    device->cabina.h = device->pianale.h * 4;
    

    device->vetro.x = device->cabina.x;
    device->vetro.y = device->cabina.h /5 + device->cabina.y;
    device->vetro.w = device->cabina.w /2;
    device->vetro.h = device->cabina.h /2;

    device->pianale.x = device->cabina.x;
    device->pianale.y = device->cabina.y + device->cabina.h;
    
    device->ruotasx.y = device->pianale.y + device->pianale.h; 
    device->ruotadx.y = device->pianale.y + device->pianale.h; 

    device->w = 2 * device->pianale.w + 2 * device->margineds;// + device->pianale.w ;
    device->h = 2 * device->marginess + device->cabina.h + device->pianale.h + device->ruotadx.r + 100;

    return device;
    
}

/**
 * Controlla i vincoli per il disegno.
 *
 * @param device struttura contenente i parametri dell'svg
 * @return 0 se i parametri rispettano i vicoli, 1 altrimenti
 */

int menini_check_pianale_w(MeniniDevice* device, float new_w){
    if (device->ruotasx.x > new_w / 2 || device->ruotadx.x < new_w / 2){
        return 1;
    }else{
        return 0;
    }
}

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 * @param new_w è il nuovo parametro che si vuole inserire
 * @return 0 se il set è andato a buon fine, 1 altrimenti
 */

int menini_set_pianale_w(MeniniDevice* device, float new_w){
    if (menini_check_pianale_w(device, new_w)==1){
        return 1;
    }

    device->pianale.w = new_w;
    menini_reset(device);
    return 0;
}

/**
 * Controlla i vincoli per il disegno.
 *
 * @param device struttura contenente i parametri dell'svg
 * @return 0 se i parametri rispettano i vicoli, 1 altrimenti
 */

int menini_check_pianale_h(MeniniDevice* device, float new_h){
    if (device->ruotadx.r > new_h){
        return 1;
    }else{
        return 0;
    }
}

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 * @param new_h è il nuovo parametro che si vuole inserire
 * @return 0 se il set è andato a buon fine, 1 altrimenti
 */

int menini_set_pianale_h(MeniniDevice* device, float new_h){
    if (menini_check_pianale_h(device, new_h)==1){
        return 1;
    }

    device->pianale.h = new_h;
    menini_reset(device);
    return 0;
}

/**
 * Controlla i vincoli per il disegno.
 *
 * @param device struttura contenente i parametri dell'svg
 * @return 0 se i parametri rispettano i vicoli, 1 altrimenti
 */

int menini_check_raggi(MeniniDevice* device, float new_r){
    if (new_r > device->pianale.h){
        return 1;
    }else{
        return 0;
    }
}

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 * @param new_r è il nuovo parametro che si vuole inserire
 * @return 0 se il set è andato a buon fine, 1 altrimenti
 */

int menini_set_raggi(MeniniDevice* device, float new_r){
    if (menini_check_raggi(device, new_r)==1){
        return 1;
    }

    device->ruotadx.r = new_r;
    menini_reset(device);
    return 0;
}

/**
 * Controlla i vincoli per il disegno.
 *
 * @param device struttura contenente i parametri dell'svg
 * @return 0 se i parametri rispettano i vicoli, 1 altrimenti
 */

int menini_check_ruotasx(MeniniDevice* device, float new_x){
    if (new_x > device->pianale.w / 2 || new_x < 0){
        return 1;
    }else{
        return 0;
    }
}

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 * @param new_x è il nuovo parametro che si vuole inserire
 * @return 0 se il set è andato a buon fine, 1 altrimenti
 */

int menini_set_ruotasx(MeniniDevice* device, float new_x){
    if (menini_check_ruotasx(device, new_x)==1){
        return 1;
    }

    device->ruotasx.x = new_x;
    menini_reset(device);
    return 0;
}

/**
 * Controlla i vincoli per il disegno.
 *
 * @param device struttura contenente i parametri dell'svg
 * @return 0 se i parametri rispettano i vicoli, 1 altrimenti
 */

int menini_check_ruotadx(MeniniDevice* device, float new_x){
    if (new_x < device->pianale.w / 2 || new_x > device->pianale.w){
        return 1;
    }else{
        return 0;
    }
}

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 * @param new_x è il nuovo parametro che si vuole inserire
 * @return 0 se il set è andato a buon fine, 1 altrimenti
 */

int menini_set_ruotadx(MeniniDevice* device, float new_x){
    if (menini_check_ruotadx(device, new_x)==1){
        return 1;
    }

    device->ruotadx.x = new_x;
    menini_reset(device);
    return 0;
}

/**
 * Crea e ritorna la stringa corrispondente al device creato
 *
 * @param device contiene i parametri dell'immagine
 * @return stringa da stampare o errore
 */
string menini_to_svg (MeniniDevice* device, int with_measures){
    if(device==NULL){
        return "ERRORE: stringa vuota";
    }
    string a;
    a += "<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='";
    a += to_string(device->cabina.w);
    a += "' height='";
    a += to_string(device->cabina.h);
    a += "' x='";
    a += to_string(device->cabina.x);
    a += "' y='";
    a += to_string(device->cabina.y);
    a += "' />\n";
    
    a += "<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='";
    a += to_string(device->vetro.w);
    a += "' height='";
    a += to_string(device->vetro.h);
    a += "' x='";
    a += to_string(device->vetro.x);
    a += "' y='";
    a += to_string(device->vetro.y);
    a += "' />\n";

    a += "<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='";
    a += to_string(device->pianale.w);
    a += "' height='";
    a += to_string(device->pianale.h);
    a += "' x='";
    a += to_string(device->pianale.x);
    a += "' y='";
    a += to_string(device->pianale.y);
    a += "' />\n";

    a += "<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='";
    a += to_string(device->ruotasx.x);
    a += "' cy='";
    a += to_string(device->ruotasx.y);
    a += "' rx='";
    a += to_string(device->ruotasx.r);
    a += "' ry='";
    a += to_string(device->ruotasx.r);
    a += "' />\n";

    a += "<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='";
    a += to_string(device->ruotadx.x);
    a += "' cy='";
    a += to_string(device->ruotadx.y);
    a += "' rx='";
    a += to_string(device->ruotadx.r);
    a += "' ry='";
    a += to_string(device->ruotadx.r);
    a += "' />\n";

    if (with_measures == 1){
        a += "<rect style='fill:#000000;stroke-width:0.310366' id='rect20' width='";
        a += to_string(device->pianale.w / 10);
        a += "' height='";
        a += to_string((float)1);
        a += "' x='";
        a += to_string(device->pianale.x + device->pianale.w);
        a += "' y='";
        a += to_string(device->pianale.y);
        a += "' />\n";

        a += "<rect style='fill:#000000;stroke-width:0.310366' id='rect21' width='";
        a += to_string(device->pianale.w / 10);
        a += "' height='";
        a += to_string((float)1);
        a += "' x='";
        a += to_string(device->pianale.x + device->pianale.w);
        a += "' y='";
        a += to_string(device->pianale.y + device->pianale.h - 1);
        a += "' />\n";

        a += "<rect style='fill:#000000;stroke-width:0.310366' id='rect22' width='";
        a += to_string((float)1);
        a += "' height='";
        a += to_string(device->pianale.h);
        a += "' x='";
        a += to_string(device->pianale.x + device->pianale.w + device->pianale.w / 12);
        a += "' y='";
        a += to_string(device->pianale.y );
        a += "' />\n";

        a += "<text xmlns='http://www.w3.org/2000/svg' x='";
        a += to_string(device->pianale.x + device->pianale.w + device->pianale.w / 10);
        a += "' y='";
        a += to_string(device->pianale.y + device->pianale.h / 2);
        a += "' fill='black' dominant-baseline='middle' text-anchor='start' font-size='8px' >";
        a += to_string(device->pianale.h);
        a += "</text>";

        //raggioruotasx
        a += "<rect style='fill:#000000;stroke-width:0.310366' id='rect23' width='";
        a += to_string((float)1);
        a += "' height='";
        a += to_string(device->ruotasx.r + device->ruotasx.r / 2);
        a += "' x='";
        a += to_string(device->ruotasx.x - (device->ruotasx.r + 1));
        a += "' y='";
        a += to_string(device->ruotasx.y);
        a += "' />\n";

        a += "<rect style='fill:#000000;stroke-width:0.310366' id='rect24' width='";
        a += to_string((float)1);
        a += "' height='";
        a += to_string(device->ruotasx.r + device->ruotasx.r / 2);
        a += "' x='";
        a += to_string(device->ruotasx.x);
        a += "' y='";
        a += to_string(device->ruotasx.y);
        a += "' />\n";

        a += "<rect style='fill:#000000;stroke-width:0.310366' id='rect25' width='";
        a += to_string(device->ruotasx.r);
        a += "' height='";
        a += to_string((float)1);
        a += "' x='";
        a += to_string(device->ruotasx.x - (device->ruotasx.r));
        a += "' y='";
        a += to_string(device->ruotasx.y + device->ruotasx.r + device->ruotasx.r/ 3);
        a += "' />\n";

        a += "<text xmlns='http://www.w3.org/2000/svg' x='";
        a += to_string(device->ruotasx.x - device->ruotasx.r / 2);
        a += "' y='";
        a += to_string(device->ruotasx.y + device->ruotasx.r + device->ruotasx.r/ 3 + 10);
        a += "' fill='black' dominant-baseline='middle' text-anchor='middle' font-size='8px' >";
        a += to_string(device->ruotasx.r);
        a += "</text>";

        //ruotasx
        a += "<rect style='fill:#000000;stroke-width:0.310366' id='rect26' width='";
        a += to_string((float)1);
        a += "' height='";
        a += to_string(device->ruotasx.r + device->ruotasx.r/ 3 + 20);
        a += "' x='";
        a += to_string(device->pianale.x);
        a += "' y='";
        a += to_string(device->ruotasx.y );
        a += "' />\n";

        a += "<rect style='fill:#000000;stroke-width:0.310366' id='rect27' width='";
        a += to_string((float)1);
        a += "' height='";
        a += to_string(device->ruotasx.r + device->ruotasx.r/ 3 + 20);
        a += "' x='";
        a += to_string(device->ruotasx.x);
        a += "' y='";
        a += to_string(device->ruotasx.y );
        a += "' />\n";

        a += "<rect style='fill:#000000;stroke-width:0.310366' id='rect28' width='";
        a += to_string(device->ruotasx.x - device->pianale.x);
        a += "' height='";
        a += to_string((float)1);
        a += "' x='";
        a += to_string(device->pianale.x);
        a += "' y='";
        a += to_string(device->ruotasx.y + device->ruotasx.r + device->ruotasx.r/ 3 + 17);
        a += "' />\n";

        a += "<text xmlns='http://www.w3.org/2000/svg' x='";
        a += to_string((device->ruotasx.x - device->pianale.x )/ 2 + device->pianale.x);
        a += "' y='";
        a += to_string(device->ruotasx.y + device->ruotasx.r + device->ruotasx.r/ 3 + 17 + 10);
        a += "' fill='black' dominant-baseline='middle' text-anchor='middle' font-size='8px' >";
        a += to_string(device->ruotasx.x - device->pianale.x);
        a += "</text>";

        //ruotadx
        a += "<rect style='fill:#000000;stroke-width:0.310366' id='rect29' width='";
        a += to_string((float)1);
        a += "' height='";
        a += to_string(device->ruotasx.r + device->ruotasx.r/ 3 + 17 + 20);
        a += "' x='";
        a += to_string(device->pianale.x);
        a += "' y='";
        a += to_string(device->ruotasx.y );
        a += "' />\n";

        a += "<rect style='fill:#000000;stroke-width:0.310366' id='rect30' width='";
        a += to_string((float)1);
        a += "' height='";
        a += to_string(device->ruotasx.r + device->ruotasx.r/ 3 + 17 + 20);
        a += "' x='";
        a += to_string(device->ruotadx.x);
        a += "' y='";
        a += to_string(device->ruotasx.y);
        a += "' />\n";

        a += "<rect style='fill:#000000;stroke-width:0.310366' id='rect31' width='";
        a += to_string(device->ruotadx.x - device->pianale.x);
        a += "' height='";
        a += to_string((float)1);
        a += "' x='";
        a += to_string(device->pianale.x);
        a += "' y='";
        a += to_string(device->ruotasx.y + device->ruotasx.r + device->ruotasx.r/ 3 + 17 + 17);
        a += "' />\n";

        a += "<text xmlns='http://www.w3.org/2000/svg' x='";
        a += to_string((device->ruotadx.x - device->pianale.x )/ 2 + device->pianale.x);
        a += "' y='";
        a += to_string(device->ruotasx.y + device->ruotasx.r + device->ruotasx.r/ 3 + 17 + 17 + 10);
        a += "' fill='black' dominant-baseline='middle' text-anchor='middle' font-size='8px' >";
        a += to_string(device->ruotadx.x - device->pianale.x);
        a += "</text>";   
    
        //pianale
        a += "<rect style='fill:#000000;stroke-width:0.310366' id='rect32' width='";
        a += to_string((float)1);
        a += "' height='";
        a += to_string(device->ruotasx.r + device->ruotasx.r/ 3 + 17 + 17 + 10 +10);
        a += "' x='";
        a += to_string(device->pianale.x);
        a += "' y='";
        a += to_string(device->ruotasx.y );
        a += "' />\n";

        a += "<rect style='fill:#000000;stroke-width:0.310366' id='rect33' width='";
        a += to_string((float)1);
        a += "' height='";
        a += to_string(device->ruotasx.r + device->ruotasx.r/ 3 + 17 + 17 + 10 + 10);
        a += "' x='";
        a += to_string(device->pianale.x + device->pianale.w - 1 );
        a += "' y='";
        a += to_string(device->ruotasx.y);
        a += "' />\n";

        a += "<rect style='fill:#000000;stroke-width:0.310366' id='rect34' width='";
        a += to_string(device->pianale.w);
        a += "' height='";
        a += to_string((float)1);
        a += "' x='";
        a += to_string(device->pianale.x);
        a += "' y='";
        a += to_string(device->ruotasx.y + device->ruotasx.r + device->ruotasx.r/ 3 + 17 + 17 + 10 + 7);
        a += "' />\n";

        a += "<text xmlns='http://www.w3.org/2000/svg' x='";
        a += to_string((device->pianale.w)/ 2 + device->pianale.x);
        a += "' y='";
        a += to_string(device->ruotasx.y + device->ruotasx.r + device->ruotasx.r/ 3 + 17 + 17 + 10 + 7 + 10);
        a += "' fill='black' dominant-baseline='middle' text-anchor='middle' font-size='8px' >";
        a += to_string(device->pianale.w);
        a += "</text>\n";   
    }
    return a;
}

/**
 * Scrive su file la stringa ricevuta in ingresso
 *
 * @param stringa contiene la tringa da scrivere
 */
void menini_write_file(string stringa, string nomefile){
    if(nomefile!=""){
        ofstream MyFile(nomefile);
        MyFile << stringa;
        MyFile.close();
    }
};

/**
  * Legge da file
  *
  * @param filename
  * @return stringa stringa letta
  */
 string menini_read_file(string filename){
     ifstream t(filename);
     stringstream buffer;
     buffer << t.rdbuf();
     string s = buffer.str();
     return s;
 };

/**
  * Cerca un parametro nell'svg
  *
  * @param stringa contiene la stringa in cui cercare
  * @param cercata contiene la stringa da cercare
  * @param partenza la posizione da cui partire nella ricerca
  * @param fine contiene la stringa che segna la fine del numero
  * @return il numero
  */
float menini_cerca(string stringa, string cercata, int & partenza, string fine){
    string numero;
    size_t found = stringa.find(cercata, partenza);
    if (found != string::npos)
        found += cercata.length();
        size_t found1 = stringa.find(fine, found+1);
        for (found; found < found1; found++){
            numero += stringa[found];
        }
    partenza = found;
    return stof(numero);
}

 /**
  * Crea un device da una stringa svg
  *
  * @param stringa contiene la stringa da scrivere
  * @return il device
  */
 MeniniDevice* menini_parse(string stringa){
    MeniniDevice *device = menini_init();

    int partenza = 0;

    if (stringa!=""){
        //width e height svg
        device->w = menini_cerca(stringa, "width='", partenza, "'");
        device->h = menini_cerca(stringa, "height='", partenza, "'");

        //cabina
        device->cabina.w = menini_cerca(stringa, "width='", partenza, "'");
        device->cabina.h = menini_cerca(stringa, "height='", partenza, "'");
        device->cabina.x = menini_cerca(stringa, "x='", partenza, "'");
        device->cabina.y = menini_cerca(stringa, "y='", partenza, "'");
        
        //vetro
        device->vetro.w = menini_cerca(stringa, "width='", partenza, "'");
        device->vetro.h = menini_cerca(stringa, "height='", partenza, "'");
        device->vetro.x = menini_cerca(stringa, "x='", partenza, "'");
        device->vetro.y = menini_cerca(stringa, "y='", partenza, "'");
        
        //pianale
        device->pianale.w = menini_cerca(stringa, "width='", partenza, "'");
        device->pianale.h = menini_cerca(stringa, "height='", partenza, "'");
        device->pianale.x = menini_cerca(stringa, "x='", partenza, "'");
        device->pianale.y = menini_cerca(stringa, "y='", partenza, "'");
        
        //ruotasx
        device->ruotasx.x = menini_cerca(stringa, "cx='", partenza, "'");
        device->ruotasx.y = menini_cerca(stringa, "cy='", partenza, "'");
        device->ruotasx.r = menini_cerca(stringa, "rx='", partenza, "'");
        
        //ruotadx

        device->ruotadx.x = menini_cerca(stringa, "cx='", partenza, "'");
        device->ruotadx.y = menini_cerca(stringa, "cy='", partenza, "'");
        device->ruotadx.r = menini_cerca(stringa, "rx='", partenza, "'");
    }else{
        return NULL;
    }
    return device;
 }
