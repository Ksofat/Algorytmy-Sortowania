#include <bits/stdc++.h>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;

const int ilosc_probki = 100000;
ofstream plik("wyniki.txt", ios::app);
long long czas2=0, czas1=0, czas3=0, czas4=0, czas5=0, prz1=0, prz2=0, prz3=0, prz4=0, prz5=0, spr1=0, spr2=0, spr3=0, spr4=0, spr5=0;


void doprzodu_standard(int przepis[], int ilosc) {

    int liczby[ilosc_probki]/*={2,6,10,5,9,8,7,3,1,4}*/;
    prz1=0; spr1=0;

    for (int i = 0; i < ilosc; i++) { //ten for przepisuje liczby z nieposortowanej tablicy, by potem nie sortować sortowanych
        liczby[i] = przepis[i];
    }

    auto start = high_resolution_clock::now(); //zaczyna liczenie czasu

    for (int i = 1; i < ilosc; i++) {

        int mniejsza = i - 1;//tworzymy zmienną o wartości mniejszej
        int przejscie = liczby[i];//tymczasowa zmienna, która przyjmuje wartość danego elementu tablicy

        while (mniejsza >= 0 && przejscie < liczby[mniejsza]) {//pętla która działa dopóki mniejsza jest większa od zera i przejscie jest mniejsze od wartosci z tablicy która ma inteks mniejszej
            liczby[mniejsza + 1] = liczby[mniejsza];//W pętli while zamieniamy miejscami wartości z tablicy, zaczynając od elementu o indeksie mniejsza
            mniejsza--;//zmniejszamy mniejszą o 1
            spr1++;//dodajemy 1 do sprawdzan
            prz1++;//dodajemy 1 do przesuniec
        }
        liczby[mniejsza + 1] = przejscie;//wiekszej przypisujemy przejscie
        spr1++;//dodajemy 1 do przesuniec
    }

    auto koniec = high_resolution_clock::now(); //konczy liczenie czaasu
    auto czas_trwania = duration_cast<microseconds>(koniec - start); //zlicza czas
    czas1 = czas_trwania.count();//zmiena czas na wartosc liczbowa

    plik<<"sortowanie_przód_zwykłe;" << prz1 << ";" << spr1 << ";" << czas1 << ";" << endl;
}


void dotylu_standard(int przepis[], int ilosc) {

    int liczby[ilosc_probki];
    prz2=0; spr2=0;

    for (int i = 0; i < ilosc; i++) {//for do kopiowania
        liczby[i] = przepis[i];
    }

    auto start = high_resolution_clock::now();//zaczyna liczenie czasu

    for (int i = ilosc - 1; i >= 0; i--) {

        int przejscie = liczby[i];//tymczasowa zmienna, która przyjmuje wartość danego elementu tablicy
        int wieksza = i + 1;//tworzymy zmienną o wartości większej

        while (wieksza < ilosc && przejscie > liczby[wieksza]) {//pętla która działa dopóki wieksza jest mniejsza od ilosci, oraz przejscie jest mniejsze od wartosci tablicy o indeksie wieksza
            liczby[wieksza - 1] = liczby[wieksza];//W pętli while zamieniamy miejscami wartości z tablicy, zaczynając od elementu o indeksie większa
            wieksza++;//zwiekszamy indeks
            prz2++;//dodajemy 1 do przesuniec
            spr2++;//dodajemy 1 do sprawdzan
        }
        liczby[wieksza - 1] = przejscie;
        spr2++;//dodajemy 1 do przesuniec
    }

    auto koniec = high_resolution_clock::now();//konczy liczenie czaasu
    auto czas_trwania = duration_cast<microseconds>(koniec - start);//zlicza czas
    czas2 = czas_trwania.count();//zmiena czas na wartosc liczbowa

    plik<<"sortowanie_tył_zwykłe;"  << prz2 << ";" << spr2 << ";" << czas2 << ";" << endl;
}


void doprzodu_alt(int przepis[], int ilosc) {

    int liczby[ilosc_probki];
    prz3=0; spr3=0;

   for (int i = 0; i < ilosc; i++) { //ten for przepisuje liczby z nieposortowanej tablicy, by potem nie sortować sortowanych
        liczby[i] = przepis[i];
    }

    auto start = high_resolution_clock::now(); //zaczyna liczenie czasu

    for(int i=1;i<ilosc;i++){

        int przejscie = liczby[i];//tymczasowa zmienna, która przyjmuje wartość danego elementu tablicy
        int wstawiana=0;//tworzymy wartosc która będzie wstawiana

        while(wstawiana<=i){//pętla działą do momentu w którym wstawiana jest mniejsza bądź równa i
            if(przejscie<liczby[wstawiana]){//petla działa jeżeli liczba przejscowa jest mniejsza od wartosci tablicy o indeksie wstawianej
                for(int j=i; j>wstawiana; j--){//pętla która chodzi po elementach tablicy aż do wstawiana+1
                    liczby[j]=liczby[j-1];//przypisujemy wartosc elementu tablicy o indeksie j-1 dla elementu o indeksie j
                    prz3++;//dodajemy 1 do przesuniec
                    spr3++;//dodajemy 1 do sprawdzan
                }
                liczby[wstawiana] =przejscie;//dajemy wartosc przejsciowej dla liczby o indeksie wstawianej
                wstawiana=i+1;//wstawiana zyskuje wartosc i+1

            }
            else{
               wstawiana++;//jeżeli przejscie jest większe od elementu tablicy o indeksie wstawianej, wstawiana rosnie o 1
                spr3++;
            }
        }
    }

    auto koniec = high_resolution_clock::now();//konczy liczenie czaasu
    auto czas_trwania = duration_cast<microseconds>(koniec - start);//zlicza czas
    czas3 = czas_trwania.count();//zmiena czas na wartosc liczbowa

    plik<<"sortowanie_przód_odwrocone;" << prz3 << ";" << spr3 << ";" << czas3 << ";" << endl;

}
void dotylu_alt(int przepis[], int ilosc){

    int liczby[ilosc_probki];
    prz4=0; spr4=0;

    for (int i = 0; i < ilosc; i++) { //ten for przepisuje liczby z nieposortowanej tablicy, by potem nie sortować sortowanych
        liczby[i] = przepis[i];
    }

    auto start = high_resolution_clock::now(); //zaczyna liczenie czasu

    for(int i=ilosc-1; i>=0; i--){

        int przejscie = liczby[i];//tymczasowa zmienna, która przyjmuje wartość danego elementu tablicy
        int wstawiana=ilosc;//tworzymy wartosc która będzie wstawiana

        while(wstawiana>i){//pętla działą do momentu w którym wstawiana jest mniejsza i
            if(przejscie>liczby[wstawiana-1]){//petla działa jeżeli liczba przejscowa jest mniejsza od wartosci tablicy o indeksie o jeden mniejszy od wstawianej
                for(int j=i; j<wstawiana-1; j++){//pętla która chodzi po elementach tablicy aż do wstawiana-1
                    liczby[j]=liczby[j+1];//przypisujemy wartosc elementu tablicy o indeksie j dla elementu o indeksie j+1
                    prz4++;//dodajemy 1 do przesuniec
                    spr4++;//dodajemy 1 do sprawdzan
                }
                liczby[wstawiana-1] =przejscie;//dajemy wartosc przejsciowej dla liczby o indeksie wstawianej-1
                wstawiana=i;//wstawiana zyskuje wartosc i
            }
            else{
                wstawiana--;//jeżeli przejscie jest większe od elementu tablicy o indeksie wstawianej, wstawiana rosnie o 1
                spr4++;
            }
        }
    }

    auto koniec = high_resolution_clock::now();//konczy liczenie czaasu
    auto czas_trwania = duration_cast<microseconds>(koniec - start);//zlicza czas
    czas5 = czas_trwania.count();//zmiena czas na wartosc liczbowa

    plik<<"sortowanie_tył_odwrocone;" << prz4 << ";" << spr4 << ";" << czas5 << ";" << endl;
}


void binarne(int przepis[], int ilosc) {

    int liczby[ilosc_probki];
    prz5=0; spr5=0;

    for (int i = 0; i < ilosc; i++) {//for do kopiowania
        liczby[i] = przepis[i];
    }

    auto start = high_resolution_clock::now();//zaczyna liczenie czasu

    for (int i = 1; i < ilosc; i++) {

        int przejscie = liczby[i];//tymczasowa zmienna, która przyjmuje wartość danego elementu tablicy
        int lewo = 0, prawo = i - 1, srodek; //Tworzymy trzy zmienne: lewo, prawo i srodek, które używamy do tworzenia algorytmu wyszukiwania binarnego

        while (lewo <= prawo) {//pętla dziala dopóki lewa jest mniejsze bądź równe prawej
            srodek = (lewo + prawo) >> 1;//obliczamy srodek, poprzez srednią arytmetyczną prawa i lewa. Wyczytałem, że użycie ">> 1" usprawni działanie kodu, dlatego zmieniłem z "  srodek = (lewo + prawo) / 2;"
            if (przejscie < liczby[srodek]) {//petla dziala jeżeli wartosc przejsciowa jest mniejsza od elementu tablicy o indeksie srodek
                prawo = srodek - 1;//prawa zmienna staje się o 1 mniejsza od srodkowej
            } else {
                lewo = srodek + 1;//w przeciwnym razie lewa zmienna staje sie o 1 wieksza od srodkowej
            }
            spr5++;//dodajemy 1 do sprawdzan
        }
        for (int j = i - 1; j >= lewo; j--) {
            liczby[j+1] = liczby[j];
            prz5++;//dodajemy 1 do przesuniec
        }
        liczby[lewo] = przejscie;//zmieniamy wartosc tablicy o indeksie lewo na wartosc przejscia
    }

    auto koniec = high_resolution_clock::now();//konczy liczenie czaasu
    auto czas_trwania = duration_cast<microseconds>(koniec - start);//zlicza czas
    czas4 = czas_trwania.count();//zmiena czas na wartosc liczbowa
    plik<<"sortowanie_binarne;" << prz5 << ";" << spr5 << ";" << czas4 << ";" << endl;
}


int main(){

    //int probka[ilosc_probki];
   int probka[ilosc_probki];
    long long cz_sr_przstd = 0, cz_sr_tylstd = 0, cz_sr_przalt = 0, cz_sr_tylalt = 0, cz_sr_bin = 0, spr_sr_przstd =0, spr_sr_tylstd =0, spr_sr_przalt =0, spr_sr_tylalt =0, spr_sr_bin =0,
     prz_sr_przstd =0, prz_sr_tylstd =0, prz_sr_przalt =0, prz_sr_tylalt =0, prz_sr_bin =0; //te wartosci będą używane do obliczania średnich

    if (plik.is_open()) {

        for (int sto = 0; sto < 100; sto++) {
            random_device los; //tworzymy obiekt który będzie służył do generowania liczb pseudlosowych
            mt19937 tworz(los()); //tworzymy generator liczb pseudlosowych oparty o obiekt los
            uniform_int_distribution<> rozstrzal(1, ilosc_probki);//pokazujemy między jakimi liczbami ma losowac

            for (int i = 0; i < ilosc_probki; i++) {
                int a = rozstrzal(los);	//przypisujemy wylosowaną liczbę zmiennej a, pomaga to potem niwelować powtórzenia
                for (int j = 0; j < i; j++) {//tutaj odbywa się proces usuwania powtórzeń
                    if (probka[j] == a) {
                        a = rozstrzal(los);
                        j = -1;
                    }
                }
                probka[i] = a;
            }

            //tablice losowe
            plik<<"dla tablic losowych :"<<endl;
            doprzodu_standard(probka, ilosc_probki);//wywolanie funcji
            cz_sr_przstd += czas1; prz_sr_przstd+=prz1; spr_sr_przstd+=spr1;                 //sumowanie czasu, powtorzen i sprawdzen dla x prob
            dotylu_standard(probka, ilosc_probki);
            cz_sr_tylstd += czas2; prz_sr_tylstd+=prz2; spr_sr_tylstd+=spr2;
            doprzodu_alt(probka, ilosc_probki);
            cz_sr_przalt += czas3; prz_sr_przalt+=prz3; spr_sr_przalt+=spr3;
            dotylu_alt(probka,ilosc_probki);
            cz_sr_tylalt += czas5; prz_sr_tylalt+=prz4; spr_sr_tylalt+=spr4;
            binarne(probka,ilosc_probki);
            cz_sr_bin += czas4;prz_sr_bin+=prz5; spr_sr_bin+=spr5;
            plik << endl;
            
        }
        plik<<"srednie wyniki dla losowych :"<<endl;
        plik << "1sze srednio zajelo : " << cz_sr_przstd / 100 << " microsekund" <<prz_sr_przstd/100 <<"przesunieć" <<spr_sr_przstd/100 <<"porownan"<< endl;//wpisywanie srednich czasów na koniec pliku
        plik << "2gie srednio zajelo : " << cz_sr_tylstd / 100<< " microsekund" <<prz_sr_tylstd/100 <<"przesunieć" <<spr_sr_tylstd/100 <<"porownan" << endl;
        plik << "3cie srednio zajelo : " << cz_sr_przalt / 100<< " microsekund" <<prz_sr_przalt/100 <<"przesunieć" <<spr_sr_przalt/100 <<"porownan" << endl;
        plik << "4te srednio zajelo : " << cz_sr_tylalt / 100<< " microsekund" <<prz_sr_tylalt/100 <<"przesunieć" <<spr_sr_tylalt/100 <<"porownan" << endl;
        plik << "5te srednio zajelo : " << cz_sr_bin / 100<< " microsekund" <<prz_sr_bin/100 <<"przesunieć" <<spr_sr_bin/100 <<"porownan" << endl;

        //tablica posortowana min max;
        for (int i = ilosc_probki; i >= 1; i--) {
            probka[ilosc_probki - i + 1] = i;
        }
        plik<<"dla tablicy posortowanej max-min :"<<endl;
        doprzodu_standard(probka, ilosc_probki);//wywolanie funcji
        cz_sr_przstd += czas1; prz_sr_przstd+=prz1; spr_sr_przstd+=spr1;                 //sumowanie czasu, powtorzen i sprawdzen dla x prob
        dotylu_standard(probka, ilosc_probki);
        cz_sr_tylstd += czas2; prz_sr_tylstd+=prz2; spr_sr_tylstd+=spr2;
        doprzodu_alt(probka, ilosc_probki);
        cz_sr_przalt += czas3; prz_sr_przalt+=prz3; spr_sr_przalt+=spr3;
        dotylu_alt(probka,ilosc_probki);
        cz_sr_tylalt += czas5; prz_sr_tylalt+=prz4; spr_sr_tylalt+=spr4;
        binarne(probka,ilosc_probki);
        cz_sr_bin += czas4;prz_sr_bin+=prz5; spr_sr_bin+=spr5;

        //tablica posortowana min max;
        for (int i = 1; i <= ilosc_probki; i++) {
            probka[i] = i;
        }
        plik<<"dla tablicy posortowanej min-max :"<<endl;
        doprzodu_standard(probka, ilosc_probki);//wywolanie funcji
        cz_sr_przstd += czas1; prz_sr_przstd+=prz1; spr_sr_przstd+=spr1;                 //sumowanie czasu, powtorzen i sprawdzen dla x prob
        dotylu_standard(probka, ilosc_probki);
        cz_sr_tylstd += czas2; prz_sr_tylstd+=prz2; spr_sr_tylstd+=spr2;
        doprzodu_alt(probka, ilosc_probki);
        cz_sr_przalt += czas3; prz_sr_przalt+=prz3; spr_sr_przalt+=spr3;
        dotylu_alt(probka,ilosc_probki);
        cz_sr_tylalt += czas5; prz_sr_tylalt+=prz4; spr_sr_tylalt+=spr4;
        binarne(probka,ilosc_probki);
        cz_sr_bin += czas4;prz_sr_bin+=prz5; spr_sr_bin+=spr5;
        plik << endl;
        plik<<"srednie wyniki dla losowych i posortowanych :"<<endl;
        plik << "1sze srednio zajelo : " << cz_sr_przstd / 102 << " microsekund" <<prz_sr_przstd/102 <<"przesunieć" <<spr_sr_przstd/102 <<"porownan"<< endl;//wpisywanie srednich czasów na koniec pliku
        plik << "2gie srednio zajelo : " << cz_sr_tylstd / 102<< " microsekund" <<prz_sr_tylstd/102 <<"przesunieć" <<spr_sr_tylstd/102 <<"porownan" << endl;
        plik << "3cie srednio zajelo : " << cz_sr_przalt / 102<< " microsekund" <<prz_sr_przalt/102 <<"przesunieć" <<spr_sr_przalt/102 <<"porownan" << endl;
        plik << "4te srednio zajelo : " << cz_sr_tylalt / 102<< " microsekund" <<prz_sr_tylalt/102 <<"przesunieć" <<spr_sr_tylalt/102 <<"porownan" << endl;
        plik << "5te srednio zajelo : " << cz_sr_bin / 102<< " microsekund" <<prz_sr_bin/102 <<"przesunieć" <<spr_sr_bin/102 <<"porownan" << endl;

        plik.close();
    }
    return 0;
}
