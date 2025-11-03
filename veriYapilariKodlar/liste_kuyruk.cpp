//Farzedin ki bir bağlantılı listede veri yapıları dersini alan ve bir kuyruk veri yapısında ise 
//programlama dersini alan öğrenciler tutulmaktadır. Her iki derste de öğrencilerin numaraları, adı ve 
//soyadı tutulmaktadır. 

//a. Her iki dersi de alan öğrencileri bulmak için gereken fonksiyonun kaba kodunu yazınız? Fonksiyonu 
//yazarken temel bağlantılı ve kuyruk işlemlerini kullanınız?



// temel işlemler
// bağlantılı liste =  ısempty, insertnode, deletenode, findNode, displayList
// kuyruk = enqueue, dequeue, isEmpty, isFull, Display

struct Ogrenci {
	int no;
	std::string ad;
	std::string soyad;
};


class List{
public: 	
		List(void){ head = nullptr; }
		~List(void);
		bool isEmpty(void);
		Node* insertNode(int index, double id);
		void deleteNode(int id);
		Node* findNode(int id);
		void displayList(void);
private:
		Node* head;
		friend class Queue;
};

class Queue: public List{
public:
		Queue(int size);
		~Queue(void);
		bool isEmpty(void);
		void enqueue(double id);
		double dequeue(void);
		void displayQueue(void);
private:
		Node* front;
		Node* rear;
		int counter;
};

void ortakOgrenciler(List& liste, Queue& kuyruk) {

	geciciKuyruk = new Queue();

	while(IsEmpty(kuyruk) == false){
		currOgrenci = kuyruk.dequeue();
		geciciKuyruk.enqueue(currOgrenci);

		if(liste.findNode(currOgrenci.no) != nullptr){
			print("Ogrenci Bulundu: " + currOgrenci.no + " " + currOgrenci.ad + " " + currOgrenci.soyad);
		}
	}

	while(IsEmpty(geciciKuyruk) == false){
		kuyruk.enqueue(geciciKuyruk.dequeue());
	}

	delete geciciKuyruk;
}