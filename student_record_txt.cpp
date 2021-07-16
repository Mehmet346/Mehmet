#include <iostream>
#include <fstream>
using namespace std;

struct ogrenci
{
    int id;
    string name;
    string surname;
};


void write_txt(ogrenci *stu[],int size);

void update(ogrenci *stu[],int sid,int size)
{
	int j{0};
	int target{};
	do
	{
		j++;
		target = j;
	}
	while (stu[j]->id != sid);
	
	cout << "\nYeni Ogrenci Numarasi : ";
	cin >> stu[target]->id;

	cout << "\nYeni Ogrenci Adi	: ";
	cin >> stu[target]->name;

	cout << "\nYeni Ogrenci Soyadi	: ";
	cin >> stu[target]->surname;
	cout << endl;
}

void fill(ogrenci *stu[],int number, int size)
{
	int id;
	cout << number+1 <<". ogrenci :"<< endl;
	while(1)
	{
		bool varMi = false;
		cout<<"Id : ";
		cin>>id; 
		int i = 0;
		while(stu[i] != NULL)
		{
			if(stu[i]->id == id)   //stu[i]->id = 10     id = 10
			{
				varMi = true;
				break;
			}
			i++;
		}
		if(varMi == false)
		{
			stu[number] = new ogrenci;
			stu[number]->id = id;
			cout<<"Name : ";
			cin>>stu[number]->name;
			cout<<"Surname : ";
			cin>>stu[number]->surname;
			break;
		}
		else
		{
			cout<<"Bu Id Zaten Kullanimda. Lutfen Baska Bir Id Deneyiniz";
		}
	}
}

void remove(ogrenci *stu[],int rid,int size) // Ã‡alÄ±ÅŸmÄ±yor
{
    int j{};
	int target {};
	do
	{
		j++;
		target = j;
	} while (stu[j]->id != rid);
	
    if(stu[target]->id == rid)
    {
        stu[target] = NULL;
    }
}

void search(ogrenci *stu[],int kid,int size)
{
	int j{0};
	int target{};
	do
	{
		j++;
		target = j;
	}
	while (stu[j]->id != kid);
	
	cout << "\nOgrenci Numarasi	:	" << stu[target]->id << endl;
	cout << "\nOgrenci Adi		:	" << stu[target]->name << endl;
	cout << "\nOgrenci Soyadi		:	" << stu[target]->surname << endl;
	cout << endl;
}
 
void print(ogrenci *stu[],int size)
{
	for(int k = 0 ; k < size ; k++)
	{
		cout << "------------" << k+1 << ". Ogrenci" << "------------" << endl;
		cout << "Numarasi : " << stu[k]->id << endl;
		cout << "Adi : " << stu[k]->name << endl;
		cout << "Soyadi : " << stu[k]->surname << endl;
		cout << endl;
	}
}

void write_txt(ogrenci *stu[],int size)
{
	int a{0};
	remove("student.txt");
	ofstream write;
	
	do
	{
		write.open("student.txt",ios::app);
		write << "------------" << a+1 << ". Ogrenci" << "------------" << endl;
		write << "Numarasi : " << stu[a]->id << endl;
		write << "Adi : " << stu[a]->name << endl;
		write << "Soyadi : " << stu[a]->surname << endl;
		write << endl;
		write.close();
		++a;
	} while (stu[a] != NULL && a < size);
}

int main()
{
	int i{0};
    int size {};
	cout << "Kac ogrenci eklemek istersiniz : ";
	cin >> size;
    ogrenci *stu[size+1] = {};
	int sayi{};

    do
    {
        cout << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "1 - Ekleme\n2 - Guncelleme\n3 - Silme\n4 - Arama\n5 - Yazdirma\n6 - Cikis" << endl;
        cout << endl;
        cout << "Hangi Islemi Yapmak Istersiniz : ";
        cin >> sayi;
        cout << "---------------------------------------------------------------------------" << endl;
        
        if (sayi == 1)
        {
            fill(stu,i++,size);
			write_txt(stu,size);
        }
        else if (sayi == 2)
        {
            int sid;
            cout << "Degisiklik yapmak istediginiz ogrenci numarasi : ";
            cin >> sid;
            update(stu,sid,size);
			write_txt(stu,size);
        }
        else if (sayi == 3)
        {
            int rid;
            cout << "Kacinci numarali ogrenci bilgilerini silmek istersiniz(Ogrencinin okul numarasina baglÄ± olarak calisir) : ";
            cin >> rid;
            remove(stu ,rid,size);
        }
        else if (sayi == 4)
        {
            int kid;
            cout << "Kacinci numarali ogrenci uzerinde degisiklik yapmak istersiniz(Ogrencinin okul numarasina baglÄ± olarak calisir) : ";
            cin >> kid;
            search(stu,kid,size);
        }
        else if (sayi == 5)
        {
            print(stu,size);
        }
        else if (sayi == 6)
        {
            cout << "Sistem Kapatiliyor !" << endl;
        }
        else
        {
            cout << "Hatali tuslama yaptiniz" << endl;
        }
    } while ( sayi != 6 );
    
    return 0;
}
