#include <iostream>
using namespace std ;

string username, password,update ;
int pilih, makanan, totalmakanan ;
string carinama;
void menu() ;
void tambahmakanan() ;
void lihatmakanan() ;
void carimakanan() ;
void bonus();
string namamakanan['x'] ;
int banyakbahan['x'] ;
string namabahan['x']['y'] ;
int jumlahbahan['x']['y'] ;
int hargabahan['x']['y'] ;
int totalharga['x'] ;
int main(){
	
	login:
		cout<<"Login Admin"<<endl ;
		cout<<"Username  : " ;
		cin>>username ;
		cout<<"Password  : " ;
		cin>>password ;
		
		if(username =="admin" && password!="admin123"){
			cout<<"Password salah"<<endl ;
			goto login ;
		}
		else if(username !="admin"&& password =="admin123"){
			cout<<"Username salah"<<endl ;
			goto login ;
		}
		else if(username =="admin" && password=="admin123"){
			cout<<"Login Sukses"<<endl ;
			system("pause") ;
			system("cls") ;
			menu();
		}
		else{
			cout<<"Username dan Password salah"<<endl ;
			goto login ;
		}
		
		
}

void menu(){
	cout<<"Menu"<<endl ;
	cout<<"1. Tambah Makanan"<<endl ;
	cout<<"2. Lihat Makanan"<<endl ;
	cout<<"3. Cari Makanan"<<endl ;
	cout<<"4. Logout"<<endl ;
	cout<<"Pilih : " ;
	cin>>pilih ;
	switch (pilih){
		case 1 :
			tambahmakanan() ;
			break ;
		case 2 :
			lihatmakanan();
			break ;
		case 3 :
			carimakanan();
			break ;
		case 4 :
			system("cls");
			main() ;
			break ;
	}
}

void tambahmakanan(){
	cout<<"Masukan banyak makanan : " ;
	cin>>totalmakanan ;
	cout<<endl ;
	for(int x=1 ; x<=totalmakanan ; x++){
		cout<<"Masukan data makanan ke-"<<x<<endl ;
		cout<<"Nama : " ;cin.ignore();
		getline(cin,namamakanan[x]) ;
		cout<<"Banyak Bahan : " ;
		cin>>banyakbahan[x] ;
		for(int y =1 ; y<=banyakbahan[x] ; y++){
			cout<<"Bahan "<<y<<endl ;
			cout<<"Nama : " ;cin.ignore();
			getline(cin,namabahan[x][y]);
			cout<<"Jumlah : " ;
			cin>>jumlahbahan[x][y] ;
			cout<<"Harga : " ;
			cin>>hargabahan[x][y] ;
			
			hargabahan[x][y]=hargabahan[x][y]*jumlahbahan[x][y] ;
			totalharga[x]=totalharga[x]+jumlahbahan[x][y]+hargabahan[x][y] ;
		}
	}
	
	cout<<"Berhasil memasukan data makanan"<<endl ;
	system("pause") ;
	system("cls") ;
	menu();
}

void lihatmakanan(){
	cout<<"Jumlah makanan : "<<totalmakanan<<endl ;
	for(int x=1 ; x<=totalmakanan; x++){
		cout<<"Data makanan ke-"<<x<<endl ;
		cout<<"Nama : "<<namamakanan[x] ;
		cout<<endl ;
		for(int y=1 ; y<=banyakbahan[x] ; y++){
			cout<<"Bahan "<<y<<endl ;
			cout<<"Nama  : "<<namabahan[x][y]<<endl ; 
			cout<<"Harga : "<<hargabahan[x][y]<<endl ;
			cout<<"Total Harga : "<<totalharga[x]<<endl ;
			cout<<endl ;
		}
}	
	system("pause") ;
	system("cls") ;
	menu();
}

void carimakanan(){
	cout<<"Cari nama makanan : " ;cin.ignore();
	getline(cin,carinama);
	for(int x=1 ; x<=banyakbahan[x]; x++){
		if(carinama==namamakanan[x]){
			cout<<"Data ditemukan"<<endl ;
			cout<<"Data makanan ke-"<<x<<endl ;
			cout<<"Nama : "<<carinama<<endl ;
			for(int y=1 ; y<=banyakbahan[x] ; y++){
				cout<<"Bahan "<<y<<endl ;
				cout<<"Nama : "<<namabahan[x][y] ;
				cout<<endl ;
				cout<<"Harga : "<<hargabahan[x][y] ;
				cout<<endl ;
				cout<<"Total Harga : "<<totalharga[x]<<endl ;
				cout<<"Update data (y/n) ? " ;
				cin>>update ;
				if(update =="y" || update=="Y"){
					bonus();
				}
				else{
					system("pause");
					system("cls") ;
					menu();
				}
					
			}		
		}
	 	else if( carinama !=namamakanan[x]){
	 		}
	 	}
		
		cout<<"Data tidak ditemukan"<<endl ;
		system("pause") ;
		system("cls") ;
		menu();	
}

void bonus(){
	int x ;
	cout<<"Update data makanan ke-"<<x+1<<endl ;
	cout<<"Nama : " ;cin.ignore();
	getline(cin,namamakanan[x]) ;
	for(int y=1 ; y<=banyakbahan[x] ; y++){
		cout<<"Bahan "<<y<<endl ;
		cout<<"Nama : ";
		getline(cin,namabahan[x][y]) ;
		cout<<"Jumlah : " ;
		cin>>jumlahbahan[x][y];
		cout<<"Harga : ";
		cin>>hargabahan[x][y] ;
		cout<<endl ;
		totalharga[x]= 0 ;
		totalharga[x]=totalharga[x]+jumlahbahan[x][y]*hargabahan[x][y] ;
		cin.ignore() ;
	}
	cout<<"Update Berhasil "<<endl ;
	system("pause") ;
	system("cls") ;
	menu() ;
}
