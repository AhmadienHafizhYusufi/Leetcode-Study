## 1: Brute Force

### Intuisi

Kita melakukan loop setiap elemen `x` dalam array, lalu mencari apakah ada
elemen lain yang nilainya sama dengan `target - x`. Jika ditemukan, maka kedua
indeks tersebut adalah solusi yang dicari. Cara ini memeriksa semua kemungkinan
pasangan, sehingga kompleksitas waktunya adalah $O(n^2)$.

- Buat loop for untuk mengakses setiap elemen dalam indeks array.

```c++
for (int i = 0; i < nums.size(); i++) {}
```

- Buat nested loop for untuk mengakses elemen dari indek selanjutnya.

```c++
for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {}
}
```

- Buat kondisi if dengan `nums[j] = target - nums[i]`, lalu return {i, j}.
  Maksudnya agar mengecek apakah elemen lain nilainya sama dengan target -
  elemen utama. return {i, j}; mengembalikan indeks dari dua angka yang jika
  dijumlahkan sama dengan target.

```c++
for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
        if (nums[j] == target - nums[i]) {
            return {i, j};
        }
    }
}
```

- Kembalikan array kosong jika target tidak ditemukan dalam loop.

```c++
for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
        if (nums[j] == target - nums[i]) {
            return {i, j};
        }
    }
}
return {};
```
