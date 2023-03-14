#include<bits/stdc++.h>
#include<string>
#include<windows.h>
#include<conio.h>
using namespace std;


struct thongtin_KH{
    string quequan,hoten;
    int timkiem; 
    string sohogd ;
    string MSKH;
 //   int tiendien = rand() % 100;
} KH[100], KHcon[100];

void gotoxy(short x, short y)
{
 HANDLE hConsoleOutput;
 COORD Cursor_an_Pos = { x, y };
 hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void TextColor(int x)
{
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}
// ham bat su kien tu ban phim de quay lai 
int return_p(int  &m ){
    char c;
    while(1){
        if(kbhit()){
            c = getch();
            switch(c){
                case 75:m = 1 ;return m;break; // phim <-

                case 27: m = 0;return m;break; // phim Esc
            }
        }
    }
} 

void nhap1(thongtin_KH &KH, int &biendem){
    gotoxy(50,15);
    cout << "nhap so ho gia dinh: ";
    gotoxy(50,16);
    cout << "nhap ho va ten khach hang:";
    gotoxy(50,17);
    cout << "nhap que quan: ";
    gotoxy(70,15);
    cin >> KH.sohogd;
    gotoxy(77,16);
    cin.ignore();
    getline(cin,KH.hoten);
    gotoxy(65,17);
    cin.ignore(0);
    getline(cin,KH.quequan);
   // cin.ignore();
    gotoxy(60, 20);
    cout << "Them thanh cong";
}

void nhap_Du_Lieu(thongtin_KH KH[], int &biendem){
	nhap1(KH[biendem], biendem);
	++biendem;
    gotoxy(60,21);
	cout << "So luong KH la: " << biendem;
}

string tachchucaidau(string qq){
    string thugon;
    for(int i = 0 ; i < qq.length(); i++){
        if(qq[i] == ' '){
            thugon = thugon + qq[i+1];
        }
    }
    thugon = qq[0]+thugon;
    return thugon; 
}
int Spacestring(thongtin_KH KHspace[], int &biendem){
    int Space = (KHspace[0].hoten).length();
    for(int i = 0; i < biendem; i++){
        if((KHspace[i].hoten).length() > Space)
            Space = (KHspace[i].hoten).length();
        }
    return Space;
}
void line(int biendem){
    for(int i = 0; i < (biendem +1); i++){
        cout << "-";
    }
}
void table(int ox, int oy,int a,thongtin_KH &KHV,int ant,int Space,int denta){
    gotoxy(ox-2*a,oy);
    cout << "|";
    gotoxy(ox-a,oy);
    cout << ant;
    gotoxy(ox,oy);
    cout << "|";
    gotoxy((ox + 2*a),oy);
    cout <<KHV.hoten;
    gotoxy((Space + 2*ox -denta),oy); 
    cout << "|"; 
    gotoxy((Space + 2*ox -denta)+10,oy);
    cout << KHV.quequan ;
    gotoxy((Space + 2*ox -denta)+29,oy);
    cout << "|";
    gotoxy((Space + 2*ox - denta)+37, oy);
    KHV.MSKH = (tachchucaidau(KHV.quequan) + KHV.sohogd);
    cout << KHV.MSKH;
    gotoxy((Space + 2*ox - denta)+47,oy);
    cout <<"|";
}

// ham tim vi tri can tim
int check_MSKH(int biendem, thongtin_KH KH[],string checkMS){
    int bienxuat = -1;
    for(int i = 0; i < biendem && bienxuat == -1; i++){
        // Khi bienxuat gan bang i can phai co dieu kien de out vong lap
        // Co the su dung lenh break;
        if(checkMS == KH[i].MSKH) {
		    bienxuat = i; 
	    }else{
		     bienxuat = -1;
	    }
    }
    return bienxuat;
}

// xoa du lieu khach hang

void xuat_Du_Lieu(thongtin_KH KH[], int &biendem){
    int Space;
    Space = Spacestring(KH,biendem);
    int a = 5;
    int ox = 45;
    int denta = 25;
    int cnt = 0;
    gotoxy(ox+27,a-3);
    TextColor(14);
    cout << "DANH SACH KHACH HANG";
    TextColor(15);
    gotoxy(ox-10,a);
	line((Space + ox -denta )+57);
    gotoxy(ox-2*a,a+1);
    cout << "|   STT    ";
    gotoxy(ox,a+1);
   	cout << "|          Ho va ten";
    gotoxy((Space + 2*ox - denta),a+1);
    cout << "|          que quan          |       MSKH      |";
    gotoxy(ox-2*a,a+2);
    line((Space + ox- denta )+57);
    int kc = 8;
    for(int i = 0; i < biendem; i++){
        if(i > 0){ kc = kc + 1;}
        cnt ++;
        int oy = i +kc;
        table(ox,oy,a,KH[i],cnt,Space,denta);
        gotoxy(ox-10,oy + 1);
        line((Space + ox - denta )+57);
    //	cout << "\nTien dien: " <<KH[i].tiendien * 3200 <<" VND\n";
    }
}

string tachten(string &KH){
	int cnt;
	for (int i = KH.length(); i > 0 ; i--){
		if (KH[i] == ' '){
            cnt = i; 
            break;   
        } 
	}
	return KH.substr((cnt + 1),KH.length());  // tra ve chuoi da duoc cat
}

// ham xu li in ra danh sach va dieu khien danh sach
int SearchNamexuli( thongtin_KH KH[], int &biendem, int &m){

	string KHx,ten;
    int cnt = 0;
    int Space;
    int denta =0;
    Space = Spacestring(KH,biendem);
    int a = 5;
    int ox = 10;
    int kc = 6;
    gotoxy(ox-10,a);
	line((Space + ox+ 2*a )+57);
    gotoxy(ox-2*a,a+1);
    cout << "|   STT    ";
    gotoxy(ox,a+1);
   	cout << "|          Ho va ten";
    gotoxy((Space + 2*ox + 2*a ),a+1);
    cout << "|          que quan          |       MSKH      |";
    gotoxy(ox-2*a,a+2);
    line((Space + ox + 2*a)+57);
    gotoxy(0,3);
	cout << "Nhap ten tim kiem: ";
    gotoxy(20,3);
    cin >> ten;
	for(int i = 0; i < biendem; i++){
		KHx = tachten(KH[i].hoten) ;
		if (ten.compare(KHx) == 0){
			cnt += 1;
            KHcon[cnt].hoten = KH[i].hoten ; 
            KHcon[cnt].quequan = KH[i].quequan;
            KHcon[cnt].sohogd = KH[i].sohogd ;
            KH[i].timkiem = cnt;
            table(ox,2*cnt+kc,a,KH[i],cnt,Space + ox,denta );
            gotoxy(ox-10,2*cnt+ kc + 1);
            line((Space + ox + 2*a)+57);
        }
	}
	char c;
    int oy = 8;
    int choice = 1; 
    TextColor(3);
    table(ox,oy,a,KHcon[choice],choice,Space+ ox,denta);
    gotoxy((Space + ox + 2*a)+58,oy);
    while(1){
        if(kbhit()){
            c = getch();
            switch(c){
                case 13:{
                    m = choice;
                    return m;

                    break;
                }
                       // len
                case 72:{ 
                    if(oy == 8){
                         oy = (oy + 2*cnt);
                         choice = cnt + 1;
                    }
                    gotoxy((Space + ox + 2*a)+58,oy-2);
                    oy -= 2;
                    choice -= 1;
                    break;
                }
                case 80:{           //xuong
                    if(oy == (8 + 2*cnt -2)){
                        oy = 6 ;
                        choice = 0;
                    }
                    gotoxy((Space + ox + 2*a)+58,oy+2);
                    oy += 2;
                    choice += 1;
                    break;
                }
                default: ;
            }

            TextColor(15);
            for(int i = 1; i <= cnt; i++){
                table(ox,2*i+kc,a,KHcon[i],i,Space+ ox,denta);
            }

            TextColor(3);
            table(ox,oy,a,KHcon[choice],choice,Space + ox,denta);
            gotoxy((Space + ox + 2*a)+58,oy);
        }
    }
}
// chinh sua du lieu khach hang
void update_Du_lieu(thongtin_KH KH[],int index,int ox, int oy){
    int n;
    gotoxy(ox,oy);
    cout << "1. Ho ten";
    gotoxy(ox,oy+1);
    cout << "2. MSKH";
    do{
        gotoxy(ox,oy+2);
        cout << "nhap thong tin can sua: ";
        cin >> n;
        if(n == 1){
            gotoxy(ox,oy+3);
            cout << "nhap ho va ten khach hang: ";
            TextColor(15);
            cin.ignore();
            getline(cin,KH[index].hoten);
        }else if(n == 2){
            gotoxy(ox,oy+3);
            cout << "nhap MSKH: ";
            TextColor(15);
            cin >> KH[index].MSKH;
        }
    }while((n > 2 || n < 1) && cout << "\n khong co lua chon. Nhap lai!!!\n");
    TextColor(14);
    gotoxy(ox,oy+4);
    cout << "Cap nhat thanh cong !!!";
}
// Xoa du lieu
void delname(int &biendem, thongtin_KH KH[],int index){
        // Khi index o vi tri cuoi
	if(index == (biendem - 1)){
		KH[index].hoten == "";
        KH[index].MSKH == "";
	}else{   //khi index o dau hoac giua
		for(int i = index; i < biendem - 1 ; i++){
    	    		KH[i] = KH[i + 1];
    		}
	}
        biendem -= 1;
}

// dieu khien cac chuc nang 
int dkmenu2(thongtin_KH KH[], int biendem, int &n){
    int Space;
    Space = Spacestring(KH,biendem);
    int ox =  Space + 85;
    int oy = 10;
    string s[100];
    int oy1 = 10;
    TextColor(15);
        gotoxy(ox,oy);
        cout << "Moi ban lua chon:";
        s[1] = "| 1. Chinh sua thong tin |";
        s[2] = "| 2. Xoa khach hang      |";
        s[3] = "| 3. In hoa don          |";
        gotoxy(ox,oy + 1);
        cout << "+------------------------+";
        for(int j = 1; j <= 3; j++){
            gotoxy(ox,oy+2*j);
            cout << s[j];
            gotoxy(ox,oy+2*j+1);
            cout << "+------------------------+";
        }
    TextColor(3);
        gotoxy(ox,oy+2);
        cout << s[1];
    char c;
   while (1) {
        if (kbhit()) {
            c = getch();
            switch (c) {
                case 13: { // phim enter
                    return n;
                }
                case 72: { // len
					oy -= 2; 
                    if (oy < 12){
						oy = 16;
						n = 4;
					}
                    gotoxy(ox+25,oy);  
					n -= 1;
                    break;
                }
                case 80: { // xuong
                    oy += 2;  
                    if(oy > 16){
                        oy = 12;
                         n = 0;
                    }
                    gotoxy(ox+25,oy);
                    n +=1;
                    break;
                }
                
            }
        
            TextColor(15);
                gotoxy(ox,oy1 + 1);
                cout << "+------------------------+";
                for(int j = 1; j <= 3; j++){
                    gotoxy(ox,oy1+2*j);
                    cout << s[j];
                    gotoxy(ox,oy1+2*j+1);
                    cout << "+------------------------+";
                }
            TextColor(3);
                gotoxy(ox,oy);
                cout << s[n];
        }
    }
}
void SearchName(thongtin_KH KH[],int &biendem){
    int m;
    int n = 0;
    int i = 0;
    int Space;
    Space = Spacestring(KH,biendem);
    int ox =  Space + 85;
    int oy = 18;
    m = SearchNamexuli(KH,biendem,m);
    for(int i = 0; i < biendem; i++){
        if(KH[i].timkiem == m){
            dkmenu2(KH,biendem,n);
            switch(n){
                case 1: update_Du_lieu(KH,i,ox,oy); break;
                case 2:	{
                        delname(biendem,KH,i);
                        TextColor(14);
                        gotoxy(ox,oy) ;
                        cout << "Da xoa du lieu !!!";
                        break;}
                default: ;
             }
        }
    }    
}

// menu lua chon
int menu1(int &dk){
    int ox = 65;
    string s[1000];
    s[11]= "| 1. Them khach hang  |";
    s[13]= "| 2. Xoa khach hang   |";
    s[15]= "| 3. Xuat danh sach   |";
    s[17]= "| 4. Cap nhat du lieu |";
    s[19]= "| 5. Tim theo ten     |";
    s[21]= "| 6. Thoat            |";
    // ve bang menu
    TextColor(3);
    gotoxy(ox,10);
    cout << "+---------------------+";
   
        for(int i = 11; i < 23; i += 2){
            gotoxy(ox,i);
            cout << s[i];
            gotoxy(ox,i+1);
            cout << "+---------------------+";
        }
    // thay mau cho s[0]; s[0] mau 15 đang đè len s[0] mau 3
    TextColor(15);
    gotoxy(ox,11);
    cout << s[11];
    // bat su kien tu ban phim 
    gotoxy(ox+20,11);
    char c;
    while (1) {
        if (kbhit()) {
            c = getch();
            switch (c) {
                case 13: { // phim enter
                    //system("cls");
                    if(dk == 21)
                        return 0;
                    return dk;
                }
                case 72: { // len
                    if(dk == 11){
                        dk = 23;
                    }   
                    gotoxy(ox+20,dk-2);   
                    dk -= 2;
                    break;
                }
                case 80: { // xuong
                    if (dk == 21){
                    	dk = 9;
					}
                    gotoxy(ox+20,dk+2);
                    dk += 2;
                    break;
                }
                default: ;
            }
            // SAU KHI DIEU KHIEN PHIM VE LAI BANG MENU
            TextColor(3);
            gotoxy(ox,10);
            cout << "+---------------------+";
            for(int i = 11; i < 23; i += 2){
                gotoxy(ox,i);
                cout << s[i];
                gotoxy(ox,i+1);
                cout << "+---------------------+";
            }
            // CHO CAC PHAN TU MA ON TRO DANG CHI DOI MAU
                TextColor(15);
                gotoxy(ox,dk);
                cout << s[dk];
        }
    }
}

int main(){
    int m = 11;
    int biendem = 0;
    int check = 0;
    int n = 0;
    thongtin_KH KH[100];
   do{      
            if(check == 1) system("cls");m = 11;
            menu1(m);
            system("cls");
            switch(m){
                case 11: nhap_Du_Lieu(KH, biendem);break;
                // case 13: xoa_KH(biendem,KH) ;break;
                case 15: xuat_Du_Lieu(KH,biendem) ;break;
                // case 17: update_Du_lieu(biendem, KH);break;
                case 19: SearchName(KH,biendem);break;
                default: ;
            } 
            TextColor(14);
            gotoxy(70,35);
            cout << "nhan <- de quay lai";
            gotoxy(70,36); 
            cout << "nhan Esc de thoat";
            gotoxy(90,35);
            return_p(check);  
    }while((check == 1));
    return 0;
}


