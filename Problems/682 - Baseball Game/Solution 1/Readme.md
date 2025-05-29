Masalah ini dapat diselesaikan dengan menggunakan stack untuk menyimpan hasil
dari setiap operasi pada array operations. Setelah semua operasi dijalankan,
kita cukup menjumlahkan seluruh elemen dalam stack untuk mendapatkan total skor.

Langkah-langkah penyelesaian

- Buat stack record untuk menyimpan skor hasil operasi.

```c++
stack<int> record;
```

- Lakukan loop untuk setiap elemen pada vector operations.

```c++
for (const string& operation : operations) {
    // proses setiap operasi
}
```

- Buat kondisi untuk setiap jenis operasi:

  - Jika operation == "+", Ambil dua skor terakhir, jumlahkan, dan masukkan
    hasilnya ke stack.

    ```c++
    int top = record.top();
    record.pop();
    int newTop = top + record.top();
    record.push(top);
    record.push(newTop);
    ```

  - Jika operation == "C", Hapus skor terakhir dari stack.

    ```c++
    record.pop();
    ```

  - Jika operation == "D", Gandakan skor terakhir dan masukkan ke stack.

    ```c++
    record.push(2 * record.top());
    ```

  - Jika berupa angka, Ubah string menjadi integer dan masukkan ke stack.

    ```c++
    record.push(stoi(operation));
    ```

- Setelah semua operasi selesai, jumlahkan seluruh elemen stack untuk
  mendapatkan total skor.

```c++
int ans = 0;
while (!record.empty()) {
    ans += record.top();
    record.pop();
}
return ans;
```

### Reference:

[Stack](https://www.w3schools.com/cpp/cpp_stacks.asp)
