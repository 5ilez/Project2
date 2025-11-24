#include"qlsv.h"
void initstu(ListStu& list) {
	list.first = list.last = NULL;
}
int isEmptstu(ListStu list) {
	return (list.first == NULL ? 1 : 0);
}
stu createNodestu(Student x) {
    stu p = new Student;
    *p = x;
    p->next = NULL;
    p->pre = NULL;
    return p;
}
void addStu(ListStu& list, Student x) {
    stu p = createNodestu(x);
    if (isEmptstu(list)) {
        list.first = list.last = p;
    }
    else {
        list.last->next = p;
        p->pre = list.last;
        list.last = p;
    }
}
bool isDuplicatestu(ListStu list, const string& id) {
    stu p = list.first;
    while (p != NULL) {
        if (p->id==id)
            return true;
        p = p->next;
    }
    return false;
}
void nhapsv(ListStu& list) {
    Student student;
    cin.ignore();
    do {
        cout << "\nNhap MSSV (0: exit): ";
        getline(cin, student.id);
        while (isDuplicatestu(list, student.id)) {
            cout << "\n>> Sinh vien nay da ton tai!";
            cout << "\n>> Vui long nhap lai MSSV: ";
            getline(cin, student.id);
        }
        if (student.id == "0") //Nhap MSSV = 0 de thoat
            break;
        cout << "\nNhap ho va ten: ";
        getline(cin, student.hoTen);
        cout << "Nhap gioi tinh (1: Nam, 2: Nu): ";
        cin >> student.gioiTinh;
        cin.ignore();
        cout << "Nhap lop: ";
        getline(cin, student.lop);
        
        addStu(list, student);
    } while (1);
}
void xuatsv(ListStu list) {
    if (isEmptstu(list)) {
        cout << "\n>> Danh sach rong!";
        return;
    }
    cout << "\nDANH SACH SINH VIEN\n";
    cout << left << setw(12) << "MSSV"
         << left << setw(25) << "| Ho va ten"
         << left << setw(15) << "| Gioi tinh"
         << left << setw(10) << "| Lop" << endl;

     cout << string(60, '-') << endl; 

     for (stu p = list.first; p != NULL; p = p->next) {
         cout << left << setw(12) << p->id
              << left << setw(25) << ("| " + p->hoTen)
              << left << setw(15) << ("| " + string(p->gioiTinh == 1 ? "Nam" : "Nu"))
              << left << setw(10) << ("| " + p->lop) << endl;
     }
}
stu findstu(ListStu list, const string& id) {
    stu p = list.first;
    while (p != NULL) {
        if (p->id == id)
            return p;
        p = p->next;
    }
    return NULL;
}
void updatestu(ListStu& list, const string& id) {
    stu p = findstu(list, id);
    if (p == NULL) {
        cout << "\n>> Khong tim thay sinh vien can sua!\n";
        return;
    }

    cout << "\nNhap ho va ten moi: ";
    getline(cin, p->hoTen);
    cout << "Nhap gioi tinh moi (1: Nam, 2: Nu): ";
    cin >> p->gioiTinh;
    cin.ignore();
    cout << "Nhap lop moi: ";
    getline(cin, p->lop);

    cout << ">> Da cap nhat sinh vien thanh cong!\n";
}
void deletestu(ListStu& list, const string& id) {
    stu p = findstu(list, id);
    if (p == NULL) {
        cout << "\n>> Khong tim thay sinh vien can xoa!\n";
        return;
    }

    // Neu chi co 1 phan tu
    if (p == list.first && p == list.last) {
        list.first = list.last = NULL;
    }
    // Neu xoa dau
    else if (p == list.first) {
        list.first = p->next;
        list.first->pre = NULL;
    }
    // Neu xoa cuoi
    else if (p == list.last) {
        list.last = p->pre;
        list.last->next = NULL;
    }
    // Neu xoa giua
    else {
        p->pre->next = p->next;
        p->next->pre = p->pre;
    }

    delete p;
    cout << ">> Da xoa sinh vien thanh cong!\n";
}


void ghiFileStu(ListStu list, const string& filename) {
    ofstream f(filename); 
    if (!f.is_open()) {
        cout << "\n>> Khong mo duoc file de ghi!";
        return;
    }

    stu p = list.first;
    while (p != NULL) {
          f << p->id << "|"
            << p->hoTen << "|"
            << p->gioiTinh << "|"
            << p->lop << "\n";
        p = p->next;
    }

    f.close();
    cout << "\n>> Da ghi danh sach vao file: " << filename;
}
void docFileStu(ListStu& list, const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "Khong mo duoc file de doc!\n";
        return;
    }

    while (list.first != NULL) {
        stu p = list.first;
        list.first = list.first->next;
        delete p;
    }
    list.last = NULL;

    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string id, hoTen, gioiTinh, lop;

        getline(ss, id, '|');
        getline(ss, hoTen, '|');
        getline(ss, gioiTinh, '|');
        getline(ss, lop, '|');

        if (id.empty()) continue;

        Student s;
        s.id = id;
        s.hoTen = hoTen;
        s.gioiTinh = stoi(gioiTinh);
        s.lop = lop;

        addStu(list, s);  
    }

    in.close();
    cout << ">> Da tai danh sach sinh vien tu file.\n";
}




void initsub(ListSub& list) {
    list.first = list.last = NULL;
}
int isEmptsub(ListSub list) {
    return (list.first == NULL ? 1 : 0);
}
sub createNodesub(Subject x) {
    sub p = new Subject;
    *p = x;
    p->next = NULL;
    p->pre = NULL;
    return p;
}
void addSub(ListSub& list, Subject x) {
    sub p = createNodesub(x);
    if (isEmptsub(list)) {
        list.first = list.last = p;
    }
    else {
        list.last->next = p;
        p->pre = list.last;
        list.last = p;
    }
}
bool isDuplicatesub(ListSub list, const string& maMH) {
    sub p = list.first;
    while (p != NULL) {
        if (p->maMH == maMH)
            return true;
        p = p->next;
    }
    return false;
}
void nhapmonhoc(ListSub& list) {
    Subject subject;
    cin.ignore();
    do {
        cout << "\nNhap mã mon hoc (0: exit): ";
        getline(cin, subject.maMH);
        while (isDuplicatesub(list, subject.maMH)) {
            cout << "\n>> Mon hoc nay da ton tai!";
            cout << "\n>> Vui long nhap lai MSMH: ";
            getline(cin, subject.maMH);
        }
        if (subject.maMH == "0") //Nhap MSMH = 0 de thoat
            break;
        cout << "\nNhap mon hoc: ";
        getline(cin, subject.tenMH);
        addSub(list, subject);
    } while (1);
}
void xuatmonhoc(ListSub list) {
    if (isEmptsub(list)) {
        cout << "\n>> Danh sach rong!";
        return;
    }
    cout << "\nDANH SACH MON HOC\n";
    cout << left << setw(12) << "MSMH"
        << left << setw(25) << "| Mon Hoc" << endl;

    cout << string(60, '-') << endl;

    for (sub p = list.first; p != NULL; p = p->next) {
        cout << left << setw(12) << p->maMH
            << left << setw(25) << ("| " + p->tenMH) << endl;
    }
}
void updatesub(ListSub& list, const string& maMH) {
    sub p = findsub(list, maMH);
    if (p == NULL) {
        cout << "\n>> Khong tim thay mon hoc can sua!\n";
        return;
    }

    cout << "\nNhap mon hoc moi: ";
    getline(cin, p->tenMH);
    cout << ">> Da cap nhat mon hoc thanh cong!\n";
}
sub findsub(ListSub list, const string& maMH) {
    sub p = list.first;
    while (p != NULL) {
        if (p->maMH == maMH)
            return p;
        p = p->next;
    }
    return NULL;
}
void deletesub(ListSub& list, const string& maMH) {
    sub p = findsub(list, maMH);
    if (p == NULL) {
        cout << "\n>> Khong tim thay mon hoc can xoa!\n";
        return;
    }

    // Neu chi co 1 phan tu
    if (p == list.first && p == list.last) {
        list.first = list.last = NULL;
    }
    // Neu xoa dau
    else if (p == list.first) {
        list.first = p->next;
        list.first->pre = NULL;
    }
    // Neu xoa cuoi
    else if (p == list.last) {
        list.last = p->pre;
        list.last->next = NULL;
    }
    // Neu xoa giua
    else {
        p->pre->next = p->next;
        p->next->pre = p->pre;
    }

    delete p;
    cout << ">> Da xoa mon hoc thanh cong!\n";
}
void ghiFileSub(ListSub list, const string& filename) {
    ofstream f(filename);
    if (!f.is_open()) { cout << "Khong mo duoc file de ghi!\n"; return; }
    for (sub p = list.first; p != nullptr; p = p->next) {
        f << p->maMH << "|" << p->tenMH << "\n";
    }
    f.close();
    cout << ">> Da ghi danh sach mon hoc vao file: " << filename << endl;
}
void docFileSub(ListSub& list, const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "\n>> Khong mo duoc file de doc!";
        return;
    }

    //xoa ds cu
    while (list.first != NULL) {
        sub p = list.first;
        list.first = list.first->next;
        delete p;
    }
    list.last = NULL;

    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string maMH, tenMH;

        getline(ss, maMH, '|');
        getline(ss, tenMH, '|');

        if (maMH.empty()) continue;

        Subject s;
        s.maMH = maMH;
        s.tenMH = tenMH;

        addSub(list, s);
    }

    in.close();
    cout << "\n>> Da tai danh sach mon hoc tu file.\n";
}
