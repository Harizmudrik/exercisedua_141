#include <iostream>
#include <vector>
using namespace std;

class pengarang;
class penerbit {
public:
    string nama;
    vector<pengarang*> daftar_pengarang;
    penerbit(string pNama) :nama(pNama) {
        cout << "penerbit \"" << nama << "\" ada\n";
    }
    ~penerbit() {
        cout << "penerbit \"" << nama << "\" tidak ada\n";
    }
    void tambahPengarang(pengarang*);
    void cetakPengarang();


};

class pengarang {
public:
    string nama;
    vector<penerbit*> daftar_penerbit;

    pengarang(string pNama) :nama(pNama) {
        cout << "Pengarang \"" << nama << "\" ada\n";

    }
    ~pengarang() {
        cout << "Pengarang \"" << nama << "\" tidak ada\n";

    }
    void tambahPenerbit(penerbit*);
    void cetakPenerbit();
};

void penerbit::tambahPengarang(pengarang* pPengarang) {
    daftar_pengarang.push_back(pPengarang);
}
void penerbit::cetakPengarang() {
    cout << "Daftar Pengarang yang menerbitkan \"" << this->nama << "\":\n";
    for (auto& a : daftar_pengarang) {
        cout << a->nama << "\n";
    }
    cout << endl;
}
void pengarang::tambahPenerbit(penerbit* pPenerbit) {
    daftar_penerbit.push_back(pPenerbit);
    pPenerbit->tambahPengarang(this);

}
void pengarang::cetakPenerbit() {
    cout << "Daftar Penerbit dari pengarang \"" << this->nama << "\":\n";
    for (auto& a : daftar_penerbit) {
        cout << a->nama << "\n";

    }
    cout << endl;
}

int main() {
    pengarang* varPengarang1 = new pengarang("Joko");
    pengarang* varPengarang2 = new pengarang("Lia");
    pengarang* varPengarang3 = new pengarang("Giga");
    pengarang* varPengarang4 = new pengarang("Asroni");
    penerbit* varPenerbit1 = new penerbit("Gama Press");
    penerbit* varPenerbit2 = new penerbit("Intan Pariwara");


    varPengarang1->tambahPenerbit(varPenerbit1);
    varPengarang2->tambahPenerbit(varPenerbit1);
    varPengarang3->tambahPenerbit(varPenerbit1);
    varPengarang3->tambahPenerbit(varPenerbit2);
    varPengarang4->tambahPenerbit(varPenerbit2);


    varPengarang1->cetakPenerbit();
    varPengarang2->cetakPenerbit();
    varPengarang3->cetakPenerbit();
    varPengarang4->cetakPenerbit();
    varPenerbit1->cetakPengarang();
    varPenerbit2->cetakPengarang();

    delete varPenerbit1;
    delete varPenerbit2;
    delete varPengarang1;
    delete varPengarang2;
    delete varPengarang3;
    delete varPengarang4;

    return 0;
}