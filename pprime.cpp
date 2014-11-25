/*
ID:willson3
PROG:pprime
LANG:C++
*/

//add test words!
//first line
//second line
//third line
#include <iostream>
#include <fstream>

using namespace std;

bool isprime(int num)
{
    for (int i = 2; i*i <= num; i++) {
        if (num%i == 0) return false;
    }
    return true;
}

int palindrome(int num)
{
    int n = num;
    int t = n / 10;
    while (t != 0) {
        n = n*10 + t % 10;
        t /= 10;
    }
    return n;
}

int main(void)
{
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");
    int a,b;
    fin >> a >> b;
    if (a == 5) fout << 5 << endl;
    if (a <= 7 && b >= 7) fout << 7 << endl;
    if (a <= 11 && b >= 11) fout << 11 << endl;
    int i = 10;
    int tmp,j,k;
    while (palindrome(i) < a) i++;
    k = palindrome(i);
    while (k <= b) {
        tmp = i;
        j = 1;
        while (tmp >= 10) {
            tmp /= 10;
            j *= 10;
        }
        if (tmp % 2 == 0) {i += j;k = palindrome(i); continue;}
        if (isprime(k)) fout << k << endl;
        i++;
        k = palindrome(i);
    }
    fin.close();
    fout.close();
    return 0;
}
