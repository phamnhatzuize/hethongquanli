#include<bits/stdc++.h>
#include<string>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include "xuli.h"
using namespace std;
  
string day_display[] = {"01","02","03","04","05","06","07","08",
                        "09","10","11","12","13","14","15","16",
                        "17","18","19","20","21","22","23","24",
                        "25","26","27","28","29","30"};
                        
string number_Bed[] = {"01","02","03","04","05","06","07","08",
                    "09","10","11","12","13","14","15"};

void gotoxy(short x, short y){
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

void hide_Cursor()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(hOut,&ConCurInf);
}

void show_Pointer()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = TRUE;
    SetConsoleCursorInfo(hOut,&ConCurInf);
} 


void Table_day(int ox, int oy){
    int denta = ox;
    for(int i = 0; i < 30; i++){
        if(i == 6 || i == 12 || i == 18 || i == 24 || i == 30){
            oy = oy + 2;
            ox = denta;
        }
        gotoxy(ox,oy-1);
        cout << "+------+";
        gotoxy(ox,oy);
        cout << "|  ";
        gotoxy(ox+3,oy);
        cout << day_display[i];
        cout <<"  |";
        gotoxy(ox,oy+1);
        cout << "+------+";
        ox = ox + 7;
    }
    hide_Cursor();
}
void table_Bed (int ox, int oy){
    int denta = ox;
        for(int i = 0; i < 15; i++){
        if(i == 3 || i == 6 || i == 9 || i == 12){
            oy = oy + 2;
            ox = denta;
        }
        gotoxy(ox,oy-1);
        cout << "+------+";
        gotoxy(ox,oy);
        cout << "|  ";
        gotoxy(ox+3,oy);
        cout <<number_Bed[i];
        cout <<"  |";
        gotoxy(ox,oy+1);
        cout << "+------+";
        ox = ox + 7;
    }
    hide_Cursor();
}
// ve bang ghe da chon
void table_Bed_choose (int ox, int oy,string &bedchoose){
    int denta = ox;
        for(int i = 0; i < 15; i++){
        if(i == 3 || i == 6 || i == 9 || i == 12){
            oy = oy + 2;
            ox = denta;
        }
        TextColor(15);
        gotoxy(ox,oy-1);
        cout << "+------+";
        if(bedchoose.compare(number_Bed[i]) == 0){
            TextColor(12);
            gotoxy(ox,oy);
            cout << "|  ";
            gotoxy(ox+3,oy);
            cout <<number_Bed[i];
            cout <<"  |";
        }
        TextColor(15);
        gotoxy(ox,oy+1);
        cout << "+------+";
        ox = ox + 7;
    }
    //hide_Cursor();
}


// ham hien thi so ghe da phan loai
void display_2(string &time, string &loaighe, string &soghe){
    if(time == "8"){
        if(loaighe == "A"){
            table_Bed_choose(80,10,soghe);
        }else if(loaighe == "B"){
            table_Bed_choose(80,22,soghe);
        }
    }else if(time == "10"){
        if(loaighe == "A"){
            table_Bed_choose(120,10,soghe);
        }else if(loaighe == "B"){
            table_Bed_choose(120,22,soghe);
        }
    }
}

void nhap1(thongtin_KH &KH){
    int setX = 20;
    int setY = 8;
    TextColor(3);
    TextColor(15);
    Table_day(setX,setY+6);
    show_Pointer();
    gotoxy(80,6);
    cout << "KHUNG GIO XUAT PHAT:";
    TextColor(14);
    gotoxy(107,14);
    cout << "Giuong A";
    gotoxy(107,26);
    cout << "Giuong B";
    TextColor(15);
    table_Bed(80,10);
    table_Bed(80,22);
    table_Bed(120,10);
    table_Bed(120,22);
    show_Pointer();
    TextColor(2);
    gotoxy(65,3);
    cout << "DAT VE XE MIEN TAY TANG THINH KINH:";
    TextColor(15);
    gotoxy(setX,5);
    cout << "So dien thoai: ";
    gotoxy(setX,7);
    cout << "Ho va ten khach hang:";
    gotoxy(setX,9);
    cout << "Dia diem xuat phat: ";
    gotoxy(setX,11);
    cout << "Ngay xuat phat: ";
    gotoxy(setX,26);
    cout << "Nhap ma so chuyen di: ";
    TextColor(9);
    gotoxy(setX,24);
    cout << "(bam 's': den luu ngay / Enter: chon ngay)";
    TextColor(14);
    gotoxy(setX + 15,5);
    cin >> KH.numberphone;
    gotoxy(setX + 22,7);
    cin.ignore();
    getline(cin,KH.name);
    gotoxy(setX + 20,9);
    getline(cin,KH.location);
}

string choose_Day(int ox, int oy,thongtin_KH KH[],int biendem){
    int setX = ox, setY = oy;
    int vtox = ox, vtoy = oy;
    TextColor(15);
    Table_day(ox,oy);
    char c;
    int day = 1;
    int a = 6;
    int setspace = 1;
    TextColor(9);
    gotoxy(setX,setY);
    cout << "| ";
    gotoxy(setX+3,setY);
    cout << day_display[0];
    cout <<"  |";
    show_Pointer();
    gotoxy(setX + 5,setY);
    while(1){
        if(kbhit()){
            c = getch();
            switch(c){
                case 's': {
                    TextColor(14);
                    gotoxy(42,26);
                    cin >> KH[biendem].MS;
                    KH[biendem].day_choose = day_display[day-1];
                    return KH[biendem].day_choose ; 
                    break;
                }
                case 13:{ //enter   
                    TextColor(14);
                    gotoxy(88,8);
                    cout << "8 gio";
                    gotoxy(128,8);
                    cout << "10 gio";
                    gotoxy(36,11);
                    cout <<day_display[day-1];
                    TextColor(15);
                    table_Bed(80,10);
                    table_Bed(80,22);
                    table_Bed(120,10);
                    table_Bed(120,22);
					// check phan loai khach hang theo location 
                    switch(KH[biendem].phanloai){
                        case 0:{
                            for(int i = 0; i < biendem; i++){
                            	// lay tat ca phan tu thuoc dia diem quy dinh 1
                                if(KH[i].phanloai == 0){
                                    if((day_display[day-1]).compare(KH[i].day_choose) == 0){ // check nay cua phan tu trung voi ngay dang chon
                                            tachMS(KH,i);
                                            display_2(KH[i].time,KH[i].loaighe, KH[i].soghe); // in ra man hinh so ghe da book
                                    }
                                }
                            }
                            break;
                        }
                        case 1:{
                            for(int i = 0; i < biendem; i++){
                                if(KH[i].phanloai == 1){
                                    if((day_display[day-1]).compare(KH[i].day_choose) == 0){
                                            tachMS(KH,i);
                                            display_2(KH[i].time,KH[i].loaighe, KH[i].soghe);
                                    }
                                }
                            }
                            break;
                        }
                        case 2:{
                            for(int i = 0; i < biendem; i++){
                                if(KH[i].phanloai == 2){
                                    if((day_display[day-1]).compare(KH[i].day_choose) == 0){
                                            tachMS(KH,i);
                                            display_2(KH[i].time,KH[i].loaighe, KH[i].soghe);
                                    }
                                }
                            }
                            break;
                        }
                        default:{ // tra ve neu dai diem khong co trong danh sach
                            TextColor(15);
                            table_Bed(80,10);
                            table_Bed(80,22);
                            table_Bed(120,10);
                            table_Bed(120,22);
                            break;
                        }
                    } 
                    setX -= 6;
                    setspace -= 1;
                    day -= 1; 
                }
                case 77:{       // phim sang phai
                    setX += 6;
                    day += 1;
                    if(setX == 36 + vtox){
                        setX = vtox;
                        day = day - 6;
                        a = 6;
                        setspace = 0;
                    }
                    setspace ++;
                    gotoxy(setX + a + setspace -1,setY);
                    break;
                }
                case 75:{       	// phim sang trai
                    if(setX == vtox ){
                        setX = vtox + 36;
                        day = day + 6;
                        setspace = 7 ;
                        a = 0;
                    }
                    day -= 1;
                    setspace --;
                    setX -= 6;
                    a = 6;
                    gotoxy(setX + a + setspace -1,setY);
                    break;
                }
                case 72:{       	// phim len
                    if(setY == vtoy ){
                        setY = vtoy + 10;
                        day = day + 30;
                    } 
                    day -= 6;
                    gotoxy(setX + a + setspace - 1,setY-2) ;
                    setY -= 2;
                    break;
                }
                case 80:{       	// phim xuong 
                    if(setY == vtoy + 8){
                        setY = vtoy - 2;
                        day = day - 30;
                    }
                    day += 6;
                    gotoxy(setX + a + setspace -1 ,setY+2) ;
                    setY += 2;
                    break;
                }
            }
            TextColor(15);
            hide_Cursor();
            Table_day(vtox,vtoy);
            TextColor(9);
            show_Pointer();
            gotoxy(setX + setspace - 1,setY);
            cout << "| ";
            gotoxy(setX + 2 + setspace,setY);
            cout << day_display[day-1]; 
            cout << "  |";
            gotoxy(setX + a + setspace - 1,setY);
        }
    }
}

void nhap_Du_Lieu(thongtin_KH KH[], int &biendem){
    nhap1(KH[biendem]);
    phanloaiKH(KH,biendem);
    choose_Day(20,14,KH,biendem);
    gotoxy(30,29);
    TextColor(14);
    cout << "Them thanh cong";
	++biendem;
    gotoxy(30,31);
	cout << "So luong KH la: " << biendem;
}

void line(int biendem){
    for(int i = 0; i < (biendem +1); i++){
        cout << "-";
    }
}
void table(int ox, int oy,int a,thongtin_KH &KHV,int ant,int Space,int denta){
    gotoxy(ox-2*a,oy);
    cout << "|";
    gotoxy(ox-a-2,oy);
    cout << ant;
    gotoxy(ox-a+1,oy);
    cout << "|";
    gotoxy((ox + a),oy);
    cout <<KHV.name;
    gotoxy((Space + 2*ox -denta),oy); 
    cout << "|"; 
    gotoxy((Space + 2*ox -denta)+4,oy);
    cout << KHV.numberphone ;
    gotoxy((Space + 2*ox -denta)+16,oy);
    cout << "|";
    gotoxy((Space + 2*ox - denta)+19, oy);
    cout << "Da Nang - ";cout <<KHV.location;
    gotoxy((Space + 2*ox - denta)+43,oy);
    cout <<"|";
    gotoxy((Space + 2*ox - denta)+46,oy);
    cout << KHV.MS;
    gotoxy((Space + 2*ox - denta)+55,oy);
    cout <<"|"; 
    gotoxy((Space + 2*ox - denta)+60,oy);
    cout << KHV.day_choose;
    gotoxy((Space + 2*ox - denta)+65,oy);
    cout <<"|";
}

void xuat_Du_Lieu(thongtin_KH KH[], int &biendem){
    int Space;
    Space = Spacestring(KH,biendem);
    int a = 5;
    int ox = 40;
    int denta = 25;
    int cnt = 0;
    gotoxy(ox+27,a-3);
    TextColor(14);
    cout << "DANH SACH KHACH HANG";
    TextColor(15);
    gotoxy(ox-10,a);
	line((Space + ox - denta )+75);
    gotoxy(ox-2*a,a+1);
    cout << "| STT ";
    gotoxy(ox-(a - 1),a+1);
   	cout << "|          Ho va ten";
    gotoxy((Space + 2*ox - denta),a+1);
    cout << "|      STD      |         Tuyen di         |   MSCD    | Ngay XP |";
    gotoxy(ox-2*a,a+2);
    line((Space + ox- denta )+75);
    int kc = 8;
    for(int i = 0; i < biendem; i++){
        if(i > 0){ kc = kc + 1;}
        cnt ++;
        int oy = i + kc;
        table(ox,oy,a,KH[i],cnt,Space,denta);
        gotoxy(ox-10,oy + 1);
        line((Space + ox - denta )+75);
    //	cout << "\nTien dien: " <<KH[i].tiendien * 3200 <<" VND\n";
    }
}

// ham xu li in ra danh sach va dieu khien danh sach
int Indanhsachtimkiem( thongtin_KH KH[], int &biendem, int &m){
	string KHx,ten;
    int cnt = 0;
    int check = -1;
    int Space;
    int denta = 0;
    Space = Spacestring(KH,biendem);
    int a = 5;
    int ox = 10;
    int kc = 6;
    gotoxy(ox-10,a);
	line((Space + ox - denta )+75);
    gotoxy(ox-2*a,a+1);
    cout << "| STT ";
    gotoxy(ox-(a - 1),a+1);
   	cout << "|          Ho va ten";
    gotoxy((Space + 2*ox - denta),a+1);
    cout << "|      STD      |         Tuyen di         |   MSCD    | Ngay XP |";
    gotoxy(ox-2*a,a+2);
    line((Space + ox- denta )+75);
    gotoxy(0,3);
	cout << "Nhap ten tim kiem: ";
    cin >> ten;
    if(biendem == 0){
        TextColor(14);
        gotoxy(ox-2*a+30,a+5);
        cout << "Khong co du lieu";
    }else{
        for(int i = 0; i < biendem; i++){
            KHx = tachten(KH[i].name) ;
            if (ten.compare(KHx) == 0){
                cnt += 1;
                KHcon[cnt].name = KH[i].name ; 
                KHcon[cnt].location = KH[i].location;
                KHcon[cnt].numberphone = KH[i].numberphone ;
                KHcon[cnt].MS = KH[i].MS;
                KHcon[cnt].day_choose = KH[i].day_choose;
                KH[i].timkiem = cnt;
                table(ox,2*cnt+kc,a,KH[i],cnt,Space,denta );
                gotoxy(ox-10,2*cnt+ kc + 1);
                line((Space + ox- denta )+75);
                check = 0;
            }
        }
        char c;
        int oy = 8;
        int choice = 1;
        if(check == 0){
            TextColor(3);
            table(ox,oy,a,KHcon[choice],choice,Space,denta);
            gotoxy((Space + ox + 2*a)+65,oy);
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
                            gotoxy((Space + ox + 2*a)+65,oy-2);
                            oy -= 2;
                            choice -= 1;
                            break;
                        }
                        case 80:{           //xuong
                            if(oy == (8 + 2*cnt -2)){
                                oy = 6 ;
                                choice = 0;
                            }
                            gotoxy((Space + ox + 2*a)+65,oy+2);
                            oy += 2;
                            choice += 1;
                            break;
                        }
                        default: ;
                    }

                    TextColor(15);
                    for(int i = 1; i <= cnt; i++){
                        table(ox,2*i+kc,a,KHcon[i],i,Space,denta);
                    }

                    TextColor(3);
                    table(ox,oy,a,KHcon[choice],choice,Space ,denta);
                    gotoxy((Space + ox + 2*a)+65,oy);
                }
            }
        }else{
            TextColor(14);
            gotoxy(ox-2*a+30,a+5);
            cout << "Khong co du lieu";
            m = -1;
            return m;
        }
    }
}

// chinh sua du lieu khach hang
// void update_Du_lieu(thongtin_KH KH[],int index,int ox, int oy){
//     int n;
//     gotoxy(ox,oy);
//     cout << "1. Ho ten";
//     gotoxy(ox,oy+1);
//     cout << "2. MSKH";
//     do{
//         gotoxy(ox,oy+2);
//         cout << "nhap thong tin can sua: ";
//         cin >> n;
//         if(n == 1){
//             gotoxy(ox,oy+3);
//             cout << "nhap ho va ten khach hang: ";
//             TextColor(15);
//             cin.ignore();
//             getline(cin,KH[index].name);
//         }else if(n == 2){
//             gotoxy(ox,oy+3);
//             cout << "nhap MSKH: ";
//             TextColor(15);
//             cin >> KH[index].;
//         }
//     }while((n > 2 || n < 1) && cout << "\n khong co lua chon. Nhap lai!!!\n");
//     TextColor(14);
//     gotoxy(ox,oy+4);
//     cout << "Cap nhat thanh cong !!!";
// }

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
    m = Indanhsachtimkiem(KH,biendem,m);
    for(int i = 0; i < biendem; i++){
        if(KH[i].timkiem == m){
            dkmenu2(KH,biendem,n);
            switch(n){
               // case 1: update_Du_lieu(KH,i,ox,oy); break;
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
    s[11]= "| 1. Dat ve ten lua   |";
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
    // thay mau cho s[0]; s[0] mau 15 dang dè len s[0] mau 3
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
    int check = 0;
    int n = 0;
    int biendem;
    fstream infile("dulieu.txt");
    infile >> biendem;
        for(int i = 0; i < biendem; i++){
            getline(infile, KH[i].name);
            getline(infile, KH[i].numberphone);
            getline(infile, KH[i].location);
            getline(infile, KH[i].MS);
            getline(infile, KH[i].day_choose);
    } 
    infile.close();
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



