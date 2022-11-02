#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    string numb;
    cin >> numb;
    int b;
    cin >> b;
    int n;
    cin >> n;
    double des = 0;

    int proof = 0;
    for(char i : numb){
        if (int(i) >= 65 && int(i) <= 90) {
            if (int(i - 55) >= b) {
                proof = 1;
                break;
            }
        }
        else{
            if(int(i - 48) >= b){
                proof = 1;
                break;
            }
        }
    }

    if(proof == 1) cout << "Incorrect number" << endl;

    else {
        int flag = 0;
        int tochka = 0;
        for (int i = 0; i < numb.size(); i++) {
            if (numb[i] == '.' || numb[i] == ',') {
                flag = numb.size() - i;
                tochka = i;
                break;
            }
        }

        for (int i = numb.size() - flag - 1; i >= 0; i--) {
            if (int(numb[i]) >= 65 && int(numb[i]) <= 90) {
                des += (int(numb[i] - 55)) * pow(b, numb.size() - flag - i - 1);
            } else {
                des += (int(numb[i] - 48)) * pow(b, numb.size() - flag - i - 1);
            }
        }
        int count = -1;
        for (int i = tochka + 1; i < numb.size(); i++){
            if (int(numb[i]) >= 65 && int(numb[i]) <= 90) {
                des += (int(numb[i] - 55)) * pow(b, count);
                count -= 1;
            } else {
                des += (int(numb[i] - 48)) * pow(b, count);
                count -= 1;
            }
        }

        int tru = trunc(des);
        double ost = des - tru;
        string res;
        while(tru >= n){
            if(tru % n < 10) {
                res = to_string(tru % n) + res;
                tru /= n;
            }
            else{
                res = char(tru % n + 55) + res;
                tru /= n;
            }
        }
        if(tru < 10) {
            res = to_string(tru) + res;
        }
        else{
            res = char(tru + 55) + res;
        }
        if(flag !=0) {
            double ost2 = ost;
            string res2 = ",";
            while (ost != 0) {
                ost *= n;
                int tru2 = trunc(ost);
                if(tru2 < 10) {
                    res2 += to_string(tru2);
                }
                else{
                    res2 += char(tru2 + 55);
                }
                ost -= tru2;
                if (ost == ost2 || res2.size() > 10) break;
            }
            cout << res + res2;
        }
        else{
            cout << res;
        }
        //std::reverse(res.begin(), res.end()); - строка в обратном порядке
    }
    return 0;
}