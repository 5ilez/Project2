#include "qlsv.h"
void main() {
    ListStu list;
    initstu(list);
    int choice;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Xuat danh sach\n";
        cout << "3. Tim sinh vien theo ma\n";
        cout << "4. Sua sinh vien theo ma\n";
        cout << "5. Xoa sinh vien theo ma\n";
        cout << "6. Ghi danh sach sinh vien\n";
        cout << "0. Thoat\n";
        cout << "================\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            nhapsv(list);
            break;
        case 2:
            xuatsv(list);
            break;
        case 3: {
            string id;
            cout << "Nhap ma sinh vien can tim: ";
            getline(cin, id);
            stu p = findstu(list, id);
            if (p != NULL)
                cout << setw(10)<< " | Ho va ten: " << p->hoTen
                     << " | Gioi tinh: " << p->gioiTinh
                     << " | Lop: " << p->lop << endl;
            else
                cout << ">> Khong tim thay sinh vien!\n";
            break;
        }
        case 4: {
            string id;
            cout << "Nhap ma sinh vien can sua: ";
            getline(cin, id);
            updatestu(list, id);
            xuatsv(list);
            break;
        }
        case 5: {
            string id;
            cout << "Nhap ma sinh vien can xoa: ";
            getline(cin, id);
            deletestu(list, id);
            xuatsv(list);
            break;
        }
        case 6: {
            ghiFile(list, "student.txt");
            break;
        }
        case 0:
            cout << ">> Thoat chuong trinh!\n";
            break;
        default:
            cout << ">> Lua chon khong hop le!\n";
        }
    } while (choice != 0);
}