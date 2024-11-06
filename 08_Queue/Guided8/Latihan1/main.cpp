#include <iostream>

using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0;               // Penanda antrian
int back = 0;                // Penanda
string queueTeller[5];       // Fungsi pengecekan

bool isFull()
{ //pengecekan antrian penuh atau tidak
    if(back == maksimalQueue){
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty(){ // Antriannya kosong atau tidak
    if( back==0 ){
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Fungsi menambahkan antrian
    if (isFull()){
      cout << "Antrian penuh" << endl;
    } else { // Antrianya ada isi
        if(isEmpty()){ // kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() {
    if (isEmpty()){
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back - 1; i++){
            queueTeller[i] = queueTeller [i +1];
        }
        queueTeller[back -1] = "";
        back--;
    }
}

int countQueue(){ //Fungsi menghitung banyak antrian
    return back;
}

void clearQueue() { //Fungsi menghapus semua antrian
    if (isEmpty()){
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
           queueTeller[i] = "";
        }
        back =0;
        front= 0;
    }
}

void viewQueue(){ // Fungsi melihat antria
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if(queueTeller[i] != "") {
               cout << i + 1<< ". " <<queueTeller[i] <<endl;
           }else{
           cout<<i + 1 << ". (kosong)"<< endl;
           }
    }
}
int main()
{
    enqueueAntrian("Shilfi");
    enqueueAntrian("Kelvin");
    viewQueue();
    cout<<"Jumlah antrian = "<<countQueue << endl;
    dequeueAntrian();
    viewQueue();
    cout<< "Jumlah antrian = " <<countQueue()<<endl;
    clearQueue();
    viewQueue();
    cout<< "jumlah antrian = "<<countQueue()<<endl;
    return 0;
}

