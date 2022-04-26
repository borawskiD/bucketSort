#include <iostream>
#include <iomanip>
#include <random>
int x = 1; //dla algorytmu nieistotne, uzywam tej zmiennej do liczenia iteracji i wyswietlania
int getMax(int arr[], int n){
    int mx = arr[0];
    for (int i = 1; i<n;i++){
        if (arr[i] > mx){
            mx = arr[i];
        }
    }
    std::cout<<"Największy element tablicy: " << mx<<"\n";
    return mx;
}
void print(int arr[], int n){
    for (int i = 0; i<n; i++){
        std::cout<<arr[i] << " ";
    }
    std::cout << std::endl;
}
void countSort(int arr[], int n, int exp){
    std::cout<<"\n---\n";
    std::cout<<"Analizuje "<<exp<<" rzad liczb [od konca] \n";
    int output[n];
    int count[10] = { 0 };
    for (int i = 0; i < n; i++){
        count[(arr[i] / exp) % 10]++;
    }
    std::cout<<"Liczę ilość wystąpień poszczególnych cyfr [cyfra - ilosc wystapien]: ";
    for (int i = 0; i<10; i++){
        std::cout <<"[" << i+1 << " - " << count[i] <<"] ";
    }
    std::cout<<"\nZsumowana tablica wystąpień (żeby zachować kolejność, kazdy element to suma poprzednikow): ";
    for(int i = 1; i < 10; i++){
        count[i] += count[i-1];
    }
    print(count,10);
    for(int i = n-1; i >= 0; i--){
        std::cout<<"\n";
        std::cout<<"Przeszukujemy: "<<(arr[i] / exp) % 10<<" rzad wielkosci \n";
        std::cout<<"Pod indeksem tego rzedu wielkosci znajduje sie: "<<count[(arr[i] / exp) % 10]<<"\n";
        std::cout<<"Przepisuje wartosc: " << arr[i] << " dla elementu o w/w indeksie \n";
        std::cout<<"output["<<count[(arr[i] / exp) % 10] - 1<<"] = " << arr[i] <<"\n";
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        std::cout<<"Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count["<<(arr[i] / exp) % 10<<"] z "<<count[(arr[i] / exp) % 10]<<" na " <<count[(arr[i] / exp) % 10]-1<<"\n";
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i<n; i++){
        arr[i] = output[i];
    }
}
void radixsort(int arr[], int n){
    int max = getMax(arr,n);

    for (int i = 1; max/i > 0; i*=10){
        x++;
        countSort(arr,n,i);
        std::cout<<"Wyglad tablicy po posortowaniu "<< x <<" rzedu(ow) od konca:\n";
        print(arr,n);
    }
}
int main() {
    int n = 100;
    int arr[n];

    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1,110);
    for(int i = 0; i <= n; i++){
        arr[i] = uniform_dist(e1);
    }
    std::cout <<"Nieposortowana tablica: \n";
    print(arr,n);
    radixsort(arr,n);
    std::cout<<"\nPosortowana tablica: \n";
    print(arr,n);
    return 0;
}

/* Dominik Borawski A1 215IC
 * Sortowanie kubełkowe */

/*
Nieposortowana tablica:
34 87 10 41 81 54 48 22 19 6 69 93 64 18 44 35 49 38 35 18 46 28 53 75 27 84 70 92 110 95 15 33 35 38 17 36 94 52 93 69 107 80 74 26 62 88 93 1 61 87 80 75 92 105 80 50 13 6 80 85 8 75 66 68 57 36 13 39 12 15 72 17 70 40 61 62 35 41 104 59 68 86 28 110 25 102 110 40 65 26 47 51 75 46 22 61 76 90 11 32
Największy element tablicy: 110

---
Analizuje 1 rzad liczb [od konca]
Liczę ilość wystąpień poszczególnych cyfr [cyfra - ilosc wystapien]: [1 - 14] [2 - 9] [3 - 11] [4 - 7] [5 - 8] [6 - 15] [7 - 11] [8 - 8] [9 - 11] [10 - 6]
Zsumowana tablica wystąpień (żeby zachować kolejność, kazdy element to suma poprzednikow): 14 23 34 41 49 64 75 83 94 100

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 34
Przepisuje wartosc: 32 dla elementu o w/w indeksie
output[33] = 32
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 34 na 33

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 23
Przepisuje wartosc: 11 dla elementu o w/w indeksie
output[22] = 11
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 23 na 22

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 14
Przepisuje wartosc: 90 dla elementu o w/w indeksie
output[13] = 90
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 14 na 13

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 75
Przepisuje wartosc: 76 dla elementu o w/w indeksie
output[74] = 76
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 75 na 74

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 22
Przepisuje wartosc: 61 dla elementu o w/w indeksie
output[21] = 61
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 22 na 21

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 33
Przepisuje wartosc: 22 dla elementu o w/w indeksie
output[32] = 22
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 33 na 32

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 74
Przepisuje wartosc: 46 dla elementu o w/w indeksie
output[73] = 46
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 74 na 73

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 64
Przepisuje wartosc: 75 dla elementu o w/w indeksie
output[63] = 75
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 64 na 63

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 21
Przepisuje wartosc: 51 dla elementu o w/w indeksie
output[20] = 51
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 21 na 20

Przeszukujemy: 7 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 83
Przepisuje wartosc: 47 dla elementu o w/w indeksie
output[82] = 47
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[7] z 83 na 82

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 73
Przepisuje wartosc: 26 dla elementu o w/w indeksie
output[72] = 26
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 73 na 72

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 63
Przepisuje wartosc: 65 dla elementu o w/w indeksie
output[62] = 65
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 63 na 62

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 13
Przepisuje wartosc: 40 dla elementu o w/w indeksie
output[12] = 40
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 13 na 12

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 12
Przepisuje wartosc: 110 dla elementu o w/w indeksie
output[11] = 110
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 12 na 11

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 32
Przepisuje wartosc: 102 dla elementu o w/w indeksie
output[31] = 102
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 32 na 31

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 62
Przepisuje wartosc: 25 dla elementu o w/w indeksie
output[61] = 25
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 62 na 61

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 11
Przepisuje wartosc: 110 dla elementu o w/w indeksie
output[10] = 110
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 11 na 10

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 94
Przepisuje wartosc: 28 dla elementu o w/w indeksie
output[93] = 28
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 94 na 93

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 72
Przepisuje wartosc: 86 dla elementu o w/w indeksie
output[71] = 86
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 72 na 71

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 93
Przepisuje wartosc: 68 dla elementu o w/w indeksie
output[92] = 68
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 93 na 92

Przeszukujemy: 9 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 100
Przepisuje wartosc: 59 dla elementu o w/w indeksie
output[99] = 59
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[9] z 100 na 99

Przeszukujemy: 4 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 49
Przepisuje wartosc: 104 dla elementu o w/w indeksie
output[48] = 104
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[4] z 49 na 48

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 20
Przepisuje wartosc: 41 dla elementu o w/w indeksie
output[19] = 41
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 20 na 19

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 61
Przepisuje wartosc: 35 dla elementu o w/w indeksie
output[60] = 35
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 61 na 60

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 31
Przepisuje wartosc: 62 dla elementu o w/w indeksie
output[30] = 62
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 31 na 30

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 19
Przepisuje wartosc: 61 dla elementu o w/w indeksie
output[18] = 61
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 19 na 18

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 10
Przepisuje wartosc: 40 dla elementu o w/w indeksie
output[9] = 40
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 10 na 9

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 9
Przepisuje wartosc: 70 dla elementu o w/w indeksie
output[8] = 70
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 9 na 8

Przeszukujemy: 7 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 82
Przepisuje wartosc: 17 dla elementu o w/w indeksie
output[81] = 17
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[7] z 82 na 81

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 30
Przepisuje wartosc: 72 dla elementu o w/w indeksie
output[29] = 72
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 30 na 29

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 60
Przepisuje wartosc: 15 dla elementu o w/w indeksie
output[59] = 15
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 60 na 59

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 29
Przepisuje wartosc: 12 dla elementu o w/w indeksie
output[28] = 12
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 29 na 28

Przeszukujemy: 9 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 99
Przepisuje wartosc: 39 dla elementu o w/w indeksie
output[98] = 39
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[9] z 99 na 98

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 41
Przepisuje wartosc: 13 dla elementu o w/w indeksie
output[40] = 13
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 41 na 40

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 71
Przepisuje wartosc: 36 dla elementu o w/w indeksie
output[70] = 36
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 71 na 70

Przeszukujemy: 7 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 81
Przepisuje wartosc: 57 dla elementu o w/w indeksie
output[80] = 57
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[7] z 81 na 80

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 92
Przepisuje wartosc: 68 dla elementu o w/w indeksie
output[91] = 68
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 92 na 91

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 70
Przepisuje wartosc: 66 dla elementu o w/w indeksie
output[69] = 66
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 70 na 69

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 59
Przepisuje wartosc: 75 dla elementu o w/w indeksie
output[58] = 75
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 59 na 58

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 91
Przepisuje wartosc: 8 dla elementu o w/w indeksie
output[90] = 8
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 91 na 90

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 58
Przepisuje wartosc: 85 dla elementu o w/w indeksie
output[57] = 85
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 58 na 57

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 8
Przepisuje wartosc: 80 dla elementu o w/w indeksie
output[7] = 80
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 8 na 7

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 69
Przepisuje wartosc: 6 dla elementu o w/w indeksie
output[68] = 6
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 69 na 68

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 40
Przepisuje wartosc: 13 dla elementu o w/w indeksie
output[39] = 13
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 40 na 39

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 7
Przepisuje wartosc: 50 dla elementu o w/w indeksie
output[6] = 50
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 7 na 6

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 6
Przepisuje wartosc: 80 dla elementu o w/w indeksie
output[5] = 80
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 6 na 5

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 57
Przepisuje wartosc: 105 dla elementu o w/w indeksie
output[56] = 105
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 57 na 56

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 28
Przepisuje wartosc: 92 dla elementu o w/w indeksie
output[27] = 92
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 28 na 27

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 56
Przepisuje wartosc: 75 dla elementu o w/w indeksie
output[55] = 75
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 56 na 55

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 5
Przepisuje wartosc: 80 dla elementu o w/w indeksie
output[4] = 80
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 5 na 4

Przeszukujemy: 7 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 80
Przepisuje wartosc: 87 dla elementu o w/w indeksie
output[79] = 87
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[7] z 80 na 79

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 18
Przepisuje wartosc: 61 dla elementu o w/w indeksie
output[17] = 61
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 18 na 17

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 17
Przepisuje wartosc: 1 dla elementu o w/w indeksie
output[16] = 1
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 17 na 16

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 39
Przepisuje wartosc: 93 dla elementu o w/w indeksie
output[38] = 93
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 39 na 38

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 90
Przepisuje wartosc: 88 dla elementu o w/w indeksie
output[89] = 88
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 90 na 89

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 27
Przepisuje wartosc: 62 dla elementu o w/w indeksie
output[26] = 62
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 27 na 26

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 68
Przepisuje wartosc: 26 dla elementu o w/w indeksie
output[67] = 26
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 68 na 67

Przeszukujemy: 4 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 48
Przepisuje wartosc: 74 dla elementu o w/w indeksie
output[47] = 74
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[4] z 48 na 47

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 4
Przepisuje wartosc: 80 dla elementu o w/w indeksie
output[3] = 80
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 4 na 3

Przeszukujemy: 7 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 79
Przepisuje wartosc: 107 dla elementu o w/w indeksie
output[78] = 107
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[7] z 79 na 78

Przeszukujemy: 9 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 98
Przepisuje wartosc: 69 dla elementu o w/w indeksie
output[97] = 69
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[9] z 98 na 97

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 38
Przepisuje wartosc: 93 dla elementu o w/w indeksie
output[37] = 93
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 38 na 37

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 26
Przepisuje wartosc: 52 dla elementu o w/w indeksie
output[25] = 52
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 26 na 25

Przeszukujemy: 4 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 47
Przepisuje wartosc: 94 dla elementu o w/w indeksie
output[46] = 94
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[4] z 47 na 46

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 67
Przepisuje wartosc: 36 dla elementu o w/w indeksie
output[66] = 36
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 67 na 66

Przeszukujemy: 7 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 78
Przepisuje wartosc: 17 dla elementu o w/w indeksie
output[77] = 17
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[7] z 78 na 77

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 89
Przepisuje wartosc: 38 dla elementu o w/w indeksie
output[88] = 38
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 89 na 88

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 55
Przepisuje wartosc: 35 dla elementu o w/w indeksie
output[54] = 35
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 55 na 54

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 37
Przepisuje wartosc: 33 dla elementu o w/w indeksie
output[36] = 33
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 37 na 36

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 54
Przepisuje wartosc: 15 dla elementu o w/w indeksie
output[53] = 15
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 54 na 53

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 53
Przepisuje wartosc: 95 dla elementu o w/w indeksie
output[52] = 95
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 53 na 52

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 3
Przepisuje wartosc: 110 dla elementu o w/w indeksie
output[2] = 110
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 3 na 2

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 25
Przepisuje wartosc: 92 dla elementu o w/w indeksie
output[24] = 92
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 25 na 24

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 2
Przepisuje wartosc: 70 dla elementu o w/w indeksie
output[1] = 70
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 2 na 1

Przeszukujemy: 4 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 46
Przepisuje wartosc: 84 dla elementu o w/w indeksie
output[45] = 84
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[4] z 46 na 45

Przeszukujemy: 7 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 77
Przepisuje wartosc: 27 dla elementu o w/w indeksie
output[76] = 27
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[7] z 77 na 76

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 52
Przepisuje wartosc: 75 dla elementu o w/w indeksie
output[51] = 75
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 52 na 51

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 36
Przepisuje wartosc: 53 dla elementu o w/w indeksie
output[35] = 53
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 36 na 35

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 88
Przepisuje wartosc: 28 dla elementu o w/w indeksie
output[87] = 28
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 88 na 87

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 66
Przepisuje wartosc: 46 dla elementu o w/w indeksie
output[65] = 46
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 66 na 65

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 87
Przepisuje wartosc: 18 dla elementu o w/w indeksie
output[86] = 18
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 87 na 86

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 51
Przepisuje wartosc: 35 dla elementu o w/w indeksie
output[50] = 35
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 51 na 50

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 86
Przepisuje wartosc: 38 dla elementu o w/w indeksie
output[85] = 38
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 86 na 85

Przeszukujemy: 9 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 97
Przepisuje wartosc: 49 dla elementu o w/w indeksie
output[96] = 49
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[9] z 97 na 96

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 50
Przepisuje wartosc: 35 dla elementu o w/w indeksie
output[49] = 35
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 50 na 49

Przeszukujemy: 4 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 45
Przepisuje wartosc: 44 dla elementu o w/w indeksie
output[44] = 44
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[4] z 45 na 44

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 85
Przepisuje wartosc: 18 dla elementu o w/w indeksie
output[84] = 18
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 85 na 84

Przeszukujemy: 4 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 44
Przepisuje wartosc: 64 dla elementu o w/w indeksie
output[43] = 64
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[4] z 44 na 43

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 35
Przepisuje wartosc: 93 dla elementu o w/w indeksie
output[34] = 93
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 35 na 34

Przeszukujemy: 9 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 96
Przepisuje wartosc: 69 dla elementu o w/w indeksie
output[95] = 69
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[9] z 96 na 95

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 65
Przepisuje wartosc: 6 dla elementu o w/w indeksie
output[64] = 6
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 65 na 64

Przeszukujemy: 9 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 95
Przepisuje wartosc: 19 dla elementu o w/w indeksie
output[94] = 19
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[9] z 95 na 94

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 24
Przepisuje wartosc: 22 dla elementu o w/w indeksie
output[23] = 22
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 24 na 23

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 84
Przepisuje wartosc: 48 dla elementu o w/w indeksie
output[83] = 48
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 84 na 83

Przeszukujemy: 4 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 43
Przepisuje wartosc: 54 dla elementu o w/w indeksie
output[42] = 54
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[4] z 43 na 42

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 16
Przepisuje wartosc: 81 dla elementu o w/w indeksie
output[15] = 81
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 16 na 15

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 15
Przepisuje wartosc: 41 dla elementu o w/w indeksie
output[14] = 41
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 15 na 14

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 1
Przepisuje wartosc: 10 dla elementu o w/w indeksie
output[0] = 10
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 1 na 0

Przeszukujemy: 7 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 76
Przepisuje wartosc: 87 dla elementu o w/w indeksie
output[75] = 87
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[7] z 76 na 75

Przeszukujemy: 4 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 42
Przepisuje wartosc: 34 dla elementu o w/w indeksie
output[41] = 34
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[4] z 42 na 41
Wyglad tablicy po posortowaniu 2 rzedu(ow) od konca:
10 70 110 80 80 80 50 80 70 40 110 110 40 90 41 81 1 61 61 41 51 61 11 22 92 52 62 92 12 72 62 102 22 32 93 53 33 93 93 13 13 34 54 64 44 84 94 74 104 35 35 75 95 15 35 75 105 85 75 15 35 25 65 75 6 46 36 26 6 66 36 86 26 46 76 87 27 17 107 87 57 17 47 48 18 38 18 28 38 88 8 68 68 28 19 69 49 69 39 59

---
Analizuje 10 rzad liczb [od konca]
Liczę ilość wystąpień poszczególnych cyfr [cyfra - ilosc wystapien]: [1 - 8] [2 - 15] [3 - 8] [4 - 12] [5 - 10] [6 - 7] [7 - 12] [8 - 9] [9 - 11] [10 - 8]
Zsumowana tablica wystąpień (żeby zachować kolejność, kazdy element to suma poprzednikow): 8 23 31 43 53 60 72 81 92 100

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 60
Przepisuje wartosc: 59 dla elementu o w/w indeksie
output[59] = 59
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 60 na 59

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 43
Przepisuje wartosc: 39 dla elementu o w/w indeksie
output[42] = 39
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 43 na 42

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 72
Przepisuje wartosc: 69 dla elementu o w/w indeksie
output[71] = 69
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 72 na 71

Przeszukujemy: 4 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 53
Przepisuje wartosc: 49 dla elementu o w/w indeksie
output[52] = 49
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[4] z 53 na 52

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 71
Przepisuje wartosc: 69 dla elementu o w/w indeksie
output[70] = 69
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 71 na 70

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 23
Przepisuje wartosc: 19 dla elementu o w/w indeksie
output[22] = 19
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 23 na 22

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 31
Przepisuje wartosc: 28 dla elementu o w/w indeksie
output[30] = 28
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 31 na 30

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 70
Przepisuje wartosc: 68 dla elementu o w/w indeksie
output[69] = 68
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 70 na 69

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 69
Przepisuje wartosc: 68 dla elementu o w/w indeksie
output[68] = 68
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 69 na 68

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 8
Przepisuje wartosc: 8 dla elementu o w/w indeksie
output[7] = 8
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 8 na 7

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 92
Przepisuje wartosc: 88 dla elementu o w/w indeksie
output[91] = 88
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 92 na 91

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 42
Przepisuje wartosc: 38 dla elementu o w/w indeksie
output[41] = 38
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 42 na 41

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 30
Przepisuje wartosc: 28 dla elementu o w/w indeksie
output[29] = 28
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 30 na 29

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 22
Przepisuje wartosc: 18 dla elementu o w/w indeksie
output[21] = 18
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 22 na 21

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 41
Przepisuje wartosc: 38 dla elementu o w/w indeksie
output[40] = 38
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 41 na 40

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 21
Przepisuje wartosc: 18 dla elementu o w/w indeksie
output[20] = 18
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 21 na 20

Przeszukujemy: 4 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 52
Przepisuje wartosc: 48 dla elementu o w/w indeksie
output[51] = 48
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[4] z 52 na 51

Przeszukujemy: 4 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 51
Przepisuje wartosc: 47 dla elementu o w/w indeksie
output[50] = 47
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[4] z 51 na 50

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 20
Przepisuje wartosc: 17 dla elementu o w/w indeksie
output[19] = 17
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 20 na 19

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 59
Przepisuje wartosc: 57 dla elementu o w/w indeksie
output[58] = 57
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 59 na 58

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 91
Przepisuje wartosc: 87 dla elementu o w/w indeksie
output[90] = 87
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 91 na 90

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 7
Przepisuje wartosc: 107 dla elementu o w/w indeksie
output[6] = 107
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 7 na 6

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 19
Przepisuje wartosc: 17 dla elementu o w/w indeksie
output[18] = 17
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 19 na 18

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 29
Przepisuje wartosc: 27 dla elementu o w/w indeksie
output[28] = 27
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 29 na 28

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 90
Przepisuje wartosc: 87 dla elementu o w/w indeksie
output[89] = 87
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 90 na 89

Przeszukujemy: 7 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 81
Przepisuje wartosc: 76 dla elementu o w/w indeksie
output[80] = 76
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[7] z 81 na 80

Przeszukujemy: 4 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 50
Przepisuje wartosc: 46 dla elementu o w/w indeksie
output[49] = 46
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[4] z 50 na 49

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 28
Przepisuje wartosc: 26 dla elementu o w/w indeksie
output[27] = 26
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 28 na 27

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 89
Przepisuje wartosc: 86 dla elementu o w/w indeksie
output[88] = 86
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 89 na 88

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 40
Przepisuje wartosc: 36 dla elementu o w/w indeksie
output[39] = 36
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 40 na 39

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 68
Przepisuje wartosc: 66 dla elementu o w/w indeksie
output[67] = 66
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 68 na 67

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 6
Przepisuje wartosc: 6 dla elementu o w/w indeksie
output[5] = 6
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 6 na 5

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 27
Przepisuje wartosc: 26 dla elementu o w/w indeksie
output[26] = 26
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 27 na 26

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 39
Przepisuje wartosc: 36 dla elementu o w/w indeksie
output[38] = 36
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 39 na 38

Przeszukujemy: 4 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 49
Przepisuje wartosc: 46 dla elementu o w/w indeksie
output[48] = 46
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[4] z 49 na 48

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 5
Przepisuje wartosc: 6 dla elementu o w/w indeksie
output[4] = 6
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 5 na 4

Przeszukujemy: 7 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 80
Przepisuje wartosc: 75 dla elementu o w/w indeksie
output[79] = 75
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[7] z 80 na 79

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 67
Przepisuje wartosc: 65 dla elementu o w/w indeksie
output[66] = 65
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 67 na 66

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 26
Przepisuje wartosc: 25 dla elementu o w/w indeksie
output[25] = 25
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 26 na 25

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 38
Przepisuje wartosc: 35 dla elementu o w/w indeksie
output[37] = 35
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 38 na 37

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 18
Przepisuje wartosc: 15 dla elementu o w/w indeksie
output[17] = 15
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 18 na 17

Przeszukujemy: 7 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 79
Przepisuje wartosc: 75 dla elementu o w/w indeksie
output[78] = 75
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[7] z 79 na 78

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 88
Przepisuje wartosc: 85 dla elementu o w/w indeksie
output[87] = 85
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 88 na 87

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 4
Przepisuje wartosc: 105 dla elementu o w/w indeksie
output[3] = 105
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 4 na 3

Przeszukujemy: 7 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 78
Przepisuje wartosc: 75 dla elementu o w/w indeksie
output[77] = 75
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[7] z 78 na 77

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 37
Przepisuje wartosc: 35 dla elementu o w/w indeksie
output[36] = 35
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 37 na 36

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 17
Przepisuje wartosc: 15 dla elementu o w/w indeksie
output[16] = 15
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 17 na 16

Przeszukujemy: 9 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 100
Przepisuje wartosc: 95 dla elementu o w/w indeksie
output[99] = 95
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[9] z 100 na 99

Przeszukujemy: 7 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 77
Przepisuje wartosc: 75 dla elementu o w/w indeksie
output[76] = 75
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[7] z 77 na 76

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 36
Przepisuje wartosc: 35 dla elementu o w/w indeksie
output[35] = 35
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 36 na 35

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 35
Przepisuje wartosc: 35 dla elementu o w/w indeksie
output[34] = 35
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 35 na 34

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 3
Przepisuje wartosc: 104 dla elementu o w/w indeksie
output[2] = 104
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 3 na 2

Przeszukujemy: 7 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 76
Przepisuje wartosc: 74 dla elementu o w/w indeksie
output[75] = 74
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[7] z 76 na 75

Przeszukujemy: 9 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 99
Przepisuje wartosc: 94 dla elementu o w/w indeksie
output[98] = 94
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[9] z 99 na 98

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 87
Przepisuje wartosc: 84 dla elementu o w/w indeksie
output[86] = 84
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 87 na 86

Przeszukujemy: 4 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 48
Przepisuje wartosc: 44 dla elementu o w/w indeksie
output[47] = 44
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[4] z 48 na 47

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 66
Przepisuje wartosc: 64 dla elementu o w/w indeksie
output[65] = 64
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 66 na 65

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 58
Przepisuje wartosc: 54 dla elementu o w/w indeksie
output[57] = 54
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 58 na 57

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 34
Przepisuje wartosc: 34 dla elementu o w/w indeksie
output[33] = 34
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 34 na 33

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 16
Przepisuje wartosc: 13 dla elementu o w/w indeksie
output[15] = 13
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 16 na 15

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 15
Przepisuje wartosc: 13 dla elementu o w/w indeksie
output[14] = 13
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 15 na 14

Przeszukujemy: 9 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 98
Przepisuje wartosc: 93 dla elementu o w/w indeksie
output[97] = 93
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[9] z 98 na 97

Przeszukujemy: 9 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 97
Przepisuje wartosc: 93 dla elementu o w/w indeksie
output[96] = 93
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[9] z 97 na 96

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 33
Przepisuje wartosc: 33 dla elementu o w/w indeksie
output[32] = 33
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 33 na 32

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 57
Przepisuje wartosc: 53 dla elementu o w/w indeksie
output[56] = 53
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 57 na 56

Przeszukujemy: 9 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 96
Przepisuje wartosc: 93 dla elementu o w/w indeksie
output[95] = 93
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[9] z 96 na 95

Przeszukujemy: 3 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 32
Przepisuje wartosc: 32 dla elementu o w/w indeksie
output[31] = 32
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[3] z 32 na 31

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 25
Przepisuje wartosc: 22 dla elementu o w/w indeksie
output[24] = 22
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 25 na 24

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 2
Przepisuje wartosc: 102 dla elementu o w/w indeksie
output[1] = 102
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 2 na 1

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 65
Przepisuje wartosc: 62 dla elementu o w/w indeksie
output[64] = 62
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 65 na 64

Przeszukujemy: 7 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 75
Przepisuje wartosc: 72 dla elementu o w/w indeksie
output[74] = 72
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[7] z 75 na 74

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 14
Przepisuje wartosc: 12 dla elementu o w/w indeksie
output[13] = 12
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 14 na 13

Przeszukujemy: 9 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 95
Przepisuje wartosc: 92 dla elementu o w/w indeksie
output[94] = 92
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[9] z 95 na 94

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 64
Przepisuje wartosc: 62 dla elementu o w/w indeksie
output[63] = 62
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 64 na 63

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 56
Przepisuje wartosc: 52 dla elementu o w/w indeksie
output[55] = 52
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 56 na 55

Przeszukujemy: 9 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 94
Przepisuje wartosc: 92 dla elementu o w/w indeksie
output[93] = 92
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[9] z 94 na 93

Przeszukujemy: 2 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 24
Przepisuje wartosc: 22 dla elementu o w/w indeksie
output[23] = 22
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[2] z 24 na 23

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 13
Przepisuje wartosc: 11 dla elementu o w/w indeksie
output[12] = 11
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 13 na 12

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 63
Przepisuje wartosc: 61 dla elementu o w/w indeksie
output[62] = 61
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 63 na 62

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 55
Przepisuje wartosc: 51 dla elementu o w/w indeksie
output[54] = 51
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 55 na 54

Przeszukujemy: 4 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 47
Przepisuje wartosc: 41 dla elementu o w/w indeksie
output[46] = 41
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[4] z 47 na 46

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 62
Przepisuje wartosc: 61 dla elementu o w/w indeksie
output[61] = 61
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 62 na 61

Przeszukujemy: 6 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 61
Przepisuje wartosc: 61 dla elementu o w/w indeksie
output[60] = 61
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[6] z 61 na 60

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 1
Przepisuje wartosc: 1 dla elementu o w/w indeksie
output[0] = 1
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 1 na 0

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 86
Przepisuje wartosc: 81 dla elementu o w/w indeksie
output[85] = 81
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 86 na 85

Przeszukujemy: 4 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 46
Przepisuje wartosc: 41 dla elementu o w/w indeksie
output[45] = 41
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[4] z 46 na 45

Przeszukujemy: 9 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 93
Przepisuje wartosc: 90 dla elementu o w/w indeksie
output[92] = 90
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[9] z 93 na 92

Przeszukujemy: 4 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 45
Przepisuje wartosc: 40 dla elementu o w/w indeksie
output[44] = 40
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[4] z 45 na 44

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 12
Przepisuje wartosc: 110 dla elementu o w/w indeksie
output[11] = 110
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 12 na 11

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 11
Przepisuje wartosc: 110 dla elementu o w/w indeksie
output[10] = 110
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 11 na 10

Przeszukujemy: 4 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 44
Przepisuje wartosc: 40 dla elementu o w/w indeksie
output[43] = 40
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[4] z 44 na 43

Przeszukujemy: 7 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 74
Przepisuje wartosc: 70 dla elementu o w/w indeksie
output[73] = 70
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[7] z 74 na 73

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 85
Przepisuje wartosc: 80 dla elementu o w/w indeksie
output[84] = 80
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 85 na 84

Przeszukujemy: 5 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 54
Przepisuje wartosc: 50 dla elementu o w/w indeksie
output[53] = 50
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[5] z 54 na 53

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 84
Przepisuje wartosc: 80 dla elementu o w/w indeksie
output[83] = 80
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 84 na 83

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 83
Przepisuje wartosc: 80 dla elementu o w/w indeksie
output[82] = 80
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 83 na 82

Przeszukujemy: 8 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 82
Przepisuje wartosc: 80 dla elementu o w/w indeksie
output[81] = 80
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[8] z 82 na 81

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 10
Przepisuje wartosc: 110 dla elementu o w/w indeksie
output[9] = 110
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 10 na 9

Przeszukujemy: 7 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 73
Przepisuje wartosc: 70 dla elementu o w/w indeksie
output[72] = 70
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[7] z 73 na 72

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 9
Przepisuje wartosc: 10 dla elementu o w/w indeksie
output[8] = 10
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 9 na 8
Wyglad tablicy po posortowaniu 3 rzedu(ow) od konca:
1 102 104 105 6 6 107 8 10 110 110 110 11 12 13 13 15 15 17 17 18 18 19 22 22 25 26 26 27 28 28 32 33 34 35 35 35 35 36 36 38 38 39 40 40 41 41 44 46 46 47 48 49 50 51 52 53 54 57 59 61 61 61 62 62 64 65 66 68 68 69 69 70 70 72 74 75 75 75 75 76 80 80 80 80 81 84 85 86 87 87 88 90 92 92 93 93 93 94 95

---
Analizuje 100 rzad liczb [od konca]
Liczę ilość wystąpień poszczególnych cyfr [cyfra - ilosc wystapien]: [1 - 93] [2 - 7] [3 - 0] [4 - 0] [5 - 0] [6 - 0] [7 - 0] [8 - 0] [9 - 0] [10 - 0]
Zsumowana tablica wystąpień (żeby zachować kolejność, kazdy element to suma poprzednikow): 93 100 100 100 100 100 100 100 100 100

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 93
Przepisuje wartosc: 95 dla elementu o w/w indeksie
output[92] = 95
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 93 na 92

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 92
Przepisuje wartosc: 94 dla elementu o w/w indeksie
output[91] = 94
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 92 na 91

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 91
Przepisuje wartosc: 93 dla elementu o w/w indeksie
output[90] = 93
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 91 na 90

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 90
Przepisuje wartosc: 93 dla elementu o w/w indeksie
output[89] = 93
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 90 na 89

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 89
Przepisuje wartosc: 93 dla elementu o w/w indeksie
output[88] = 93
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 89 na 88

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 88
Przepisuje wartosc: 92 dla elementu o w/w indeksie
output[87] = 92
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 88 na 87

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 87
Przepisuje wartosc: 92 dla elementu o w/w indeksie
output[86] = 92
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 87 na 86

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 86
Przepisuje wartosc: 90 dla elementu o w/w indeksie
output[85] = 90
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 86 na 85

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 85
Przepisuje wartosc: 88 dla elementu o w/w indeksie
output[84] = 88
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 85 na 84

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 84
Przepisuje wartosc: 87 dla elementu o w/w indeksie
output[83] = 87
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 84 na 83

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 83
Przepisuje wartosc: 87 dla elementu o w/w indeksie
output[82] = 87
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 83 na 82

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 82
Przepisuje wartosc: 86 dla elementu o w/w indeksie
output[81] = 86
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 82 na 81

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 81
Przepisuje wartosc: 85 dla elementu o w/w indeksie
output[80] = 85
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 81 na 80

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 80
Przepisuje wartosc: 84 dla elementu o w/w indeksie
output[79] = 84
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 80 na 79

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 79
Przepisuje wartosc: 81 dla elementu o w/w indeksie
output[78] = 81
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 79 na 78

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 78
Przepisuje wartosc: 80 dla elementu o w/w indeksie
output[77] = 80
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 78 na 77

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 77
Przepisuje wartosc: 80 dla elementu o w/w indeksie
output[76] = 80
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 77 na 76

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 76
Przepisuje wartosc: 80 dla elementu o w/w indeksie
output[75] = 80
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 76 na 75

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 75
Przepisuje wartosc: 80 dla elementu o w/w indeksie
output[74] = 80
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 75 na 74

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 74
Przepisuje wartosc: 76 dla elementu o w/w indeksie
output[73] = 76
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 74 na 73

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 73
Przepisuje wartosc: 75 dla elementu o w/w indeksie
output[72] = 75
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 73 na 72

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 72
Przepisuje wartosc: 75 dla elementu o w/w indeksie
output[71] = 75
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 72 na 71

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 71
Przepisuje wartosc: 75 dla elementu o w/w indeksie
output[70] = 75
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 71 na 70

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 70
Przepisuje wartosc: 75 dla elementu o w/w indeksie
output[69] = 75
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 70 na 69

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 69
Przepisuje wartosc: 74 dla elementu o w/w indeksie
output[68] = 74
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 69 na 68

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 68
Przepisuje wartosc: 72 dla elementu o w/w indeksie
output[67] = 72
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 68 na 67

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 67
Przepisuje wartosc: 70 dla elementu o w/w indeksie
output[66] = 70
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 67 na 66

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 66
Przepisuje wartosc: 70 dla elementu o w/w indeksie
output[65] = 70
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 66 na 65

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 65
Przepisuje wartosc: 69 dla elementu o w/w indeksie
output[64] = 69
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 65 na 64

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 64
Przepisuje wartosc: 69 dla elementu o w/w indeksie
output[63] = 69
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 64 na 63

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 63
Przepisuje wartosc: 68 dla elementu o w/w indeksie
output[62] = 68
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 63 na 62

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 62
Przepisuje wartosc: 68 dla elementu o w/w indeksie
output[61] = 68
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 62 na 61

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 61
Przepisuje wartosc: 66 dla elementu o w/w indeksie
output[60] = 66
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 61 na 60

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 60
Przepisuje wartosc: 65 dla elementu o w/w indeksie
output[59] = 65
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 60 na 59

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 59
Przepisuje wartosc: 64 dla elementu o w/w indeksie
output[58] = 64
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 59 na 58

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 58
Przepisuje wartosc: 62 dla elementu o w/w indeksie
output[57] = 62
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 58 na 57

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 57
Przepisuje wartosc: 62 dla elementu o w/w indeksie
output[56] = 62
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 57 na 56

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 56
Przepisuje wartosc: 61 dla elementu o w/w indeksie
output[55] = 61
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 56 na 55

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 55
Przepisuje wartosc: 61 dla elementu o w/w indeksie
output[54] = 61
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 55 na 54

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 54
Przepisuje wartosc: 61 dla elementu o w/w indeksie
output[53] = 61
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 54 na 53

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 53
Przepisuje wartosc: 59 dla elementu o w/w indeksie
output[52] = 59
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 53 na 52

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 52
Przepisuje wartosc: 57 dla elementu o w/w indeksie
output[51] = 57
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 52 na 51

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 51
Przepisuje wartosc: 54 dla elementu o w/w indeksie
output[50] = 54
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 51 na 50

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 50
Przepisuje wartosc: 53 dla elementu o w/w indeksie
output[49] = 53
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 50 na 49

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 49
Przepisuje wartosc: 52 dla elementu o w/w indeksie
output[48] = 52
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 49 na 48

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 48
Przepisuje wartosc: 51 dla elementu o w/w indeksie
output[47] = 51
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 48 na 47

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 47
Przepisuje wartosc: 50 dla elementu o w/w indeksie
output[46] = 50
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 47 na 46

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 46
Przepisuje wartosc: 49 dla elementu o w/w indeksie
output[45] = 49
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 46 na 45

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 45
Przepisuje wartosc: 48 dla elementu o w/w indeksie
output[44] = 48
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 45 na 44

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 44
Przepisuje wartosc: 47 dla elementu o w/w indeksie
output[43] = 47
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 44 na 43

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 43
Przepisuje wartosc: 46 dla elementu o w/w indeksie
output[42] = 46
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 43 na 42

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 42
Przepisuje wartosc: 46 dla elementu o w/w indeksie
output[41] = 46
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 42 na 41

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 41
Przepisuje wartosc: 44 dla elementu o w/w indeksie
output[40] = 44
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 41 na 40

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 40
Przepisuje wartosc: 41 dla elementu o w/w indeksie
output[39] = 41
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 40 na 39

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 39
Przepisuje wartosc: 41 dla elementu o w/w indeksie
output[38] = 41
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 39 na 38

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 38
Przepisuje wartosc: 40 dla elementu o w/w indeksie
output[37] = 40
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 38 na 37

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 37
Przepisuje wartosc: 40 dla elementu o w/w indeksie
output[36] = 40
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 37 na 36

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 36
Przepisuje wartosc: 39 dla elementu o w/w indeksie
output[35] = 39
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 36 na 35

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 35
Przepisuje wartosc: 38 dla elementu o w/w indeksie
output[34] = 38
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 35 na 34

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 34
Przepisuje wartosc: 38 dla elementu o w/w indeksie
output[33] = 38
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 34 na 33

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 33
Przepisuje wartosc: 36 dla elementu o w/w indeksie
output[32] = 36
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 33 na 32

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 32
Przepisuje wartosc: 36 dla elementu o w/w indeksie
output[31] = 36
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 32 na 31

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 31
Przepisuje wartosc: 35 dla elementu o w/w indeksie
output[30] = 35
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 31 na 30

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 30
Przepisuje wartosc: 35 dla elementu o w/w indeksie
output[29] = 35
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 30 na 29

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 29
Przepisuje wartosc: 35 dla elementu o w/w indeksie
output[28] = 35
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 29 na 28

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 28
Przepisuje wartosc: 35 dla elementu o w/w indeksie
output[27] = 35
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 28 na 27

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 27
Przepisuje wartosc: 34 dla elementu o w/w indeksie
output[26] = 34
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 27 na 26

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 26
Przepisuje wartosc: 33 dla elementu o w/w indeksie
output[25] = 33
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 26 na 25

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 25
Przepisuje wartosc: 32 dla elementu o w/w indeksie
output[24] = 32
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 25 na 24

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 24
Przepisuje wartosc: 28 dla elementu o w/w indeksie
output[23] = 28
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 24 na 23

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 23
Przepisuje wartosc: 28 dla elementu o w/w indeksie
output[22] = 28
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 23 na 22

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 22
Przepisuje wartosc: 27 dla elementu o w/w indeksie
output[21] = 27
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 22 na 21

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 21
Przepisuje wartosc: 26 dla elementu o w/w indeksie
output[20] = 26
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 21 na 20

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 20
Przepisuje wartosc: 26 dla elementu o w/w indeksie
output[19] = 26
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 20 na 19

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 19
Przepisuje wartosc: 25 dla elementu o w/w indeksie
output[18] = 25
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 19 na 18

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 18
Przepisuje wartosc: 22 dla elementu o w/w indeksie
output[17] = 22
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 18 na 17

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 17
Przepisuje wartosc: 22 dla elementu o w/w indeksie
output[16] = 22
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 17 na 16

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 16
Przepisuje wartosc: 19 dla elementu o w/w indeksie
output[15] = 19
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 16 na 15

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 15
Przepisuje wartosc: 18 dla elementu o w/w indeksie
output[14] = 18
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 15 na 14

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 14
Przepisuje wartosc: 18 dla elementu o w/w indeksie
output[13] = 18
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 14 na 13

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 13
Przepisuje wartosc: 17 dla elementu o w/w indeksie
output[12] = 17
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 13 na 12

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 12
Przepisuje wartosc: 17 dla elementu o w/w indeksie
output[11] = 17
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 12 na 11

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 11
Przepisuje wartosc: 15 dla elementu o w/w indeksie
output[10] = 15
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 11 na 10

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 10
Przepisuje wartosc: 15 dla elementu o w/w indeksie
output[9] = 15
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 10 na 9

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 9
Przepisuje wartosc: 13 dla elementu o w/w indeksie
output[8] = 13
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 9 na 8

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 8
Przepisuje wartosc: 13 dla elementu o w/w indeksie
output[7] = 13
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 8 na 7

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 7
Przepisuje wartosc: 12 dla elementu o w/w indeksie
output[6] = 12
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 7 na 6

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 6
Przepisuje wartosc: 11 dla elementu o w/w indeksie
output[5] = 11
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 6 na 5

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 100
Przepisuje wartosc: 110 dla elementu o w/w indeksie
output[99] = 110
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 100 na 99

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 99
Przepisuje wartosc: 110 dla elementu o w/w indeksie
output[98] = 110
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 99 na 98

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 98
Przepisuje wartosc: 110 dla elementu o w/w indeksie
output[97] = 110
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 98 na 97

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 5
Przepisuje wartosc: 10 dla elementu o w/w indeksie
output[4] = 10
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 5 na 4

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 4
Przepisuje wartosc: 8 dla elementu o w/w indeksie
output[3] = 8
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 4 na 3

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 97
Przepisuje wartosc: 107 dla elementu o w/w indeksie
output[96] = 107
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 97 na 96

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 3
Przepisuje wartosc: 6 dla elementu o w/w indeksie
output[2] = 6
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 3 na 2

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 2
Przepisuje wartosc: 6 dla elementu o w/w indeksie
output[1] = 6
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 2 na 1

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 96
Przepisuje wartosc: 105 dla elementu o w/w indeksie
output[95] = 105
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 96 na 95

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 95
Przepisuje wartosc: 104 dla elementu o w/w indeksie
output[94] = 104
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 95 na 94

Przeszukujemy: 1 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 94
Przepisuje wartosc: 102 dla elementu o w/w indeksie
output[93] = 102
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[1] z 94 na 93

Przeszukujemy: 0 rzad wielkosci
Pod indeksem tego rzedu wielkosci znajduje sie: 1
Przepisuje wartosc: 1 dla elementu o w/w indeksie
output[0] = 1
Na koniec zmniejszam wartosc zliczonego elementu w tablicy count z count[0] z 1 na 0
Wyglad tablicy po posortowaniu 4 rzedu(ow) od konca:
1 6 6 8 10 11 12 13 13 15 15 17 17 18 18 19 22 22 25 26 26 27 28 28 32 33 34 35 35 35 35 36 36 38 38 39 40 40 41 41 44 46 46 47 48 49 50 51 52 53 54 57 59 61 61 61 62 62 64 65 66 68 68 69 69 70 70 72 74 75 75 75 75 76 80 80 80 80 81 84 85 86 87 87 88 90 92 92 93 93 93 94 95 102 104 105 107 110 110 110

Posortowana tablica:
1 6 6 8 10 11 12 13 13 15 15 17 17 18 18 19 22 22 25 26 26 27 28 28 32 33 34 35 35 35 35 36 36 38 38 39 40 40 41 41 44 46 46 47 48 49 50 51 52 53 54 57 59 61 61 61 62 62 64 65 66 68 68 69 69 70 70 72 74 75 75 75 75 76 80 80 80 80 81 84 85 86 87 87 88 90 92 92 93 93 93 94 95 102 104 105 107 110 110 110

*/
