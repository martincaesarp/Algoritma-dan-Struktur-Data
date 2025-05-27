#include <iostream>
using namespace std;

class contoh{
	private:
		int nilai; //Variabel yang menyimpan nilai
	public:
		//Constructor: dipanggil saat objek dibuat
		contoh (int n){
			nilai = n;
		}
		//Fungsi anggota untuk mendapatkan nilai
		int getNum(){
			return nilai;
		}
};

int main(){
	contoh obj (10); //Membuat objek 'obj' dengan nilai 10
	cout <<"nilai yang diinput: "<< obj.getNum() <<endl;
	return 0;		
}






//Program menerapkan constructor, karena ada fungsi contoh (int n) yang langsung dijalankan saat objek dibuat. Constructor ini bertugas untuk menginisialisasi nilai awal dari atribut nilai. 
