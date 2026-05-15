#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct KhachHang{

    int id;

    string ten;

    int start;

    int end;

    int loiNhuan;

    int taiSan;
};

string tenKH[] = {
    "An",
    "Binh",
    "Cuong",
    "Dung",
    "Huy",
    "Khanh",
    "Long",
    "Minh"
};

int n;

int S;

int f[100][100] = {0};

void khoiTao(KhachHang d[]){

    for(int i = 0; i < n; i++){

        d[i].id = i + 1;

        d[i].ten = tenKH[rand() % 8];

        d[i].start = rand() % 10;

        d[i].end =
            d[i].start + rand() % 5 + 1;

        d[i].loiNhuan =
            rand() % 500 + 100;

        d[i].taiSan =
            rand() % 8 + 1;
    }
}

void hienThi(KhachHang d[]){

    cout << "\nDanh sach khach hang:\n\n";

    for(int i = 0; i < n; i++){

        cout << "KH "
             << d[i].id
             << " | "
             << d[i].ten
             << " | "
             << d[i].start
             << " -> "
             << d[i].end
             << " | Loi nhuan: "
             << d[i].loiNhuan
             << " | Tai san: "
             << d[i].taiSan
             << endl;
    }

    cout << endl;
}

void sortEnd(KhachHang d[]){

    for(int i = 0; i < n - 1; i++){

        for(int j = 0; j < n - i - 1; j++){

            if(d[j].end > d[j+1].end){

                KhachHang tmp = d[j];

                d[j] = d[j+1];

                d[j+1] = tmp;
            }
        }
    }
}

void greedy(KhachHang d[]){

    sortEnd(d);

    cout << "\n===== THAM LAM =====\n";

    cout << "\nLich phuc vu toi da:\n\n";

    int count = 1;

    cout << "KH "
         << d[0].id
         << " | "
         << d[0].ten
         << endl;

    int lastEnd = d[0].end;

    for(int i = 1; i < n; i++){

        if(d[i].start >= lastEnd){

            cout << "KH "
                 << d[i].id
                 << " | "
                 << d[i].ten
                 << endl;

            lastEnd = d[i].end;

            count++;
        }
    }

    cout << "\nSo khach phuc vu nhieu nhat: "
         << count
         << endl;
}

KhachHang maxProfit(KhachHang d[], int l, int r){

    if(l == r){

        return d[l];
    }

    int mid = (l + r) / 2;

    KhachHang left =
        maxProfit(d, l, mid);

    KhachHang right =
        maxProfit(d, mid + 1, r);

    if(left.loiNhuan > right.loiNhuan){

        return left;
    }

    return right;
}

void dp(KhachHang d[]){

    for(int i = 1; i <= n; i++){

        for(int j = 0; j <= S; j++){

            f[i][j] = f[i-1][j];

            if(d[i-1].taiSan <= j){

                int tmp =
                    d[i-1].loiNhuan
                    + f[i-1][j-d[i-1].taiSan];

                if(tmp > f[i][j]){

                    f[i][j] = tmp;
                }
            }
        }
    }
}

void truyVet(KhachHang d[]){

    cout << "\n===== QUY HOACH DONG =====\n";

    int i = n;

    int j = S;

    int count = 0;

    while(i > 0 && j > 0){

        if(f[i][j] != f[i-1][j]){

            cout << "KH "
                 << d[i-1].id
                 << " | "
                 << d[i-1].ten
                 << " | Loi nhuan: "
                 << d[i-1].loiNhuan
                 << " | Tai san: "
                 << d[i-1].taiSan
                 << endl;

            j -= d[i-1].taiSan;

            count++;
        }

        i--;
    }

    cout << "\nSo khach duoc chon: "
         << count
         << endl;

    cout << "Tong loi nhuan toi uu: "
         << f[n][S]
         << endl;
}

int main(){

    srand(time(0));

    do{
        cout << "Nhap n: ";
        cin >> n;
    }while(n < 5 || n > 10);

    cout << "Nhap suc chua tai san S: ";
    cin >> S;

    KhachHang d[20];

    khoiTao(d);

    hienThi(d);

    greedy(d);

    cout << "\n===== CHIA DE TRI =====\n";

    KhachHang best =
        maxProfit(d, 0, n - 1);

    cout << "\nKhach hang loi nhuan lon nhat:\n";

    cout << "KH "
         << best.id
         << " | "
         << best.ten
         << " | Loi nhuan: "
         << best.loiNhuan
         << endl;

    dp(d);

    truyVet(d);

    return 0;
}