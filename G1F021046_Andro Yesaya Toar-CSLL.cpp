#include <iostream>
using namespace std;

// Deklarasi struktur untuk Circular Single Linked List
struct HP{
  string merek, tipe, harga;

  HP *next;
};

HP *head, *tail, *newNode, *cur, *del;

// create Circular Single Linked List
void createCircularSingleLinkedList(string newData[3]){

  head = new HP();
  head->merek = newData[0];
  head->tipe = newData[1];
  head->harga = newData[2];
  tail = head;
  tail->next = head;

}

// add first
void addFirst( string data[3] ){
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    newNode = new HP();
    newNode->merek = data[0];
    newNode->tipe = data[1];
    newNode->harga = data[2];
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
  }
}

// add Last
void addLast( string data[3] ){
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    newNode = new HP();
    newNode->merek = data[0];
    newNode->tipe = data[1];
    newNode->harga = data[2];
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
  }
}

// add Middle
void addMiddle(string data[3], int posisi)
{
  if( head == NULL ){
    cout << "Buat Linked List terlebih dahulu!!" << endl;
  }else{
    if( posisi == 1 ){
      cout << "Posisi pertama bukan posisi tengah!!!" << endl;
    }else{
      newNode = new HP();
      newNode->merek = data[0];
      newNode->tipe = data[1];
      newNode->harga = data[2];

      // tranversing
      int nomor = 1;
      cur = head;
      while (nomor < posisi - 1)
      {
        cur = cur->next;
        nomor++;
      }
      newNode->next = cur->next;
      cur->next = newNode;
    }
  }
}

// remove First
void removeFirst(){
  if( head == NULL ){
    cout << "Buat Linked List terlebih dahulu!!" << endl;
  }else{
    del = head;
    head = head->next;
    tail->next = head;
    delete del;
  }
}

// remove last
void removeLast()
{
  if( head == NULL ){
    cout << "Buat Linked List terlebih dahulu!!" << endl;
  }else{
    del = tail;
    cur = head;
    while( cur->next != tail ){
      cur = cur->next;
    }
    tail = cur;
    tail->next = head;
    delete del;
  }
}

// remove middle
void removeMiddle(int posisi)
{
  if( head == NULL ){
    cout << "Buat Linked List terlebih dahulu!!" << endl;
  }else{
    // tranversing
    int nomor = 1;
    cur = head;
    while( nomor < posisi - 1 ){
      cur = cur->next;
      nomor++;
    }
    del = cur->next;
    cur->next = del->next;
    delete del;
  }
}


void printCircular()
{
  if( head == NULL ){
    cout << "Buat Linked List terlebih dahulu!!" << endl;
  }else{
    cout << " Data Smartphone " << endl;
    cout << "________________________________________________________________" << endl; 
    cout << "| MEREK\t\t| TIPE\t\t| HARGA\t\t|" << endl;
    cout << "________________________________________________________________" << endl; 
    cur = head;
    while (cur->next != head)
    {
      // print
      cout << "| " << cur->merek << "\t| " << cur->tipe << "\t| " << cur->harga << "\t\t|" << endl;
      cur = cur->next;
    }
    cout << "| " << cur->merek << "\t| " << cur->tipe << "\t| " << cur->harga << "\t\t|" << endl;
    cout << "_________________________________________________________________" << endl;
  }
}


int main(){
  string dataBaru[3] = {"XIAOMI", "NOTE 9", "2.499.000"};
  createCircularSingleLinkedList(dataBaru);

  printCircular();

  string data[3] = {"REALME", "Realme Narzo 50A", "2.299.000"};
  addFirst(data);

  printCircular();

  string data2[3] = {"SAMSUNG", "SAMSUNG A12", "2.199.000"};
  addLast(data2);

  printCircular();

  string data3[3] = {"OPPO", "OPPO A5", "2.300.000"};
  addMiddle(data3, 5);

  printCircular();

  removeMiddle(6);

  printCircular();

  removeFirst();

  printCircular();

  removeLast();

  printCircular();
}
