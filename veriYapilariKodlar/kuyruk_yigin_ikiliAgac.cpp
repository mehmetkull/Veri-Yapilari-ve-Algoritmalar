/*
Soru 4:  Üç tane sınıf listesi vardır. Farzedin ki bir kuyruk veri yapısında Kimya dersini alan öğrencilerin 
listesi tutulmaktadır. Bir yığın veri yapısında ise Fizik dersini alan öğrencilerin listesi tutulmaktadır. Bir 
ikili arama ağacı veri yapısında ise Biyoloji dersini alan öğrencilerin listesi tutulmaktadır. Her derste de 
öğrencilerin numaraları, adları ve soyadları tutulmaktadır. İkili arama ağacında indeksleme öğrenci adına 
göre yapılmaktadır. 

a) Hem Biyoloji hem de Fizik dersini alan öğrencilerin bilgilerini listeleyen fonksiyonun kaba kodunu 
yazınız? Fonksiyonu yazarken temel kuyruk, yığın ve ağaç işlemlerini kullanınız. 
*/

// temel işlemler
// kuyruk = enqueue, dequeue, IsEmpty, Display
// yığın = push, pop, IsEmpty, top, Display
// ikili arama ağacı = insertNode, deleteNode, findNode, inOrderDisplay


///*** SORUYA BAŞLAMADAN LÜTFEN İLGİLİ SATIRI OKUYUNUZ ***/// // SATIR 82 //


// öğrenci yapısının tanımı
struct Ogrenci { 
    int no ;
    std::string ad ;
    std::string soyad ;
};

// yığın sınıfının tanımı
class Stack {
public:
    Stack(int size);
    ~Stack(void);
    bool isEmpty(void);
    void push(Ogrenci data);
    double pop(void);
    double top(void);
    void displayStack(void);
private:
    };

// ikili arama ağacı düğüm sınıfının tanımı
    class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int item) {
        data = item;
        left = right = nullptr;
    }
};
// ikili arama ağacı sınıfının tanımı
class BST {
public:  
    BST(void) : root(nullptr) {}
    ~BST(void);
    void insertNode(Ogrenci data);
    void deleteNode(std::string ad);
    Node* findNode(std::string ad);
    void inOrderDisplay(void);
private:
    Node* root;
};

// kuyruk sınıfının tanımı
class Queue {
public:
    Queue(int size);
    ~Queue(void);
    bool isEmpty(void);
    void enqueue(Ogrenci data);
    double dequeue(void);
    void displayQueue(void);
private:
    Node* front;
    Node* rear;
    int counter;
};


// *** DİKKAT *** ///
/// SORUNUN ÇÖZÜMÜ BURADAN BAŞLIYOR (SINAVDA İSTENEN KISIM) ///
/// YUKARIDAKİ KODLAR SADECE İLGİLİ VERİ YAPILARININ TANIMI İÇİNDİR ///
/// BU BİR KABA KODDUR DOLAYISIYLA SYNTAX VE YAZIM HATALARINA DİKKAT EDİLMEMİŞTİR KODU DERLEMEYE ÇALIŞMAYIN. ///


void ortakOgrenciler(Queue& kuyruk, Stack& yigin, BST& agac) {

geciciYigin = new Stack(); // fizik öğrencilerini geçici tutmak için yeni bir yığın oluştur

while(IsEmpty(yigin) == false){   // yığın boşalana kadar dön
    fizikOgrenci = yigin.pop();   // yığından bir fizik öğrencisi çıkar
    geciciYigin.push(fizikOgrenci); // geçici yığına ekle, çünkü yığın yapısı bozulmamalı

 // ikili arama ağacında fizik öğrencisinin adıyla arama yap, çünkü ağaçta indeksleme öğrenci adına göre yapılmış
    Node* bulunanDugum = agac.findNode(fizikOgrenci.ad);

    if(bulunanDugum != nullptr){                              // öğrenci adı bulunduysa devam et
        if(bulunanDugum -> data.no == fizikOgrenci.no){       // numaraları kontrol et çünkü adlar aynı olabilir
        print("Ogrenci Bulundu: " + fizikOgrenci.no + " " + fizikOgrenci.ad + " " + fizikOgrenci.soyad);
    }
    else{
        print("Ogrenci Bulunamadi: ");
    }
}
while(IsEmpty(geciciYigin) == false){  // geçici yığın boşalana kadar dön
    yigin.push(geciciYigin.pop());     // fizik öğrencilerini tekrar orijinal yığına geri ekle
}
delete geciciYigin;    // geçici yığını sil
};