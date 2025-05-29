## 2: Two-pass Hash Table

Two-pass Hash Table adalah metode yang menggunakan dua kali perulangan (pass).
Pada pass pertama, semua elemen dan indeksnya disimpan ke dalam hash table. Pada
pass kedua, untuk setiap elemen, kita mencari apakah angka pelengkap
(`target - nums[i]`) ada di hash table dan bukan indeks yang sama. Jika
ditemukan, kita kembalikan pasangan indeks tersebut.

Dengan cara ini, pencarian pasangan angka bisa dilakukan dalam waktu rata-rata
O(1) per pencarian, sehingga total kompleksitas waktunya menjadi O(n).

- Buat hash table untuk menyimpan key dan value bertipe integer.

```c++
unordered_map<int, int> hash;
```

- Buat for loop untuk perulangan dari indeks 0 hingga akhir array nums. Lalu
  pada setiap perulangan ambil elemen nums[i] sebagai key di hash dan simpan
  indeks i sebagai value-nya.

```c++
unordered_map<int, int> hash;

for (int i = 0; i < nums.size(); i++) {
    hash[nums[i]] = i;
}
```

- Buat for loop untuk perulangan dari indeks 0 hingga akhir array nums. Pada
  setiap perulangan buat perhitungan angka pelengkap yang jika ditambah nums[i]
  akan menghasilkan target.

```c++
unordered_map<int, int> hash;

for (int i = 0; i < nums.size(); i++) {
    hash[nums[i]] = i;

for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];
}
```

- Masih di loop yang sama, buat kondisi untuk mengecek apakah complement ada di
  hash table, lalu return array {i, hash[complement]}. hash.find(complement) !=
  hash.end() artinya key ditemukan. hash[complement] != i memastikan indeksnya
  beda (tidak menggunakan angka yang sama dua kali).

```c++
unordered_map<int, int> hash;

for (int i = 0; i < nums.size(); i++) {
    hash[nums[i]] = i;

for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];
    if (hash.find(complement) != hash.end() && hash[complement] != i) {
        return {i, hash[complement]};
    }
}
```

- Kembalikan array kosong jika target tidak ditemukan dalam loop.

```c++
unordered_map<int, int> hash;

for (int i = 0; i < nums.size(); i++) {
    hash[nums[i]] = i;

for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];
    if (hash.find(complement) != hash.end() && hash[complement] != i) {
        return {i, hash[complement]};
    }
}
return 0;
```
