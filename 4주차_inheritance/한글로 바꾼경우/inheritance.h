#pragma once
#include <iostream>
using namespace std;
class ���̽�Ŭ���� {
public:
	���̽�Ŭ����() { }
	void �ۺ�(const char* s = "unknown") {
		cout << "Function �ۺ�() in ���̽�Ŭ���� called from " << s << endl;
		�����();
	}
protected:
	void ��ȣ��(const char* s = "unknown") {
		cout << "Function ��ȣ��() in ���̽�Ŭ���� called from " << s << endl;
	}
private:
	void �����() {
		cout << "Function �����() in ���̽�Ŭ����\n";
	}
};

class �Ļ�1 : public virtual ���̽�Ŭ���� {
	//�������� ����� �θ�� ���𸸵Ǿ��ְ� ��ü�� ������ �ȵǾ��ִ�
public:
	void �ۺ�(const char* s = "unknown") {
		cout << "Function �ۺ�() in �Ļ�1 called from " << s << endl;
		��ȣ��("�Ļ�1");
		�����("�Ļ�1");
	}
	void �����(const char* s = "unknown") {
		cout << "Function �����() in �Ļ�1 called from " << s << endl;
	}
};
class �Ļ�2 : public virtual ���̽�Ŭ���� {
public:
	void �ۺ�(const char* s = "unknown") {
		cout << "Function �ۺ�() in �Ļ�2 called from " << s << endl;
		��ȣ��("�Ļ�2");
		// �����(); // error: ���̽�Ŭ����::�����() is not accessible
	}
};

class �Ļ�2���2 : public �Ļ�1, public �Ļ�2 {
public:
	void �ۺ�(const char* s = "unknown") {
		cout << "Function �ۺ�() in �Ļ�2���2 called from " << s << endl;
		��ȣ��("�Ļ�2���2");
		�Ļ�1::�����("�Ļ�2���2");
		���̽�Ŭ����::�ۺ�("�Ļ�2���2");
	}
};
//inheritance.h
