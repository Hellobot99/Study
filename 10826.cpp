#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string bigNumberAdd(string a, string b) {
	int carry = 0;
	string result = "";

	while (!a.empty() || !b.empty() || carry) { //�� ���Ҷ� ����
		if (!a.empty()) {
			carry += a.back() - '0'; //���� �ڸ� ���� ���� ĳ���� ���ϱ�
			a.pop_back();
		}

		if (!b.empty()) {
			carry += b.back() - '0'; //���� �ڸ� ���� ���� ĳ���� ���ϱ�
			b.pop_back();
		}

		result += ((carry % 10) + '0'); //carry �� 10���� ���� �������� ���ϱ� ��� ��
		carry /= 10; // ���� �ø����ν� ���� ���꿡 ������
	}

	reverse(result.begin(), result.end()); //���� �ڸ����� �������� ������� �´� ��
	return result;
}

int main() {
	int n;
	cin >> n;
	vector<string>arr(n+10);
	arr[0] = '0';
	arr[1] = '1';
	arr[2] = '1';
	arr[3] = '2';

	for (int i = 4; i < n + 1; i++) {
		arr[i] = bigNumberAdd(arr[i - 1], arr[i - 2]);
	}	
	
	cout << arr[n];
	return 0;
}