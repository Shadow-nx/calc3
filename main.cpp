/*"Copyright 2017 <Copyright Shadow>"*/
#include <iostream>
#include <locale>

using namespace std;
int pplus(int a, int b) { return a + b; }
int mminus(int a, int b) { return a - b; }
int proiz(int a, int b) { return a * b; }
double chast(double a, double b) { return a / b; }
double pw(double a, double b) {
  if (b > 0) {
    for (int i = 0, j = a; i < b - 1; i++) a *= j;
    return a;
  } else if (b < 0) {
    for (int i = 0, j = a; i < (b + 1) * (-1); i++) a *= j;
    return 1 / a;
  } else
    return 1;
}
int modul(int a, int b) { return (a % b); }
int anbit(int a, int b) { return a & b; }
int btright(int a) { return a >> 1; }
int btleft(int a) { return a << 1; }
int btili(int a, int b) { return a | b; }
int otr(int a) { return !a; }

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "RUS");
  char choice[1][1];
  choice[0][0] = 'y';
  while ((char)choice[0][0] == 'y') {
    int op1, op2;
    char x[1][1];
    do {
      cout << "Выбирите одну из операций[+.-.*,/,%,^,!,&,|,<,>]:" << endl;
      cin >> *x;
    } while (x[0][0] != '+' && x[0][0] != '-' && x[0][0] != '*' &&
             x[0][0] != '/' && x[0][0] != '%' && x[0][0] != '^' &&
             x[0][0] != '!' && x[0][0] != '&' && x[0][0] != '|' &&
             x[0][0] != '<' && x[0][0] != '>');
    if (x[0][0] == '+' || x[0][0] == '-' || x[0][0] == '*' || x[0][0] == '/' ||
        x[0][0] == '%' || x[0][0] == '^' || x[0][0] == '|' || x[0][0] == '&') {
      cout << "Введите первое число:" << endl;
      cin >> op1;
      cout << "Введите второй число:" << endl;
      cin >> op2;
      if (cin.good()) {
        switch ((char)x[0][0]) {
          case '+':
            cout << "Сумма:" << pplus(op1, op2) << endl;
            break;
          case '-':
            cout << "Разность:" << mminus(op1, op2) << endl;
            break;
          case '*':
            cout << "произведение:" << proiz(op1, op2) << endl;
            break;
          case '/':
            if (op2 != 0)
              cout << "частное:" << chast(op1, op2) << endl;
            else
              cerr << "Ошибка:на0 делить нельзя!" << endl;
            break;
          case '%':
            cout << "модуль:" << modul(op1, op2) << endl;
            break;
          case '^':
            cout << "Возведение в степень:" << pw(op1, op2) << endl;
            break;
          case '&':
            cout << "Побитовая И:" << anbit(op1, op2) << endl;
            break;
          case '|':
            cout << "Побитовое ИЛИ:" << btili(op1, op2) << endl;
            break;
          default:
            cerr << "Ошибка" << endl;
        }
      } else {
        cin.ignore();
        cin.clear();
        cout << "Некорректные данные" << endl;
      }
    }
    if (x[0][0] == '!' || x[0][0] == '<' || x[0][0] == '>') {
      cout << "Введите пожалуйста число:" << endl;
      cin >> op1;
      switch ((char)x[0][0]) {
        case '!':
          cout << otr(op1) << endl;
          break;
        case '>':
          cout << btright(op1);
          break;
        case '<':
          cout << btleft(op1);
          break;
        default:
          cerr << "Ошибка" << endl;
      }
    }
    do {
      cout << "Если вы хотите продолжить введите y,если закончить n" << endl;
      cin >> *choice;
    } while ((char)choice[0][0] != 'y' && (char)choice[0][0] != 'n');
  }
  cout << "До свидания!" << endl;
  return 0;
}
