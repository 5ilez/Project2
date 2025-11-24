#include "qlsv.h"

void menuStudent(ListStu& list) {
    int choice;
    do {
        cout << "\n===== MENU QUAN LY SINH VIEN =====\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Xuat danh sach\n";
        cout << "3. Tim sinh vien\n";
        cout << "4. Sua sinh vien\n";
        cout << "5. Xoa sinh vien\n";
        cout << "6. Ghi file\n";
        cout << "7. Doc file\n";
        cout << "0. Quay lai\n";
        cout << "=================================\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1: nhapsv(list); break;
        case 2: xuatsv(list); break;
        case 3: {
            string id;
            cout << "Nhap MSSV can tim: ";
            getline(cin, id);

            stu p = findstu(list, id);
            if (p)
                cout << "\nMSSV: " << p->id
                << " | Ho ten: " << p->hoTen
                << " | GT: " << (p->gioiTinh == 1 ? "Nam" : "Nu")
                << " | Lop: " << p->lop << endl;
            else
                cout << ">> Khong tim thay!\n";
            break;
        }
        case 4: {
            string id;
            cout << "Nhap MSSV can sua: ";
            getline(cin, id);
            updatestu(list, id);
            break;
        }
        case 5: {
            string id;
            cout << "Nhap MSSV can xoa: ";
            getline(cin, id);
            deletestu(list, id);
            break;
        }
        case 6: ghiFileStu(list, "student.txt"); break;
        case 7: docFileStu(list, "student.txt"); break;
        }
    } while (choice != 0);
}


void menuSubject(ListSub& list) {
    int choice;
    do {
        cout << "\n===== MENU QUAN LY MON HOC =====\n";
        cout << "1. Them mon hoc\n";
        cout << "2. Xuat danh sach\n";
        cout << "3. Tim mon hoc\n";
        cout << "4. Sua mon hoc\n";
        cout << "5. Xoa mon hoc\n";
        cout << "6. Ghi file\n";
        cout << "7. Doc file\n";
        cout << "0. Quay lai\n";
        cout << "=================================\n";
        cout << "Chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1: nhapmonhoc(list); break;
        case 2: xuatmonhoc(list); break;

        case 3: {
            string ma;
            cout << "Nhap ma mon hoc can tim: ";
            getline(cin, ma);

            sub p = findsub(list, ma);
            if (p)
                cout << "\nMa MH: " << p->maMH
                << " | Ten mon: " << p->tenMH << endl;
            else
                cout << ">> Khong tim thay!\n";
            break;
        }
        case 4: {
            string ma;
            cout << "Nhap ma mon hoc can sua: ";
            getline(cin, ma);
            updatesub(list, ma);
            break;
        }
        case 5: {
            string ma;
            cout << "Nhap ma mon hoc can xoa: ";
            getline(cin, ma);
            deletesub(list, ma);
            break;
        }
        case 6: ghiFileSub(list, "subject.txt"); break;  
        case 7: docFileSub(list, "subject.txt"); break;
        }
    } while (choice != 0);
}


void main() {
    ListStu stuList;
    ListSub subList;

    initstu(stuList);
    initsub(subList);

    int choice;

    do {
        cout << "\n===== MENU CHINH =====\n";
        cout << "1. Quan ly sinh vien\n";
        cout << "2. Quan ly mon hoc\n";
        cout << "0. Thoat\n";
        cout << "======================\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            menuStudent(stuList);
            break;

        case 2:
            menuSubject(subList);
            break;

        case 0:
            cout << "\n>> Thoat chuong trinh!\n";
            break;

        default:
            cout << ">> Lua chon khong hop le!\n";
        }

    } while (choice != 0);
}
