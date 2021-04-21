#include <iostream>
#include <fstream>
#include<string>
#include <cmath>
using namespace std;

public class ulamki {
	public:
		ifstream wejscie;
		const int SIZE = 1000;
		float tab[1000][2];
		int sum = 0;
		ulamki(string path) {
			wejscie.open(path);
		}
		~ulamki() {
			wejscie.close();
		}
		void wczytaj() {
			for (int i = 0; i < SIZE; i++) {
				wejscie >> tab[i][0] >> tab[i][1];
			}
			this->licz();
		}
		void licz() {
			int currentNwd;
			for (int i = 0; i < SIZE; i++) {
				float licznik = tab[i][0];
				float mianownik = tab[i][1];
				while (NWD(licznik, mianownik) > 1) {
					currentNwd = NWD(licznik, mianownik);
					licznik = licznik / currentNwd;
					mianownik = mianownik / currentNwd;
				}
				sum += licznik;
			}
		}
		int NWD(int x, int y) {
			if (x < y) return NWD(y, x);
			if (y == 0) return x;
			return NWD(y, x % y);
		}
		string wypisz() {
			string wynik;
			wynik = to_string(sum);
			return wynik;
		}
};