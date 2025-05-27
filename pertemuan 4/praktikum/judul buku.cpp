#include <iostream>
#include <string>
using namespace std;

class infobuku {
	private:
		string judul;
		string penulis;
		int tahun;
	
	public:
		infobuku () {
			judul = " ";
			penulis = " ";
			tahun = 0;
		}
		
		void setjudul(string title) {
			judul = title;
			
		}

		void setpenulis (string author) {
			penulis = author;
			
		}

		void settahun(int year) {
			tahun = year;
			
		}
	
	void displayinfobuku() {
		cout << "Judul : " << judul << endl;
		cout << "Penulis : " << penulis << endl;
		cout << "Tahun terbit : " << tahun << endl;
	}
};

int main () 
{
	infobuku buku1;
	infobuku buku2;
	
	buku1.setjudul ("Harry potter");
	buku1.setpenulis ("Agus");
	buku1.settahun(1990);
	
	buku2.setjudul("Petualangan si Agus");
	buku2.setpenulis ("Wildan");
	buku2.settahun (2045);
	
	buku1.displayinfobuku();
	buku2.displayinfobuku();
		
	return 0;
}

//#include <iostream>
//#include <string>
//using namespace std;
//
//class info buku {
//	private:
//		string judul;
//		string penulis;
//		int tahun;
//	
//	public:
//		
//		infobuku (string title, string author, int year)
//		: judul(title), penulis(author), tahun(year){
//			cout << endl;
//		}
//
//		
//		void setjudul(string title) {
//			judul = title;
//	
//		}
//
//		void setpenulis (string author) {
//			penulis = author;
//			
//		}
//
//		void settahun(int year) {
//			tahun = year;
//			
//		}
//	
//	void displayinfobuku() {
//		cout << "Judul : " << judul << endl;
//		cout << "Penulis : " << penulis << endl;
//		cout << "Tahun terbit : " << tahun << endl;
//	}
//};
//
//int main () 
//{
//	infobuku pertama("Harry Potter", "JK Rowling", 1998);
//	pertama.displayinfobuku();
//	
//	infobuku kedua("Mariposa", "Lupa", 2018);
//	kedua.displayinfobuku();
//		
//	return 0;
//}
