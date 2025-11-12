#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
//student
struct Student {
	string id;
	string hoTen;
	int gioiTinh;
	string lop;
	Student* next;
	Student* pre;
};
typedef Student* stu;
struct ListStu {
	stu first;
	stu last;
};

void initstu(ListStu& list);
int isEmptstu(ListStu list);
stu createNodestu(Student x);
void addStu(ListStu& list, Student x);
bool isDuplicatestu(ListStu list, const string& id);
void nhapsv(ListStu& list);
void xuatsv(ListStu list);
void updatestu(ListStu& list, const string& id);
stu findstu(ListStu list, const string& id);
void deletestu(ListStu& list, const string& id);
void ghiFile(ListStu listStu, const string& filename);
void docFile(ListStu& listStu, const string& filename);

//subject
struct Subject {
	string maMH;
	string tenMH;
	Subject* next;
	Subject* pre;
};
typedef Subject* sub;
struct ListSub {
	sub first;
	sub last;
};

void initsub(ListSub& list);
int isEmptsub(ListSub list);
sub createNodesub(Subject x);
void addSub(ListSub& list, Subject x);
bool isDuplicatesub(ListSub list, const string& maMH);
void nhapmonhoc(ListSub& list);
void xuatmonhoc(ListSub list);
void updatesub(ListSub& list, const string& maMH);
sub findsub(ListSub list, const string& maMH);
void deletesub(ListSub& list, const string& maMH);

//mark
struct Mark {
	string id;
	string maMH;
	float diem;
	Mark* next;
	Mark* pre;
};
typedef Mark* mrk;
struct ListMrk {
	mrk first;
	mrk last;
};